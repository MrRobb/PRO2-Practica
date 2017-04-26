/** @file Individuo.hh
    @brief Especificación de la clase Individuo
*/
//  Created by Roberto Ariosa Hernandez.

#ifndef Individuo_hh
#define Individuo_hh

#include "Especie.hh"
#include "Cromosoma.hh" // redundante, pero necesario para el diagrama modular

#ifndef NO_DIAGRAM      // ver explicacion en Cromosoma.hh
#include <iostream>
#include <vector>
#endif

using namespace std;

/** @class Individuo
    @brief Representa un individuo de la especie.
    
    Contiene el nombre del padre, de la madre y del individuo, su sexo y su información genética.
 
 */
class Individuo {

  // Tipo de modulo: datos
  /*
   Descripcion del tipo: almacena los datos de un individuo concreto, su informacion genetica y sus progenitores.
   */

private:
  string nombre, padre, madre;
  bool es_masculino;
  vector< vector<Cromosoma> > adn;

  /*

   Invariante (temporal) de la representacion:
   - adn[0] es el par de cromosomas sexuales
   - adn[1..N] son los pares de cromosomas normales
   - si es_masculino == false, es femenino. si es_masculino == true, es masculino.

   */

public:

  // Constructora

  /** @brief Creadora por defecto
   
   Se ejecuta automáticamente al declarar un individuo.
   \pre <em>cierto</em>
   \post El resultado es un individuo sin leer, es decir, sin información genética, ni nombre, ni padres, ni sexo.
   */
  Individuo();

  /** @brief Crea un individuo a partir de los genotipos de los progenitores
   \pre El padre es un individuo valido. La madre es un individuo valido. Se leen los valores que determinan la reproduccion, en el siguiente orden:
   1. Cual de los pares de la madre forma el ovulo ('0' --> primero , '1' --> segundo)
   2. Cual de los pares de la madre forma el espermatozoide ('0' --> primero , '1' --> segundo)
   3. Un conjunto de N+1 enteros entre 0 y li que indican el punto de corte de cada par de cromosomas (N y li dependen de la especie).
   
   \post Se crea un individuo hijo de padre y hijo de madre a partir los genotipos de los padres, segun los datos de entrada.
   */
  Individuo(string nombre, const Individuo &madre, const Individuo &padre, const Especie &esp);
  

  // Destructora

  // Modificadoras

  // Consultoras

  /** @brief Consultora de si tiene ascendientes
   \pre cierto.
   \post Devuelve true si tiene padre o madre y false si no.
   */
  bool tiene_ascendientes() const;
  
  /** @brief Consultora de su sexo
   \pre cierto.
   \post Devuelve true si es masculino y false si es femenino.
   */
  bool consultar_es_masculino() const;
  
  /** @brief Consultora de su nombre
   \pre cierto.
   \post Devuelve el nombre del individuo.
   */
  string consultar_nombre() const;
  
  /** @brief Consultora del nombre de su madre
   \pre cierto.
   \post Devuelve el nombre de la madre del individuo.
   */
  string consultar_madre() const;
  
  /** @brief Consultora del nombre de su padre
   \pre cierto.
   \post Devuelve el nombre del padre del individuo.
   */
  string consultar_padre() const;
  
  
  // Leer y escribir
  
  /** @brief Lee un individuo
   \pre Se leen los datos de cada individuo en el siguiente orden:
   1. un nombre para el individuo que lo identificara (string con letras y digitos).
   2. La composicion genetica del individuo:
   2.1 una 'X' si es hembra o una 'Y' si es macho.
   2.2 primero se leen los cromosomas sexuales, primero el X y luego el X o Y dependiendo de su sexo (2.1), a continuacion se leen todos los cromosomas normales segun su especificacion.
   
   esp es la especie del individuo.
   
   \post Se almacena la informacion en el individuo de la especie esp.
   */
  void leer(const Especie &esp);
  
  /** @brief Escribe un individuo
   \pre cierto.
   \post Se escribe el nombre del individuo, el sexo, y los padres (si no tiene son $).
   */
  void escribir() const;
  
  /** @brief Escribe el genotipo de un individuo
   \pre cierto.
   
   \post Se escriben los cromosomas del individuo por orden creciente, por orden creciente de identificador de par de cromosomas (primero el par de cromosomas sexuales y luego los N pares de cromosomas normales); dentro de cada par, primero se escribira el primer cromosoma y luego el segundo; dentro de cada cromosoma, se escribiran los valores de los genes por orden creciente de posicion. Para cada par de cromosomas, el orden entre los dos cromosomas depende de si el individuo tiene progenitores conocidos o no. Si se trata de un individuo sin ascendientes, el orden de escritura sera el mismo que el orden en que se leyeron los dos cromosomas. Si se trata de un individuo con ascendientes, primero se escribira c′i1 y luego c′i2, resultado del cruce entre ci1 y ci2, donde ci1 es el cromosoma proveniente del ovulo (celula de la madre) y ci2 el cromosoma proveniente del espermatozoide (celula del padre).
   */
  void escribir_genotipo() const;
  
};

#endif /* Individuo_hh */
