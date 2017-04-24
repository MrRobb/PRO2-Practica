//
//  Cromosoma.cc
//  PRO2
//
//  Created by Roberto Ariosa Hernández.
//

#include "Cromosoma.hh"
#include <iostream>

Cromosoma::Cromosoma(){}

Cromosoma::~Cromosoma(){}

void Cromosoma::leer(int li) {
  c = vector<int> (li);
  for (int i = 0; i < li; ++i) cin >> c[i];
}
