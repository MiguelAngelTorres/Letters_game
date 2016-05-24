#ifndef __Diccionario_h__
#define __Diccionario_h__
#include "ArbolGeneral.h"
#include <vector>

/**
 * @brief Pareja de elementos que constituyen las etiquetas de cada nodo
 * en el TDA ArbolGeneral para formar el TDA Diccionario.
**/
struct info{
	char c; 
	bool fin; 

info(){
	c='\0';
	fin=false;
}

info(char car, bool f):c(car),fin(f){}
};

/**
   @brief T.D.A. Diccionario
   
   \b Definición:
   Una instancia \e a del tipo de dato abstracto Diccionario se puede construir como:
   
   - Un objeto vacío (Diccionario sin palabras) si no contiene ningún elemento. 

   - Un árbol general que contiene en sus nodos elementos del tipo \e info, formados por un
   caracter (normalmente una letra) y un booleano que indica si el camino desde la 
   raiz hasta el nodo es una palabra.
    
   Para más información sobre la estructura interna del Diccionario acuda a la documentación 
   detallada en el TDA ArbolGeneral sobre el que se ha instanciado este TDA.
   
   Para poder usar el tipo de dato ArbolGeneral se debe incluir el fichero
   
   <tt>\#include ArbolGeneral.h</tt>
   
   El espacio requerido para el almacenamiento es O(n), donde n es el número de
   nodos del árbol.
   
   @author Miguel Ángel Torres López
   @date 20/1/2016
*/
class Diccionario{
/**
  * @page repConjuntoDiccionario Rep del TDA Diccionario
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es un objeto de tipo Arbol General instanciado con parejas de caracter!="" y booleano[true,false].
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto valido Diccionario representa cadenas de caracteres señalados para marcar el fin de una palabra.
  */
	private:
		ArbolGeneral<info> datos;

	public:
	/**
	 * @brief Construye un diccionario vacío.
	**/
	Diccionario();

	/**
	 * @brief Devuelve el numero de palabras en el diccionario
	**/
	int size() ;

	/**
	 * @brief Obtiene todas las palabras en el diccionario de un longitud dada
	 * @param longitud: la longitud de las palabras de salida
	 * @return un vector con las palabras de longitud especifica en el parametro de entrada
	**/
	vector<string> PalabrasLongitud(int longitud);

	/**
	 * @brief Indica si una palabra está en el diccionario o no
	 * @param palabra: la palabra que se quiere buscar
	 * @return true si la palabra esta en el diccionario. False en caso contrario
	**/
	bool Esta(string palabra);

	/**
	 * @brief Lee de un flujo de entrada un diccionario
	 * @param is:flujo de entrada
	 * @param D: el objeto donde se realiza la lectura.
	 * @return el flujo de entrada
	**/
	friend std::istream & operator>>(std::istream & is,Diccionario& D);

	/**
	 * @brief Escribe en un flujo de salida un diccionario
	 * @param os:flujo de salida
	 * @param D: el objeto diccionario que se escribe
	 * @return el flujo de salida
	**/
	friend std::ostream & operator<<(std::ostream & os, const Diccionario& D);

	class iterator{
    private:
		ArbolGeneral<info>::iter_preorden it;
		string cad;
    public:
	 
		 /**
		  * @brief Constructor por defecto
		  * 
		  * */
		iterator();
		 
		 /**
		  * @brief Obtiene la palabra asociada al iterador
		  * 
		  * */
		 string operator*();
		 
		   
		 /**
		  * @brief Obtiene un iterador a la siguiente palabra registrada en el diccionario
		  * 
		  * */
		 iterator& operator ++();
			
		 /**
		  * @brief Compara dos iteradores
		  * @param i: iterador con el  que se compara
		  * @return true si los dos iteradores son iguales (la palabra asociada es la misma). False en caso contrario
		  * */
		 bool operator == (iterator i);
		 	    
		 /**
		  * @brief Compara dos iteradores
		  * @param i: iterador con el  que se compara
		  * @return true si los dos iteradores son diferentes (la palabra asociada es distinta). False en caso contrario
		  * */
		 bool operator != (iterator i);
		 
		 
		 friend class Diccionario;
	};
	 /**
	  * @brief Iterador de inicio
	  * @return iterador inicial de la clase Diccionario
	* */
	iterator begin() const;

 	/**
	  * @brief Iterador de final
	  * @return iterador final de la clase Diccionario
	* */
	iterator end() const;
};
#endif
