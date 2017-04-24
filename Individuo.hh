//
//  Individuo.hh
//  PRO2
//
//  Created by Roberto Ariosa Hernandez.
//

#ifndef Individuo_hh
#define Individuo_hh

#include "Especie.hh"
#include "Cromosoma.hh"
#include <iostream>
#include <vector>

using namespace std;

class Individuo {
  
  // Tipo de modulo: datos
  /*
   Descripcion del tipo: almacena los datos de un individuo concreto, su informacion genetica y sus progenitores.
   */
  
private:
  string nombre, padre, madre;
  bool es_masculino;
  vector< pair< Cromosoma, Cromosoma > > adn;
  
  /*
   
   Invariante de la representacion:
   - 
   - si es_masculino == false, es femenino. si es_masculino == true, es masculino.
   
   */
  
public:
  
  // Constructora
  
  Individuo();
  
  // Destructora
  
  ~Individuo();
  
  // Modificadoras
  
  // Consultoras
  
  string consultar_nombre() const;
  /*
   PRE: cierto.
   POST: Devuelve el nombre del individuo.
   */
  
  // Leer y escribir
  
  void leer(const Especie &esp);
  /*
   PRE: Se leen los datos de cada individuo en el siguiente orden:
   1. un nombre para el individuo que lo identificara (string con letras y digitos).
   2. La composicion genetica del individuo:
     2.1 una 'X' si es hembra o una 'Y' si es macho.
     2.2 primero se leen los cromosomas sexuales, primero el X y luego el X o Y dependiendo de su sexo (2.1), a continuacion se leen todos los cromosomas normales segun su especificacion.
   
   esp es la especie del individuo.
   
   POST: Se almacena la informacion en el individuo de la especie esp.
   */
  
  void escribir() const;
  /*
   PRE: cierto.
   POST: Se escribe el nombre del individuo, el sexo, y los padres (si no tiene son $).
   */
  
  void escribir_genotipo() const;
  /*
   PRE: cierto.
   
   POST: Se escriben los cromosomas del individuo por orden creciente, por orden creciente de identificador de par de cromosomas (primero el par de cromosomas sexuales y luego los N pares de cromosomas normales); dentro de cada par, primero se escribira el primer cromosoma y luego el segundo; dentro de cada cromosoma, se escribiran los valores de los genes por orden creciente de posicion. Para cada par de cromosomas, el orden entre los dos cromosomas depende de si el individuo tiene progenitores conocidos o no. Si se trata de un individuo sin ascendientes, el orden de escritura sera el mismo que el orden en que se leyeron los dos cromosomas. Si se trata de un individuo con ascendientes, primero se escribira c′i1 y luego c′i2, resultado del cruce entre ci1 y ci2, donde ci1 es el cromosoma proveniente del ovulo (celula de la madre) y ci2 el cromosoma proveniente del espermatozoide (celula del padre).
   */
  
};

#endif /* Individuo_hh */
