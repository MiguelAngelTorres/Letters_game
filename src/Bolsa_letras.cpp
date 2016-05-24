#include "Bolsa_letras.h"
#include "Letra.h"
#include <fstream>	
#include <string.h>
#include <list>


	Letra Bolsa_letras::Busca(Letra l){
		Bolsa_letras::iterator it;
		if((*l >= 'A' && *l <= 'Z') || (*l >= 'a' && *l <= 'z') ){
			for(it=begin(); it!=end(); ++it){
				if(*it==*l){
					return *it;
				}
			}
			*l=toupper(*l);
			bolsa.push_back(l);
			it=begin();
			while(*it==*l){
				++it;
			}
			return *it;
		}
	return l;
	}


	std::ifstream & operator>>(std::ifstream & is,Bolsa_letras& b){
		std::string aux;		
		Letra laux, otra;
		
		getline(is,aux);
	
		while(!is.eof()){
			is >> laux;
			otra=b.Busca(laux);
			otra.Puntuacion()=laux.Puntuacion();
			otra.Cantidad()=otra.Cantidad();
		}
	return is;
	}

	void Bolsa_letras::VaciaCantidad(){
		std::list<Letra>::iterator it;

		for(it=bolsa.begin(); it!=bolsa.end(); ++it){
			(*it).Cantidad()=0;
		}		
	}

	std::ofstream & operator<<(std::ofstream & os,Bolsa_letras& b){
		Bolsa_letras::iterator it;

		os << "#Letra Cantidad Puntos" << std::endl;
		for(it=b.begin(); it!=b.end(); ++it){
			os << *it << std::endl;
		}
	return os;
	}
		 
		Letra& Bolsa_letras::iterator::operator*(){
			return *it;
		}
		   
		Bolsa_letras::iterator& Bolsa_letras::iterator::operator ++(){
			++it;
		return *this;
		}

		bool Bolsa_letras::iterator::operator == (Bolsa_letras::iterator i){
			return(i.it==it);
		}
		 	    
		bool Bolsa_letras::iterator::operator != (Bolsa_letras::iterator i){
			return(i.it!=it);
		}

	Bolsa_letras::iterator Bolsa_letras::begin(){
		Bolsa_letras::iterator itb;
		itb.it= bolsa.begin();
	return itb; 
	}

	Bolsa_letras::iterator Bolsa_letras::end(){
		Bolsa_letras::iterator itb;
		itb.it = bolsa.end();
	return itb;
	}
