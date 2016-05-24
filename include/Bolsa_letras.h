#ifndef __Bolsa_letras_h__
#define __Bolsa_letras_h__
#include <list>
#include "Letra.h"
#include <iostream>

 /*! \mainpage Pagina Principal del Proyecto Letras
  * \image html logodelproyecto.jpg Realizado por Miguel Ángel Torres López 
  * \image html logodelproyecto.jpg
  * \section intro_sec Introducción
  *
  * El fin de este proyecto es conseguir un programa que calculé las soluciones del famoso programa de televisión 
  * “Cifras y Letras”. En este caso solamente deberá generar la sección de Letras. Este juego
  * consiste en dada una serie de letras escogidas de forma aleatoria obtener la palabra existente
  * en el diccionario formada a partir de ellas de mayor longitud.
  * Por ejemplo dadas las siguientes letras:\n
  *            \t\t\t O D Y R M E T \n
  * Una de las mejores soluciones sería METRO.\n
  *
  * Además, hemos incorporado la posibilidad de crear un juego propia, jugando con la puntuación de las letras en lugar
  * de tener en cuenta la longitud de las palabras.\n
  *
  * \section use_sec Uso 
  *
  * \subsection step1 Paso 1: Inicio del programa
  *
  * Al ejecutar el programa, si los argumentos fueron incorrectos, se ofrece ayuda para insertarlos. He aquí un pequeño resumen:
  * 
  *
  * 1. El nombre del fichero con el diccionario
  *         El diccionario será un archivo con una palabra por cada linea con todas las palabras válidas del idioma.
  *         @include Diccionario.txt
  *
  * 2. El nombre del fichero con las letras 
  *      Para crear este fichero de forma equilibrada, se aconseja usar el programa cantidad_letras, que, dado un diccionario
  *      da la frecuencia relativa de aparición de cada letra en el diccionario. La puntuación debe ser cambiada manualmente.
  * 	 @include letras_salida.txt
  *      
  * 3. El numero de letras que se deben generar de forma aleatoria
  *      Se aconseja entre 7 y 10 letras.
  *
  * 4. Modalidad de juego:\n
  *     \t  • Longitud: Si el parámetro es L se buscará la palabra más larga.\n
  *     \t • Puntuación: Si el parámetro es P se obtendrá la palabra de mayor puntuación.
  *
  *
  * \subsection step2 Paso 2: El juego
  *		El juego mostrará las letras generadas aleatoriamente de entre las del fichero con las letras y pedirá al usuario que 
  *     introduzca la mejor solución encontrada, nótese que no aceptará palabras que no se puedan formar o que no aparezcan en el 
  *     diccionario introducido.
  * 
  *     A continuación, se calculará la puntuación de la palabra del usuario y se mostrará junto con la/s mejor/es solucion/es 
  *     encontradas por la máquina. Por último se preguntará al usuario si quiere seguir jugando.
  *     \image html ejemplo_juego.png
  */
/**
   @brief T.D.A. Bolsa_letras
   
   \b Definición:
   Una instancia \e a del tipo de dato abstracto Bolsa_letras es:

   - Un conjunto de objetos \e Letras agrupados.
   
   El T.D.A. Bolsa_letras tiene programadas algunas funciones para simplifificar su tratamiento.
    
   @author Miguel Ángel Torres López
   @date 20/1/2016
*/

class Bolsa_letras{
/**
  * @page repConjuntoBolsa_letras Rep del TDA Bolsa_letras
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e rep.bolsa lista de \e Letras vacia o no.
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Bolsa_letras representa una lista de términos formado por \e Letras
  *
  */
	private:
		std::list<Letra> bolsa;
	public:
	/**
	 * @brief Construye una bolsa vacia
	**/
	Bolsa_letras(){bolsa.clear();};

	/**
	 * @brief Obtiene por referencia una letra si existe. Si la \e Letra no existiera se añade a la \e Bolsa_letras y se devuelve una
     * letra con los mismos valores.
	 * @param l caracter que representa a la \e Letra que se esta buscando
	 * @return una referencia a \e Letra
	**/
	Letra Busca(Letra l);

	/**
	 * @brief Establece la cantidad de apariciones de cada \e Letra a 0
	**/
	void VaciaCantidad();

	/**
	 * @brief Lee de un flujo de entrada de un archivo cuya primera linea es despreciada, una consecucion de \e Letras en su 
	 * formato y actualiza sus campos \e cantidad y \e puntuación o las añade a \e Bolsa_letras si no existían.
	 * @param is:flujo de entrada
	 * @param b: Bolsa_letras a actualizar
	 * @return el flujo de entrada
	**/
	friend std::ifstream & operator>>(std::ifstream & is,Bolsa_letras& b);

	/**
	 * @brief Escribe en un flujo de salida la \e Bolsa_letras en el mismo formato que en el de entrada. La primera fila contiene un
	 * indice para indicar el significado de cada columna (será despreciado en caso de ser leído).
	 * @param os:flujo de salida
	 * @param b: el objeto \e Bolsa_letras que va a ser escrito.
	 * @return el flujo de salida
	**/
	friend std::ofstream & operator<<(std::ofstream & os, Bolsa_letras& b);

	class iterator{
    private:
		std::list<Letra>::iterator it;
    public:
	 
		 /**
		  * @brief Obtiene la \e Letra asociada al iterador
		  * 
		  * */
		 Letra& operator*();
		 
		   
		 /**
		  * @brief Obtiene un iterador a la siguiente \e Letra en la Bolsa_Letras
		  * 
		  * */
		 iterator& operator ++();
			
		 /**
		  * @brief Compara dos iteradores
		  * @param i: iterador con el  que se compara
		  * @return true si los dos iteradores son iguales (la letra asociada es la misma). False en caso contrario
		  * */
		 bool operator == (iterator i);
		 	    
		 /**
		  * @brief Compara dos iteradores
		  * @param i: iterador con el  que se compara
		  * @return true si los dos iteradores son diferentes (la letra asociada es distinta). False en caso contrario
		  * */
		 bool operator != (iterator i);
		 
		 
		 friend class Bolsa_letras;
	};

	iterator begin();
	iterator end();

};
#endif
