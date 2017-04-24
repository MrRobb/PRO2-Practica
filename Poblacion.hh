//
//  Poblacion.hh
//  PRO2
//
//  Created by Roberto Ariosa Hernandez.
//

#ifndef Poblacion_hh
#define Poblacion_hh

#include "Especie.hh"
#include "Individuo.hh"
#include <iostream>
#include <map>

class Poblacion {
  
  // Tipo de modulo: datos
  /*
   Descripcion del tipo: almacena los datos de una poblacion concreta
   de individuos donde estos estan ordenados alfabeticamente y tienen
   una relacion de parentesco.
   */
  
private:
  
  map<string, Individuo> pob;
  
  
public:
  
  // Constructores
  
  Poblacion();
  
  // Destructora
  
  ~Poblacion();
  
  // Modificadores
  
  void anadir_individuo(const Individuo &ind);
  
  // Consultores
  
    // TEMP = "void"
    // TEMP = "()"
  void arbol_incompleto() const;
  
  // Lectura y escritura
  
  void leer();
  /*
   PRE: Se leen los datos en el siguiente orden:
   1. un entero positivo M >= 1 individuos sin ascendientes.
   2. Se leen M individuos segun su especificacion.
   
   POST: Se añaden los individuos a la poblacion.
   */
  
  void escribir();
  
  void escribir_arbol(string ind);
  
};

#endif /* Poblacion_hh */
