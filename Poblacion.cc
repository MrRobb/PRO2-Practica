//
//  Poblacion.cc
//  PRO2
//
//  Created by Roberto Ariosa Hernández.
//

#include "Poblacion.hh"
#include <iostream>

Poblacion::Poblacion(){
}

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

void Poblacion::i_escribir_padres(queue<string> &q_individuos, string ind){
  string madre = pob[ind].consultar_madre();
  string padre = pob[ind].consultar_padre();
  
  if(madre == "" and padre == ""){
    q_individuos.push("$");
    q_individuos.push("$");
  } else {
    q_individuos.push(padre);
    i_escribir_padres(q_individuos, padre);
    q_individuos.push(madre);
    i_escribir_padres(q_individuos, madre);
  }
}

void Poblacion::anadir_individuo(string nombre, const Especie &esp){
  // Ver si esta repetido
  map<string,Individuo>::iterator i = pob.find(nombre);

  // Leer individuo y añadir
  if (i == pob.end()) {
    Individuo(ind);
    ind.leer(esp);
    pob[nombre] = ind;
  }
  
  // Error
  else {
    cout << "  error" << endl;
  }
}

bool Poblacion::son_hermanos(string ind1, string ind2) {
  return !(( not pob[ind1].tiene_ascendientes() or  not pob[ind2].tiene_ascendientes() or pob[ind1].consultar_padre() != pob[ind2].consultar_padre()) and (not pob[ind1].tiene_ascendientes() or not pob[ind2].tiene_ascendientes() or pob[ind1].consultar_madre() != pob[ind2].consultar_madre()));
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
          if(not son_hermanos(madre, padre)){
          
            if(!pob[madre].tiene_ascendientes() or !pob[padre].tiene_ascendientes() or pob[madre].consultar_madre() != pob[padre].consultar_madre()){
              if(!pob[madre].tiene_ascendientes() or !pob[padre].tiene_ascendientes() or pob[madre].consultar_padre() != pob[padre].consultar_padre()){
              
              // Mirar si son antecesores
                if(!es_antecesor(madre, padre)) {
                  if(!es_antecesor(padre, madre)){
                  
                  // Reproducir
                    pob[hijo] = Individuo(madre, padre, pob[madre], pob[padre], esp);
                    b = 2;
                  }
                }
              }
            }
          }
        }
      } else b = 1;
    } else b = 1;
  } else b = 1;
  
  // ERRORES:
  if(b == 0){
    cout << "  no es posible reproduccion" << endl;
    
  }
  else if(b == 1){
    cout << "  error" << endl;
  }
}

void Poblacion::completar_arbol_genealogico(string ind){
  map<string,Individuo>::const_iterator it = pob.find(ind);
  int finish_entrada = 1; // Contiene la diferencia entre hojas y nodos del pseudoarbol
  
  if(it != pob.end()){
    
    queue<string> q_individuos;
    string madre;
    string padre;
    
    q_individuos.push(ind);
    i_escribir_padres(q_individuos, ind); // q_individuos contiene el pseudoarbol de individuos
    
    // Comparar colas
    queue<string> q_final;
    bool correcto = true;
    while(correcto and finish_entrada != 0 and not q_individuos.empty()){
      
      // Si coinciden
      if(ind != "$" and ind == q_individuos.front()){
        ++finish_entrada;
        q_final.push(ind);
        q_individuos.pop();
      }
      
      // Si no coinciden pero es desconocido
      else if (ind == "$"){
        --finish_entrada;
        
        // Insertar el pseudoarbol del individuo q_individuos.front() en la cola final
        // Sabiendo que el numero de hojas es n+1
        
        int finish_arbol = 1;
        while(finish_arbol != 0){
          if(q_individuos.front() == "$"){
            --finish_arbol;
            q_final.push("$");
          }
          else {
            ++finish_arbol;
            q_final.push("*" + q_individuos.front() + "*");
          }
          q_individuos.pop();
        }
      }
      
      // Si no coinciden y son diferentes
      else correcto = false;
      
      // Siguiente elemento
      if(finish_entrada != 0 and not q_individuos.empty()) cin >> ind;
    }
    
    // PRINT si es correcto
    if(correcto){
      // PRINT
      bool first = true;
      cout << "  ";
      while(not q_final.empty()){
        if(first){
          cout << q_final.front();
          first = false;
        }
        else cout << ' ' << q_final.front();
        q_final.pop();
      }
      cout << endl;
    }
  }
  
  if(finish_entrada > 0){
    cout << "  no es arbol parcial" << endl;
  }
}

void Poblacion::leer(const Especie &esp){
  int M; cin >> M;
  for(int i = 0; i < M; ++i){
    string nombre; cin >> nombre;
    Individuo (ind);
    ind.leer(esp);
    pob[nombre] = ind;
  }
}

void Poblacion::escribir() const {
  for(std::map<string, Individuo>::const_iterator it = pob.begin(); it != pob.end(); ++it){
    cout << "  " << (*it).first << ' ';
    (*it).second.escribir();
  }
}

void Poblacion::escribir_genotipo(string nombre) const {
  map<string, Individuo>::const_iterator it = pob.find(nombre);
  if(it != pob.end()) (*it).second.escribir_genotipo();
  else cout << "  error" << endl;
}

void Poblacion::escribir_por_niveles(string ind) {
  map<string,Individuo>::const_iterator it = pob.find(ind);
  if(it != pob.end()){
    
    // Inicializar
    queue<string> q_individuos;
    queue<int> q_niveles;
    string madre;
    string padre;
    int nivel_anterior = -1;
    
    // Push inicial
    q_individuos.push(ind);
    q_niveles.push(0);
    
    // BFS
    while (!q_individuos.empty()) {
      // Progenitores
      madre = pob[q_individuos.front()].consultar_madre();
      padre = pob[q_individuos.front()].consultar_padre();
      
      
      // Print
      if(q_niveles.front() != nivel_anterior){
        if(nivel_anterior != -1) cout << endl;
        cout << "  Nivel " << q_niveles.front() << ":";
        nivel_anterior = q_niveles.front();
      }
      
      cout << " " << q_individuos.front();
      
      // Añadir a la cola progenitores
      if(madre != "" and padre != ""){
        q_individuos.push(padre);
        q_individuos.push(madre);
        q_niveles.push(q_niveles.front()+1);
        q_niveles.push(q_niveles.front()+1);
      }
      
      // Pop
      q_niveles.pop();
      q_individuos.pop();
    }
    
    cout << endl;
    
  } else {
    cout << "  error" << endl;
  }
}
