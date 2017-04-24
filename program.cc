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
  pob.leer();
  
  string s;
  while (cin >> s and s != "acabar") {
    if (s == "anadir_individuo") {
      // AÑADIR INDIVIDUO
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
      // ESCRIBIR POBLACION
    }
    else if (s == "escribir_genotipo"){
      // ESCRIBIR GENOTIPO
    }
  }
  
}
