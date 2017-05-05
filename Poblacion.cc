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
    q_individuos.push(madre);
    i_escribir_padres(q_individuos, madre);
    q_individuos.push(padre);
    i_escribir_padres(q_individuos, padre);
  }
}

void Poblacion::anadir_individuo(string nombre, const Individuo &ind){
  map<string,Individuo>::iterator i = pob.find(nombre);
  if (i == pob.end()) {
    pob[nombre] = ind;
  } else {
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
                    pob[hijo] = Individuo(hijo, madre, padre, pob[madre], pob[padre], esp);
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
  
  // Leer entrada si hay error
  if(b <= 1){
    int N = esp.consultar_pares_cromosomas();
    // Puedo usar b en el for ya que ya he entrado en el if y ya no me sirve para nada
    for(int i = 0; i < 3*(N+1); ++i) {
      cin >> b;
    }
  }
}

bool Poblacion::completar_arbol_genealogico(queue<string> &q_entrada){
  string ind = q_entrada.front();
  map<string,Individuo>::const_iterator it = pob.find(ind);
  
  if(it != pob.end()){
    
    queue<string> q_individuos;
    string madre;
    string padre;
    
    q_individuos.push(ind);
    i_escribir_padres(q_individuos, ind);
    
    // Comparar colas
    // q_individuos vs q_entrada
    
    queue<string> q_final;
    
    while(not q_entrada.empty() and q_individuos.empty()){
      if(q_entrada.front() == q_individuos.front()){
        q_final.push(q_entrada.front());
        q_entrada.pop();
        q_individuos.pop();
      }
      else if(q_entrada.front() != "$") {
        return false;
      }
      else {
        // Encontrar siguiente elemento no desconocido
        while(not q_entrada.empty() and q_entrada.front() == "$"){
          q_entrada.pop();
        }
        
        // Si toda la lista restante es desconocida
        if(q_entrada.empty()){
          while(not q_individuos.empty()){
            q_final.push("*"+q_individuos.front()+"*");
            q_individuos.pop();
          }
        }
        
        // Si hay un elemento conocido
        else {
          while(not q_individuos.empty() and q_individuos.front() != q_entrada.front()){
            q_final.push("*"+q_individuos.front()+"*");
            q_individuos.pop();
          }
        }
      }
    }
    
    // PRINT
    bool first = true;
    while(not q_final.empty()){
      if(first){
        cout << q_final.front();
        first = false;
      }
      else cout << ' ' << q_final.front();
      q_final.pop();
    }
    cout << endl;
  
    return true;
    
  } else return false;
}

void Poblacion::leer(const Especie &esp){
  int M; cin >> M;
  for(int i = 0; i < M; ++i){
    string nombre;
    cin >> nombre;
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
    queue<string> q_recorridos;
    queue<string> q_individuos;
    queue<int> q_niveles;
    string madre;
    string padre;
    
    // Push inicial
    q_recorridos.push(ind);
    q_individuos.push(ind);
    q_niveles.push(0);
    
    // BFS
    while (!q_recorridos.empty()) {
      madre = pob[q_recorridos.front()].consultar_madre();
      padre = pob[q_recorridos.front()].consultar_padre();
      
      if(madre != "" and padre != ""){
        q_recorridos.push(madre);
        q_recorridos.push(padre);
        q_individuos.push(madre);
        q_individuos.push(padre);
        q_niveles.push(q_niveles.front()+1);
        q_niveles.push(q_niveles.front()+1);
      }
      q_recorridos.pop();
    }
    
    // Print
    int nivel = -1;
    while (!q_individuos.empty()) {
      if(nivel != q_niveles.front()){
        nivel = q_niveles.front();
        if(nivel != 0) cout << endl;
        cout << "Nivel " << nivel << ":";
      }
      cout << " " << q_individuos.front();
      q_niveles.pop();
      q_individuos.pop();
    }
    
  } else {
    cout << "  error" << endl;
  }
}
