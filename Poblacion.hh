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
  /*
   PRE: cierto.
   POST: Se crea una poblacion de 0 individuos.
   */
  
  // Destructora
  
  ~Poblacion();
  
  // Modificadores
  
  void anadir_individuo(const Individuo &ind);
  /*
   PRE: ind es un individuo valido.
   
   POST: Si no se ha añadido correctamente saldra un mensaje de error.
   */
  
  // Consultores
  
    // TEMP = "void"
    // TEMP = "()"
  void arbol_incompleto() const;
  
  // Lectura y escritura
  
  void leer(const Especie &esp);
  /*
   PRE: Se leen los datos en el siguiente orden:
   1. un entero positivo M >= 1 individuos sin ascendientes.
   2. Se leen M individuos segun su especificacion.
   
   esp es la especie de los individuos de la poblacion.
   
   POST: Se añaden los individuos de la especie esp a la poblacion.
   */
  
  void escribir() const;
  /*
   PRE: cierto.
   POST: Se escriben todos los individuos de la poblacion.
   */
  
  void escribir_genotipo(string nombre) const;
  /*
   PRE: nombre es el nombre del individuo a escribir.
   
   POST: Se busca al individuo, y si existe se escribe su genotipo.
   */
  
  void escribir_arbol(string ind);
  
};

#endif /* Poblacion_hh */
