#ifndef __Letra_h__
#define __Letra_h__
#include <iostream>

/**
   @brief T.D.A. Letra
   
   \b Definición:
   Una instancia \e a del tipo de dato abstracto Letra se puede construir como:

   - Una terna de elementos cuyos campos corresponden al caractér de la letra a la que representan,
   un entero que marca el número de apariciones de la letra y otro entero con puntuación de la misma.
   
   El T.D.A. Letra tiene programadas algunas funciones para simplifificar su tratamiento.
    
   @author Miguel Ángel Torres López
   @date 20/1/2016
*/
class Letra{
/**
  * @page repConjuntoLetra Rep del TDA Letra
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e rep.letra[0]!="" y \e rep.cantidad y \e rep.score dos enteros.
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Letra representa una terna formada por :
  *
  *    Un caracter 
  *    La cantidad de veces que aparece el caracter
  *    La puntacion del caracter 
  *
  */
	private:
		char letra;
		int cantidad;
		int score;

	public:
	/**
	 * @brief Construye una letra vacía, el valor del caracter es nulo.
	**/
	Letra();

	/**
	 * @brief Construye una letra cuyo valor de caracter es \e l. Es posible especificar la cantidad y la puntuación,
	 * aunque por defecto son 1 y 0 respectivamente.
	**/
	Letra(char l, int c=1, int s=0) ;

	/**
	 * @brief Obtiene por referencia la cantidad de una letra.
	 * @return una referencia al entero con la cantidad de la letra.
	**/
	int& Cantidad();

	/**
	 * @brief Obtiene por referencia la puntuación de la letra.
	 * @return un entero con la puntuacion de la letra.
	**/
	int& Puntuacion();

	/**
	 * @brief Compara si los caracteres de dos letras son el mismo
	 * @return true si el caracter es el mismo y false si no lo es (Nótese que devolverá true aunque sus cantidades y puntuacion sean 
	 * distintos).
	**/
	bool operator==(const char l);

	/**
	 * @return el caracter al que representa la \e Letra
	**/
	char& operator*(){return letra;};

	/**
	 * @brief Lee de un flujo de entrada de una letra con el formato \e caracter \e cantidad \e puntuacion
	 * @param is flujo de entrada
	 * @param l letra a actualizar
	 * @return el flujo de entrada
	**/
	friend std::istream & operator>>(std::istream & is,Letra& l);

	/**
	 * @brief Escribe en un flujo de salida una letra con el mismo formato que el de entrada (@see operator>>)
	 * @param os flujo de salida
	 * @param l el objeto letra que se escribe
	 * @return el flujo de salida
	**/
	friend std::ostream & operator<<(std::ostream & os, const Letra& l);

};
#endif
