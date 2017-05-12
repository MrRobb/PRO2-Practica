/**
 * @mainpage Práctica de PRO2:  Experimentos genéticos de laboratorio.
 * 
 * En esta práctica se construye un programa modular que ofrece un menú de opciones para gestionar la creación y reproducción de individuos de una especie concreta y la evolución de su estructura genética. Se introducen las clases: <em>Cromosoma</em>, <em>Individuo</em>, <em>Poblacion</em> y <em>Especie</em>.
 * 
 * Sólo se documentan elementos públicos de los .hh y el programa principal. En una próxima versión se documentarán los demás elementos.
 */

/** @file pro2.cc
    @brief Programa principal para la práctica de PRO2: <em>Experimentos genéticos de laboratorio</em>.
*/

#ifndef NO_DIAGRAM      // ver explicacion en Cromosoma.hh
#include <iostream>
#include <queue>
#include <vector>
#endif 

#include "Cromosoma.hh"
#include "Individuo.hh"
#include "Poblacion.hh"
#include "Especie.hh"

/** @brief Programa principal para el ejercicio <em>Experimentos genéticos de laboratorio</em>.
*/

using namespace std;

int main() {
  // Inicialitzar
  Especie(esp);
  esp.leer();

  Poblacion(pob);
  pob.leer(esp);

  string s;
  while (cin >> s and s != "acabar") {
    // Añadir individuo
    if (s == "anadir_individuo") {
      string nombre; cin >> nombre;
      Individuo(ind);
      ind.leer(esp);
      cout << "anadir_individuo " << nombre << endl;
      pob.anadir_individuo(nombre, ind);
    }

    // Reproducir individuos
    else if (s == "reproduccion_sexual"){
      string madre, padre, hijo;
      cin >> madre >> padre >> hijo;
      cout << "reproduccion_sexual " << madre << ' ' << padre << ' ' << hijo << endl;
      pob.reproducir(madre, padre, hijo, esp);
    }

    // Escribir arbol de un individuo
    else if (s == "escribir_arbol_genealogico"){
      string ind; cin >> ind;
      cout << "escribir_arbol_genealogico " << ind << endl;
      pob.escribir_por_niveles(ind);
    }

    // Completar arbol genealogico
    else if (s == "completar_arbol_genealogico"){
      string ind; cin >> ind;

      cout << "completar_arbol_genealogico " << ind << endl;
      int b = pob.completar_arbol_genealogico(ind);
      
      // Error
      if(b > 0) {
        cout << "  no es arbol parcial" << endl;

        // Desechar entrada (finish_arbol = 2 porque el individuo ya leido siempre sera un nombre diferente de $
        int finish_arbol = b+1;
        while(finish_arbol > 0){
          cin >> ind;
          if(ind == "$") --finish_arbol;
          else ++finish_arbol;
        }
      }
    }

    // Escribir poblacion
    else if (s == "escribir_poblacion"){
      cout << "escribir_poblacion" << endl;
      pob.escribir();
    }

    // Escribir genotipo
    else if (s == "escribir_genotipo"){
      string s; cin >> s;
      cout << "escribir_genotipo " << s << endl;
      pob.escribir_genotipo(s);
    }

    // Fin
    else {
      return 0;
    }
  }
  cout << "acabar" << endl;

}
