//
//  Individuo.cc
//  PRO2
//
//  Created by Roberto Ariosa Hernández.
//

#include "Individuo.hh"

Individuo::Individuo(){
  nombre = "";
  padre = "";
  madre = "";
  adn = vector< pair<Cromosoma, Cromosoma> > (0);
}

Individuo::~Individuo(){}

string Individuo::consultar_nombre() const {
  return nombre;
}

void Individuo::leer(const Especie &esp){
  cin >> nombre;
  string sexo; cin >> sexo;
  es_masculino = (sexo == "Y");
  
  int N = esp.consultar_pares_cromosomas();
  adn = vector< pair<Cromosoma, Cromosoma> > (N+1);
  // Leer sexuales
  int lx = esp.consultar_longitud_cromosoma_x();
  int ly = esp.consultar_longitud_cromosoma_y();
  adn[0].first.leer(lx);
  if(es_masculino) adn[0].second.leer(ly);
  else adn[0].second.leer(lx);
  
  
  // Leer normales
  for(int i = 1; i <= N; ++i){
    int li = esp.consultar_longitud_cromosoma_normal(i);
    adn[i].first.leer(li);
    adn[i].second.leer(li);
  }
}
