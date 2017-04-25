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
  
  Cromosoma(int li);
  /*
   PRE: cierto.
   POST: El resultado es un cromosoma sin informacion de tamaño li.
   */
  
  // Destructora
  
  ~Cromosoma();
  
  // Modificadora
  
  Cromosoma cruzamiento_sexuales (const Cromosoma &secundario, int k, int li) const;
  /*
   PRE: El cromosoma secundario es un cromosoma valido, 0 <= k <= li y li es la longitud de la parte comun entre cromosomas.
   POST: Se devuelve un cromosoma que corresponde de 0 a k al parametro implicito, de k+1 a li corresponde al cromosoma secundario y de li hasta el tamaño del cromosoma implicito correspondera al parametro implicito.
   */
  
  Cromosoma cruzamiento_normales (const Cromosoma &secundario, int k) const;
  /*
   PRE: El cromosoma secundario es un cromosoma valido y 0 <= k <= li
   POST: Se devuelve un cromosoma que corresponde de 0 a k al parametro implicito y de k+1 a li corresponde al cromosoma secundario.
   */
  
  // Lectura y escritura
  
  void leer(int li);
  /*
   PRE: La informacion del cromosoma se lee en el siguiente orden:
     1. Se leen un total de li (li >= 1) enteros positivos.
   POST: Se almacenan los datos leidos en el cromosoma.
   */
  
  void escribir() const;
  /*
   PRE: cierto.
   POST: Se escribe el contenido del cromosoma.
   */
  
};

#endif /* Cromosoma_hh */
