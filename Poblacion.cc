//
//  Poblacion.cc
//  PRO2
//
//  Created by Roberto Ariosa Hernández.
//

#include "Poblacion.hh"

Poblacion::Poblacion(){
}

Poblacion::~Poblacion(){}

void Poblacion::anadir_individuo(const Individuo &ind){
  map<string,Individuo>::iterator i = pob.find(ind.consultar_nombre());
  if (i == pob.end()) {
    pob[ind.consultar_nombre()] = ind;
  } else {
    cout << "  error" << endl;
  }
}

void Poblacion::leer(const Especie &esp){
  int M; cin >> M;
  for(int i = 0; i < M; ++i){
    Individuo (ind);
    ind.leer(esp);
    pob[ind.consultar_nombre()] = ind;
  }
}

void Poblacion::escribir() const {
  for(std::map<string, Individuo>::const_iterator it = pob.begin(); it != pob.end(); ++it){
    (*it).second.escribir();
  }
}

void Poblacion::escribir_genotipo(string nombre) const {
  map<string, Individuo>::const_iterator it = pob.find(nombre);
  if(it != pob.end()) (*it).second.escribir_genotipo();
  else cout << "  error" << endl;
  
}
