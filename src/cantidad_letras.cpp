#include "Bolsa_letras.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include "Diccionario.h"

using namespace std;

int main(int argc,char* argv[]){
	Bolsa_letras mibolsa;
	Diccionario midiccionario;
	Diccionario::iterator it;
	Bolsa_letras::iterator itb;

	if(argc != 4){
		cout << "Argumentos no validos: <Diccionario> <entrada_letras> <salida_letras>" << endl;
	}
	ifstream fi(argv[1]);
	fi>>midiccionario;
	fi.close();
	fi.open(argv[2]);
	fi>>mibolsa;
	fi.close();
	
	mibolsa.VaciaCantidad();
	string palabra;
	int numchar = 0;
	unsigned i;
	Letra l;
	l.Cantidad()=0;
	l.Puntuacion()=1;

	for(it=midiccionario.begin(); it!=midiccionario.end(); ++it){
		palabra=*it;
		for(i=0; i<palabra.size(); i++){
			*l = palabra[i];
			mibolsa.Busca(l).Cantidad()+=1;
		}
		numchar=numchar+i;
	}
	
	for(itb=mibolsa.begin(); itb!=mibolsa.end(); ++itb){
		(*itb).Cantidad()=floor(((*itb).Cantidad()* 100 / numchar)) +1 ;
	}
	ofstream fo;
	fo.open(argv[3]);
	fo<<mibolsa;
	fo.close();
}
