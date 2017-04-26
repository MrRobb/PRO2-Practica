/**
 * @mainpage Práctica de PRO2:  Experimentos genéticos de laboratorio.
 */

/** @file pro2.cc
    @brief Programa principal para la práctica de PRO2: <em>Experimentos genéticos de laboratorio</em>.
*/

#include <iostream>
#include <queue>
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
      Individuo(ind);
      ind.leer(esp);
      cout << "anadir_individuo " << ind.consultar_nombre() << endl;
      pob.anadir_individuo(ind);
    }

    // Reproducir individuos
    else if (s == "reproduccion_sexual"){
      int N = esp.consultar_pares_cromosomas();
      vector<vector<int> > mat_rep (N+1, vector<int> (3));
      string madre, padre, hijo;
      cin >> madre >> padre >> hijo;
      for(int i = 0; i < N+1; ++i){
        for(int j = 0; j < 3; ++j) cin >> mat_rep[i][j];
      }
      cout << "reproduccion_sexual " << madre << ' ' << padre << ' ' << hijo << endl;
      pob.reproducir(madre, padre, hijo, mat_rep, esp);
    }

    // Escribir arbol de un individuo
    else if (s == "escribir_arbol_genealogico"){
      string ind; cin >> ind;
      cout << "escribir_arbol_genealogico " << ind << endl;
      pob.escribir_arbol(ind);
    }

    // Completar arbol genealogico
    else if (s == "completar_arbol_genealogico"){
      queue<string> q;
      string ind;
      while(cin >> ind) q.push(ind);

      cout << "completar_arbol_genealogico " << q.front() << endl;
      pob.completar_arbol_genealogico(q);
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

}
