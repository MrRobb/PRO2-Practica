/** @file Especie.hh
    @brief Especificación de la clase Especie
*/
//  Created by Roberto Ariosa Hernandez.

#ifndef Especie_hh
#define Especie_hh

#ifndef NO_DIAGRAM    // ver explicacion en Cromosoma.hh
#include <vector>
#endif

using namespace std;

/** @class Especie
    @brief Representa una especie.

    Contiene el número de pares de Cromosomas, el tamaño de cada uno de esos pares y el tamaño del cromosoma X e Y.
*/

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

  // Constructoras

  /** @brief Creadora por defecto
   
   Se ejecuta automáticamente al declarar una especie.
   \pre cierto.
   \post Se crea una especie donde N, lx, ly y v_li.size() == 0.
   */
  Especie();
  

  // Destructora

  // Modificadoras

  // Consultoras

  /** @brief Consultora del número de pares de cromosomas
   \pre cierto.
   \post Se devuelve el numero de pares de cromosomas.
   */
  int consultar_pares_cromosomas() const;
  
  /** @brief Consultora de la longitud de un cromosoma
   \pre 0 <= i <= N
   \post Se devuelve la longitud de un cromosoma normal o la parte común de los cromosomas sexuales (si i representa el par sexual).
   */
  int consultar_longitud_cromosoma_normal(int i) const;
  
  /** @brief Consultora de la longitud de x
   \pre cierto.
   \post Se devuelve la longitud del cromosoma x.
   */
  int consultar_longitud_cromosoma_x() const;
  
  /** @brief Consultora de la longitud de y
   \pre cierto.
   \post Se devuelve la longitud del cromosoma y.
   */
  int consultar_longitud_cromosoma_y() const;

  // Lectura
  
  /** @brief Lectura de la especie
   \pre Se leen los datos de la especie en el siguiente orden:
   1. un entero positivo 1 <= N que indica los pares de cromosomas normales
   2. un conjunto de N+1 enteros positivos 1 <= li (0 <= i <= N) que indican la longitud del par i o la parte común de los cromosomas sexuales (si i representa el par sexual)
   3. un entero positivo 1 <= lx que indica la longitud del cromosoma x
   4. un entero positivo 1 <= ly que indica la longitud del cromosoma y
   
   \post Se asignan esos datos a la especie.
   */
  void leer();
  

};

#endif /* Especie_hh */
