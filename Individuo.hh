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
  
private:
  string nombre, padre, madre;
  bool sexo;
  vector< pair< Cromosoma, Cromosoma > > adn;
  
public:
  
  void leer();
  /*
   PRE: Se leen los datos de cada individuo en el siguiente orden:
   1. un nombre para el individuo que lo identificara (string con letras y digitos).
   2. La composicion genetica del individuo:
     2.1 una 'X' si es hembra o una 'Y' si es macho.
     2.2 primero se leen los cromosomas sexuales, primero el X y luego el X o Y dependiendo de su sexo (2.1), a continuacion se leen todos los cromosomas normales segun su especificacion.
   
   POST: Se almacena la informacion en el individuo.
   */
  
};

#endif /* Individuo_hh */
