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
  
};

#endif /* Individuo_hh */
