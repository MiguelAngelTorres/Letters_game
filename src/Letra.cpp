#include "Letra.h"	
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <cctype>

	Letra::Letra(){
		letra=' ';
		cantidad=0;
		score=0;
	}

	Letra::Letra(char l, int c, int s){
		letra = l;
		cantidad = c;
		score = s;	
	}

	int& Letra::Cantidad(){
	return cantidad;
	}

	int& Letra::Puntuacion(){
	return score;
	}
	
	bool Letra::operator==(const char l){
	return (tolower(letra)==tolower(l));
	}
	
	std::istream & operator>>(std::istream & is,Letra& l){
		std::string aux;
		std::string numero;
		unsigned int i=0;

		getline(is,aux);
		while(aux[i]==' ' || aux[i]=='\t'){
			i++;
		}
		l.letra=toupper(aux[i]);
		i++;
		i++;
		while(aux[i]==' ' || aux[i]=='\t'){
			i++;
		}
		while(aux[i]!=' ' && aux[i]!='\t'){
			numero.push_back(aux[i]);
			i++;
		}
		l.cantidad=atoi(numero.c_str());
		while(aux[i]==' ' || aux[i]=='\t'){
			i++;
		}
		numero.clear();
		while(i < aux.size()  && aux[i]!='\t'){
			numero.push_back(aux[i]);
			i++;
		}
		l.score=atoi(numero.c_str());
	return is;
	}

	std::ostream & operator<<(std::ostream & os, const Letra& l){
		os << l.letra << "       " << l.cantidad << "      " << l.score;
	return os;
	}
