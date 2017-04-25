//
//  Poblacion.hh
//  PRO2
//
//  Created by Roberto Ariosa Hernandez.
//

#ifndef Poblacion_hh
#define Poblacion_hh

#include "Especie.hh"
#include "Individuo.hh"
#include <iostream>
#include <map>

class Poblacion {
  
  // Tipo de modulo: datos
  /*
   Descripcion del tipo: almacena los datos de una poblacion concreta
   de individuos donde estos estan ordenados alfabeticamente y tienen
   una relacion de parentesco.
   */
  
private:
  
  map<string, Individuo> pob;
  
  bool es_antecesor(string hijo, const string &antecesor);
  /*
   PRE: antecesor es el nombre del individuo que queremos mirar si es antecesor y hijo es el nombre de un hijo de la poblacion existente.
   POST: Si el individuo antecesor es un antecesor del individuo hijo, devuelve true, sino false.
   */
  
  
public:
  
  // Constructores
  
  Poblacion();
  /*
   PRE: cierto.
   POST: Se crea una poblacion de 0 individuos.
   */
  
  // Destructora
  
  ~Poblacion();
  
  // Modificadores
  
  void anadir_individuo(const Individuo &ind);
  /*
   PRE: ind es un individuo valido.
   
   POST: Si no se ha añadido correctamente saldra un mensaje de error.
   */
  
  void reproducir(string madre, string padre, string hijo, const Especie &esp);
  /*
   PRE: El string madre, padre, son los nombres de los dos progenitores existentes en la poblacion a partir de los cuales se creara el individuo con nombre hijo, que antes no existia en la poblacion. Los padres deben ser de la especie esp y el hijo lo sera una vez creado.
   
   POST: Si alguno de los dos primeros nombres no esta entre los individuos del sistema (no existe) o el tercero si esta (ya existe) se escribira el mensaje error. Si los dos primeros individuos no pueden reproducirse se escribira el mensaje no es posible reproduccion. Para poder reproducirse el primer indi- viduo ha de tener cromosomas sexuales XX, el segundo cromosomas sexuales XY , no ser hermanos ni por parte de padre ni de madre, y no ser ninguno de los dos antecesor del otro. La operacion de reproduccion sexual producira un nuevo individuo cuyo nombre sera el tercero leido. El genotipo del descendiente se calculara a partir de los genotipos de sus padres indicando que cromosomas de cada par (el primero o el segundo) forman el ovulo y el espermatozoide y cuales son los puntos de corte para cada par de cromosomas del descendiente. El sistema registrara la relacion de parentesco entre los padres y el nuevo individuo.
   */
  
  void completar_arbol_genealogico(queue<string> elem_arb_incom);
  /*
   PRE: elem_arb_incom es una cola de elementos que representan el arbol parcial de una poblacion, si el arbol no es parcial se escribira un error: 'no es arbol parcial'.
   POST: Se escribe el arbol completado con aquellos individuos de la poblacion que faltaban.
   */
  
  // Consultores
  
  // Lectura y escritura
  
  void leer(const Especie &esp);
  /*
   PRE: Se leen los datos en el siguiente orden:
   1. un entero positivo M >= 1 individuos sin ascendientes.
   2. Se leen M individuos segun su especificacion.
   
   esp es la especie de los individuos de la poblacion.
   
   POST: Se añaden los individuos de la especie esp a la poblacion.
   */
  
  void escribir() const;
  /*
   PRE: cierto.
   POST: Se escriben todos los individuos de la poblacion.
   */
  
  void escribir_genotipo(string nombre) const;
  /*
   PRE: nombre es el nombre del individuo a escribir.
   
   POST: Se busca al individuo, y si existe se escribe su genotipo.
   */
  
  void escribir_arbol(string ind);
  /*
   PRE: el string ind debe ser un individuo de la poblacion, en caso contrario dara error.
   POST: Escribe el arbol del individuo por niveles. Dentro del mismo nivel, el padre y la madre asociados (es decir, que hayan formado pareja reproductora) apareceran consecutivos, primero el padre y despues la madre.
   */
  
};

#endif /* Poblacion_hh */
