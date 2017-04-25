//
//  Individuo.cc
//  PRO2
//
//  Created by Roberto Ariosa Hernández.
//

#include "Individuo.hh"

Individuo::Individuo(){
  padre = "";
  madre = "";
  adn = vector< vector<Cromosoma> > (0, vector<Cromosoma>(2));
}

Individuo::Individuo(string nombre, const Individuo &madre, const Individuo &padre, const Especie &esp){
  int N = esp.consultar_pares_cromosomas();
  (*this).adn = vector< vector<Cromosoma> > (N+1, vector<Cromosoma>(2));
  
  for(int i = 0; i <= N; ++i){
    int c1, c2, k;
    cin >> c1 >> c2 >> k;
    if(i != 0){
      (*this).adn[i][0] = madre.adn[i][c1].cruzamiento_normales(padre.adn[i][c2], k);
      (*this).adn[i][1] = padre.adn[i][c2].cruzamiento_normales(madre.adn[i][c1], k);
    } else {
      (*this).es_masculino = (c2 == 1);
      (*this).adn[i][0] = madre.adn[i][c1].cruzamiento_sexuales(padre.adn[i][c2], k, esp.consultar_longitud_cromosoma_normal(i));
      (*this).adn[i][1] = padre.adn[i][c2].cruzamiento_sexuales(madre.adn[i][c1], k, esp.consultar_longitud_cromosoma_normal(i));
    }
  }
  (*this).padre = padre.nombre;
  (*this).madre = madre.nombre;
  (*this).nombre = nombre;
}

Individuo::~Individuo(){}

bool Individuo::tiene_ascendientes() const {
  return !(madre == "" or padre == "");
}

bool Individuo::consultar_es_masculino() const {
  return es_masculino;
}

string Individuo::consultar_nombre() const {
  return nombre;
}

string Individuo::consultar_madre() const {
  return madre;
}

string Individuo::consultar_padre() const {
  return padre;
}

void Individuo::leer(const Especie &esp){
  cin >> nombre;
  string sexo; cin >> sexo;
  es_masculino = (sexo == "Y");
  
  int N = esp.consultar_pares_cromosomas();
  adn = vector< vector<Cromosoma> > (N+1, vector<Cromosoma> (2));
  // Leer sexuales
  int lx = esp.consultar_longitud_cromosoma_x();
  int ly = esp.consultar_longitud_cromosoma_y();
  adn[0][0].leer(lx);
  if(es_masculino) adn[0][1].leer(ly);
  else adn[0][1].leer(lx);
  
  
  // Leer normales
  for(int i = 1; i <= N; ++i){
    int li = esp.consultar_longitud_cromosoma_normal(i);
    adn[i][0].leer(li);
    adn[i][1].leer(li);
  }
}

void Individuo::escribir() const {
  // Nombre
  cout << "  " << nombre << ' ';
  
  // Sexo
  if(es_masculino) cout << "XY ";
  else cout << "XX ";
  
  // Padres
  if(padre == "" and madre == ""){
    cout << "($,$)" << endl;
  }
  else {
    cout << "(" << padre << "," << madre << ")" << endl;
  }
}

void Individuo::escribir_genotipo() const {
  // Sexuales
  cout << "X:"; adn[0][0].escribir(); cout << endl;;
  
  if(es_masculino) {
    cout << "Y:"; adn[0][1].escribir(); cout << endl;
  }
  else {
    cout << "X:"; adn[0][1].escribir(); cout << endl;
  }
  
  // Normales
  int size = int(adn.size());
  for(int i = 1; i < size; ++i){
    for(int j = 1; j <= 2; ++j){
      cout << i << '.' << j << ':';
      if(j == 1) adn[i][0].escribir();
      else adn[i][1].escribir();
      cout << endl;
    }
  }
}
