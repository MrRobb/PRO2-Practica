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
    if (s == "anadir_individuo") {
      Individuo(ind);
      ind.leer(esp);
      cout << "anadir_individuo " << ind.consultar_nombre() << endl;
      pob.anadir_individuo(ind);
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
      cout << "escribir_poblacion" << endl;
      pob.escribir();
    }
    else if (s == "escribir_genotipo"){
      string s; cin >> s;
      cout << "escribir_genotipo " << s << endl;
      pob.escribir_genotipo(s);
    }
  }
  
}
