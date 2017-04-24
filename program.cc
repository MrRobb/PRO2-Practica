//
//  program.cc
//  PRO2
//
//  Created by Roberto Ariosa Hernandez.
//

#include <iostream>
#include "Cromosoma.hh"
#include "Individuo.hh"
#include "Poblacion.hh"
#include "Especie.hh"

int main() {
  Especie(esp);
  esp.leer();
  
  Poblacion(pob);
  pob.leer(esp);
  
  string s;
  while (cin >> s and s != "acabar") {
    bool b;
    if (s == "anadir_individuo") {
      Individuo(ind);
      ind.leer(esp);
      pob.anadir_individuo(ind, b);
      if(b) cout << "error" << endl;
      else  cout << "added" << endl;
    }
    else if (s == "reproduccion_sexual"){
      // REPRODUCIR
    }
    else if (s == "escribir_arbol_genealogico"){
      // ESCRIBIR ARBOL
    }
    else if (s == "completar_arbol_genealogico"){
      // COMPLETAR ARBOL
    }
    else if (s == "escribir_poblacion"){
      pob.escribir();
    }
    else if (s == "escribir_genotipo"){
      // ESCRIBIR GENOTIPO
    }
  }
  
}
