//
//  Especie.cc
//  PRO2
//
//  Created by Roberto Ariosa Hernández.
//

#include "Especie.hh"
#include <iostream>

Especie::Especie(){
  N = 0;
  lx = 0;
  ly = 0;
  v_li = vector<int> (0);
}

int Especie::consultar_pares_cromosomas() const {
  return N;
}

int Especie::consultar_longitud_cromosoma_normal(int i) const {
  return v_li[i];
}

int Especie::consultar_longitud_cromosoma_x() const {
  return lx;
}

int Especie::consultar_longitud_cromosoma_y() const {
  return ly;
}

void Especie::leer() {
  cin >> N;
  v_li = vector<int> (N+1);
  for(int i = 0; i <= N; ++i) cin >> v_li[i];
  cin >> lx >> ly;
}
