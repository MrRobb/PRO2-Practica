//
//  Especie.hh
//  PRO2
//
//  Created by Roberto Ariosa Hernandez.
//

#ifndef Especie_hh
#define Especie_hh

#include <stdio.h>

#endif /* Especie_hh */

class Especie {
  
  // Tipo de modulo: datos
  /*
   Descripcion del tipo: almacena los datos genericos
   de una especie concreta.
   */
  
private:
  int N, li, lx, ly;
  
  /*
   
   Invariante de la representacion:
   - 0 <= N
   - li (0 <= i <= N)
   
   */
  
public:
  
  // Constructores
  
  Especie();
  
  // Destructora
  
  ~Especie();
  
  // Modificadores
  
  // Consultores
  
  int pares_cromosomas() const;
  
  int longitud_cromosoma_normal() const;
  
  int longitud_cromosoma_x() const;
  
  int longitud_cromosoma_y() const;
  
  // Lectura y escritura
  
  void leer();
  
  void escribir();
  
};
