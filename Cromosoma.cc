//
//  Cromosoma.cc
//  PRO2
//
//  Created by Roberto Ariosa Hernández.
//

#include "Cromosoma.hh"
#include <iostream>

Cromosoma::Cromosoma(){}

Cromosoma::Cromosoma(int li){
  c = vector<int> (li);
}

Cromosoma Cromosoma::cruzamiento_sexuales (const Cromosoma &secundario, int k, int li) const{
  int lim = int((*this).c.size());
  Cromosoma cnuevo (lim);
  
  for(int i = 0; i < k; ++i) cnuevo.c[i] = (*this).c[i];
  for(int i = k; i < li; ++i) cnuevo.c[i] = secundario.c[i];
  for(int i = li; i < lim; ++i) cnuevo.c[i] = (*this).c[i];
  
  return cnuevo;
}

Cromosoma Cromosoma::cruzamiento_normales (const Cromosoma &secundario, int k) const {
  int li = int(c.size());
  Cromosoma cnuevo (li);
  
  for(int i = 0; i < k; ++i) cnuevo.c[i] = (*this).c[i];
  for(int i = k; i < li; ++i) cnuevo.c[i] = secundario.c[i];
  
  return cnuevo;
}

void Cromosoma::leer(int li) {
  c = vector<int> (li);
  for (int i = 0; i < li; ++i) cin >> c[i];
}

void Cromosoma::escribir() const {
  int size = int(c.size());
  for (int i = 0; i < size; ++i) cout << ' ' << c[i];
}
