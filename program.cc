//
//  program.cc
//  PRO2
//
//  Created by Roberto Ariosa Hernandez.
//

#include <iostream>
#include <queue>
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
      string madre, padre, hijo;
      cin >> madre >> padre >> hijo;
      cout << "reproduccion_sexual " << madre << ' ' << padre << ' ' << hijo << endl;
      pob.reproducir(madre, padre, hijo, esp);
    }
    else if (s == "escribir_arbol_genealogico"){
      string ind; cin >> ind;
      cout << "escribir_arbol_genealogico " << ind << endl;
      pob.escribir_arbol(ind);
    }
    else if (s == "completar_arbol_genealogico"){
      queue<string> q;
      string ind;
      while(cin >> ind) q.push(ind);
      
      cout << "completar_arbol_genealogico " << q.front() << endl;
      pob.completar_arbol_genealogico(q);
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
