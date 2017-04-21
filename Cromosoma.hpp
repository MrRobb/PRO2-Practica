//
//  Cromosoma.hpp
//  PRO2
//
//  Created by Roberto Ariosa Hernández.
//

#ifndef Cromosoma_hpp
#define Cromosoma_hpp

#include <vector>

using namespace std;

#endif /* Cromosoma_hpp */

class Cromosoma {
  
  // Tipo de modulo: datos
  // Descripcion del tipo: contiene la informacion genetica
  // de un cromosoma, en forma de vector v[0..li-1].
  // li puede ser un entero positivo cualquiera
  
private:
  int li;
  vector<int> c;
  
  /*
   
   Invariante de la representacion:
   - 0 < li
   - c[0..li] contiene la informacion genetica del cromosoma
   
   */
  
public:
  
  // Constructores
  
  Cromosoma();
  /* Pre: cert */
  /* Post: el resultado es un cromosoma vacio, con li == 0 y c.size() == 0 */
  
  Cromosoma(vector<int> c);
  /* Pre: c.size() > 0 */
  
  // Destructora: borra automaticamente los objectos locales en salir
  // de un ambito de visibilidad
  ~Cromosoma();
  
  // Modificadora
  
  Cromosoma cruzamiento (Cromosoma c_fill, Cromosoma c_progenitor, int k);
  
  // Lectura y escritura
  
  void leer();
  
  void escribir() const;
  
};
