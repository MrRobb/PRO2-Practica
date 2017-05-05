/** @file Poblacion.hh
    @brief Especificación de la clase Poblacion
*/
//  Created by Roberto Ariosa Hernandez.

#ifndef Poblacion_hh
#define Poblacion_hh

#include "Especie.hh"
#include "Cromosoma.hh" // redundante, pero necesario para el diagrama modular
#include "Individuo.hh"

#ifndef NO_DIAGRAM      // ver explicacion en Cromosoma.hh
#include <iostream>
#include <map>
#include <queue>
#endif

/** @class Poblacion
    @brief Representa un poblacion de individuos de una misma especie.
    
    Si está leída, contiene un registro formado por los individuos de la poblacion, ordenado por nombre, sinó está leída, contiene una población vacía, es decir, sin individuos.
 
    Todas las operaciones son de <b>coste constante</b>.
*/
class Poblacion {

  // Tipo de modulo: datos
  /*
   Descripcion del tipo: almacena los datos de una poblacion concreta
   de individuos donde estos estan ordenados alfabeticamente y tienen
   una relacion de parentesco.
   */

private:

  map<string, Individuo> pob;
  /*
   Invariante de la representacion:
    - Los individuos de la poblacion estan ordenados por nombre
   */
  
  /** 
   \pre antecesor es el nombre del individuo que queremos mirar si es antecesor y hijo es el nombre de un hijo de la poblacion existente.
   \post Si el individuo antecesor es un antecesor del individuo hijo, devuelve true, sino false.
   */
  bool es_antecesor(string hijo, const string &antecesor);

  void i_escribir_padres(queue<string> &q_individuos, string ind);
  
public:

  // Constructoras

  /** @brief Creadora por defecto
   
   Se ejecuta automáticamente al declarar una población.
   \pre cierto.
   \post Se crea una poblacion de 0 individuos.
   */
  Poblacion();

  // Modificadoras

  /** @brief Añade un individuo sin ascendentes a la población
   \pre ind es un individuo valido.
   \post Si no se ha añadido correctamente saldra un mensaje de error.
   */
  void anadir_individuo(string nombre, const Individuo &ind);
  
  /** @brief Reproduce dos individuos y añade el hijo a la población
   \pre El string madre, padre, son los nombres de los dos progenitores existentes en la poblacion a partir de los cuales se creara el individuo con nombre hijo, que antes no existia en la poblacion. Los padres deben ser de la especie esp y el hijo lo sera una vez creado.
   
   \post Si alguno de los dos primeros nombres no esta entre los individuos del sistema (no existe) o el tercero si esta (ya existe) se escribira el mensaje error. Si los dos primeros individuos no pueden reproducirse se escribira el mensaje no es posible reproduccion. Para poder reproducirse el primer indi- viduo ha de tener cromosomas sexuales XX, el segundo cromosomas sexuales XY , no ser hermanos ni por parte de padre ni de madre, y no ser ninguno de los dos antecesor del otro. La operacion de reproduccion sexual producira un nuevo individuo cuyo nombre sera el tercero leido. El genotipo del descendiente se calculara a partir de los genotipos de sus padres indicando que cromosomas de cada par (el primero o el segundo) forman el ovulo y el espermatozoide y cuales son los puntos de corte para cada par de cromosomas del descendiente. El sistema registrara la relacion de parentesco entre los padres y el nuevo individuo.
   */
  void reproducir(string madre, string padre, string hijo, const Especie &esp);

  // Consultores
  
  /** @brief Consulta si son hermanos
   \pre ind1 y ind2 existen en la población.
   \post devuelve true si son hermanos y false si no lo son.
   */
  bool son_hermanos(string ind1, string ind2);
  
  /** @brief Completa un arbol genealogico
   \pre elem_arb_incom es una cola de elementos que representan el arbol parcial de una poblacion, si el arbol no es parcial se escribira un error: 'no es arbol parcial'.
   \post Se escribe el arbol completado con aquellos individuos de la poblacion que faltaban.
   */
  bool completar_arbol_genealogico(queue<string> &elem_arb_incom);

  // Lectura y escritura
  
  /** @brief Lee una población de una especie
   \pre Se leen los datos en el siguiente orden:
   1. un entero positivo M >= 1 individuos sin ascendientes.
   2. Se leen M individuos segun su especificacion.
   
   esp es la especie de los individuos de la poblacion.
   
   \post Se añaden los individuos de la especie esp a la poblacion.
   */
  void leer(const Especie &esp);
  
  /** @brief Escribe una población.
   \pre cierto.
   \post Se escriben todos los individuos de la poblacion.
   */
  void escribir() const;
  
  /** @brief Escribe un genotipo de un individuo
   \pre nombre es el nombre del individuo a escribir.
   
   \post Se busca al individuo, y si existe se escribe su genotipo.
   */
  void escribir_genotipo(string nombre) const;
  
  /** @brief Escribe un arbol de un individuo
   \pre el string ind debe ser un individuo de la poblacion, en caso contrario dara error.
   \post Escribe el arbol del individuo por niveles. Dentro del mismo nivel, el padre y la madre asociados (es decir, que hayan formado pareja reproductora) apareceran consecutivos, primero el padre y despues la madre.
   */
  void escribir_por_niveles(string ind);
  

};

#endif /* Poblacion_hh */
