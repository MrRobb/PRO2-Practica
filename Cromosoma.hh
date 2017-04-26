/** @file Cromosoma.hh
    @brief Especificación de la clase Cromosoma
*/
//  Created by Roberto Ariosa Hernandez.

#ifndef Cromosoma_hh
#define Cromosoma_hh

#ifndef NO_DIAGRAM  // esto hace que el Doxyfile de la sesión no
#include <vector>   // incluya estas clases en los diagramas modulares,
#endif              // mientras que el compilador de c++
                    // sí que las procesa correctamente

using namespace std;

/** @class Cromosoma
    @brief Contiene la informacion genetica de un cromosoma.
 
    Contiene un vector con información genética del cromosoma.
*/
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

  // Constructoras

  /** @brief Constructora por defecto
   \pre cierto.
   \post El resultado es un cromosoma sin informacion.
   */
  Cromosoma();

  /** @brief Crea un cromosoma de un tamaño especifico
   \pre cierto.
   \post El resultado es un cromosoma sin informacion de tamaño li.
   */
  Cromosoma(int li);
  

  // Destructora

  // Modificadora
  
  /** @brief Cruza los cromosomas sexuales y devuelve el derivado
   \pre El cromosoma secundario es un cromosoma valido, 0 <= k <= li y li es la longitud de la parte comun entre cromosomas.
   \post Se devuelve un cromosoma que corresponde de 0 a k al parametro implicito, de k+1 a li corresponde al cromosoma secundario y de li hasta el tamaño del cromosoma implicito correspondera al parametro implicito.
   */
  Cromosoma cruzamiento_sexuales (const Cromosoma &secundario, int k, int li) const;
  
  /** @brief Cruza los cromosomas normales y devuelve el derivado
   \pre El cromosoma secundario es un cromosoma valido y 0 <= k <= li
   \post Se devuelve un cromosoma que corresponde de 0 a k al parametro implicito y de k+1 a li corresponde al cromosoma secundario.
   */
  Cromosoma cruzamiento_normales (const Cromosoma &secundario, int k) const;
  

  // Lectura y escritura
  
  /** @brief Lee un cromosoma
   \pre La informacion del cromosoma se lee en el siguiente orden:
   1. Se leen un total de li (li >= 1) enteros positivos.
   \post Se almacenan los datos leidos en el cromosoma.
   */
  void leer(int li);
  
  /** @brief Escribe un cromosoma
   \pre cierto.
   \post Se escribe el contenido del cromosoma.
   */
  void escribir() const;
  
};

#endif /* Cromosoma_hh */
