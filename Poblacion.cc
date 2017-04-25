//
//  Poblacion.cc
//  PRO2
//
//  Created by Roberto Ariosa Hernández.
//

#include "Poblacion.hh"
#include <queue>

Poblacion::Poblacion(){
}

Poblacion::~Poblacion(){}

bool Poblacion::es_antecesor(string hijo, const string &antecesor){
  
  if(!pob[hijo].tiene_ascendientes()){
    return false;
  } else {
    string madre = pob[hijo].consultar_madre();
    string padre = pob[hijo].consultar_padre();
    
    if(madre == antecesor or padre == antecesor){
      return true;
    } else {
      bool antecesor_padres = es_antecesor(madre, antecesor);
      if(!antecesor_padres) antecesor_padres = es_antecesor(padre, antecesor);
      return antecesor_padres;
    }
  }
}

void Poblacion::anadir_individuo(const Individuo &ind){
  map<string,Individuo>::iterator i = pob.find(ind.consultar_nombre());
  if (i == pob.end()) {
    pob[ind.consultar_nombre()] = ind;
  } else {
    cout << "  error" << endl;
  }
}

void Poblacion::reproducir(string madre, string padre, string hijo, const Especie &esp){
  // Crear iteradores
  map<string, Individuo>::iterator it_madre;
  map<string, Individuo>::iterator it_padre;
  map<string, Individuo>::const_iterator it_hijo;
  int b = 0;
  
  // Buscar madre
  it_madre = pob.find(madre);
  if(it_madre != pob.end()){
    
    // Buscar padre
    it_padre = pob.find(padre);
    if(it_padre != pob.end()){
      
      // Buscar hijo
      it_hijo  = pob.find(hijo);
      if(it_hijo == pob.end()){
        
        // Madre == XX y Padre == XY
        if(!pob[madre].consultar_es_masculino() and pob[padre].consultar_es_masculino()){
          
          // Mirar si son hermanos
          if(!pob[madre].tiene_ascendientes() or !pob[padre].tiene_ascendientes() or pob[madre].consultar_madre() != pob[padre].consultar_madre()){
            if(!pob[madre].tiene_ascendientes() or !pob[padre].tiene_ascendientes() or pob[madre].consultar_padre() != pob[padre].consultar_padre()){
              
              // Mirar si son antecesores
              if(!es_antecesor(madre, padre)) {
                if(!es_antecesor(padre, madre)){
                  
                  // Reproducir
                  pob[hijo] = Individuo(hijo, pob[madre], pob[padre], esp);
                  b = 2;
                }
              }
            }
          }
        }
      } else b = 1;
    } else b = 1;
  } else b = 1;
  
  // ERRORES:
  if(b == 0) cout << "  no es posible reproduccion" << endl;
  else if(b == 1) cout << "  error" << endl;
}

void Poblacion::leer(const Especie &esp){
  int M; cin >> M;
  for(int i = 0; i < M; ++i){
    Individuo (ind);
    ind.leer(esp);
    pob[ind.consultar_nombre()] = ind;
  }
}

void Poblacion::escribir() const {
  for(std::map<string, Individuo>::const_iterator it = pob.begin(); it != pob.end(); ++it){
    (*it).second.escribir();
  }
}

void Poblacion::escribir_genotipo(string nombre) const {
  map<string, Individuo>::const_iterator it = pob.find(nombre);
  if(it != pob.end()) (*it).second.escribir_genotipo();
  else cout << "  error" << endl;
}

void Poblacion::escribir_arbol(string ind) {
  map<string,Individuo>::const_iterator it = pob.find(ind);
  if(it != pob.end()){
    
    // TEMP
    
    
    
  } else {
    cout << "  error" << endl;
  }
}
/*
 PRE: el string ind debe ser un individuo de la poblacion, en caso contrario dara error.
 POST: Escribe el arbol del individuo por niveles. Dentro del mismo nivel, el padre y la madre asociados (es decir, que hayan formado pareja reproductora) apareceran consecutivos, primero el padre y despues la madre.
 */
