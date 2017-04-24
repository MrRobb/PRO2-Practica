//
//  Poblacion.cc
//  PRO2
//
//  Created by Roberto Ariosa Hernández.
//

#include "Poblacion.hh"

Poblacion::Poblacion(){
  pob = map<string,Individuo> ();
}

Poblacion::~Poblacion(){}

void Poblacion::anadir_individuo(const Individuo &ind, bool &b){
  map<string,Individuo>::iterator i = pob.find(ind.consultar_nombre());
  if (i != pob.end() or (*i).second.consultar_nombre() == (*pob.end()).second.consultar_nombre()) {
    b = true;
  } else {
    b = false;
    pob[ind.consultar_nombre()] = ind;
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
