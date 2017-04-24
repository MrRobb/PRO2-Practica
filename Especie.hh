//
//  Especie.hh
//  PRO2
//
//  Created by Roberto Ariosa Hernandez.
//

#ifndef Especie_hh
#define Especie_hh

#include <vector>

using namespace std;

class Especie {
  
  // Tipo de modulo: datos
  /*
   Descripcion del tipo: almacena los datos genericos
   de una especie concreta.
   */
  
private:
  int N, lx, ly;
  vector<int> v_li;
  
  /*
   
   Invariante de la representacion:
   - 0 <= N
   - v_li.size() == N+1
   - v[i] donde (0 <= i <= N) corresponde a li
   - 0 < lx
   - 0 < ly
   
   */
  
public:
  
  // Constructora
  
  Especie();
  /*
   PRE: cierto.
   POST: Se crea una especie donde N, lx, ly y v_li.size() == 0.
   */
  
  // Destructora
  
  ~Especie();
  
  // Modificadores
  
  // Consultores
  
  int consultar_pares_cromosomas() const;
  /*
   PRE: cierto.
   POST: Se devuelve el numero de pares de cromosomas.
   */
  
  int consultar_longitud_cromosoma_normal(int i) const;
  /*
   PRE: 0 <= i <= N
   POST: Se devuelve la longitud de un cromosoma normal o la parte común de los cromosomas sexuales (si i representa el par sexual).
   */
  
  int consultar_longitud_cromosoma_x() const;
  /*
   PRE: cierto.
   POST: Se devuelve la longitud del cromosoma x.
   */
  
  int consultar_longitud_cromosoma_y() const;
  /*
   PRE: cierto.
   POST: Se devuelve la longitud del cromosoma y.
   */
  
  // Lectura y escritura
  
  void leer();
  /*
   PRE: Se leen los datos de la especie en el siguiente orden:
   1. un entero positivo 1 <= N que indica los pares de cromosomas normales
   2. un conjunto de N+1 enteros positivos 1 <= li (0 <= i <= N) que indican la longitud del par i o la parte común de los cromosomas sexuales (si i representa el par sexual)
   3. un entero positivo 1 <= lx que indica la longitud del cromosoma x
   4. un entero positivo 1 <= ly que indica la longitud del cromosoma y
   
   POST: Se asignan esos datos a la especie.
   */
  
};

#endif /* Especie_hh */
