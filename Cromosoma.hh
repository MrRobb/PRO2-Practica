//
//  Cromosoma.hh
//  PRO2
//
//  Created by Roberto Ariosa Hernandez.
//

#ifndef Cromosoma_hh
#define Cromosoma_hh

#include <vector>

using namespace std;

class Cromosoma {
  
  // Tipo de modulo: datos
  // Descripcion del tipo: contiene la informacion genetica
  // de un cromosoma, en forma de vector v[0..li-1].
  // li puede ser un entero positivo cualquiera
  
private:
  vector<int> c;
  
  /*
   
   Invariante de la representacion:
   - 0 < li
   - c[0..li] contiene la informacion genetica del cromosoma
   
   */
  
public:
  
  // Constructores
  
  Cromosoma();
  /*
   PRE: cierto.
   POST: El resultado es un cromosoma sin informacion.
   */
  
  // Destructora
  
  ~Cromosoma();
  
  // Modificadora
  
  // Lectura y escritura
  
  void leer(int li);
  /*
   PRE: La informacion del cromosoma se lee en el siguiente orden:
     1. Se leen un total de li (li >= 1) enteros positivos.
   POST: Se almacenan los datos leidos en el cromosoma.
   */
  
};

#endif /* Cromosoma_hh */
