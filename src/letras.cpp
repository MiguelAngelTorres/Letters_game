#include "Diccionario.h"
#include "Bolsa_letras.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <cctype>

using namespace std;

int Score(Bolsa_letras& mibolsa,string palabra, char modo){  /// CALCULA LA PUNTUACIÓN DE UNA PALABRA SEGÚN EL MODO DE JUEGO  ///
	int res=0;
	unsigned int i = 0;
	Letra aux;
	if(modo=='L'){
		res = palabra.size();
	}else if(modo=='P'){
		while(i<palabra.size()){
			*aux = palabra[i];
			res+=mibolsa.Busca(aux).Puntuacion();
			i++;
		}
	}
return res;
}

bool Chequea(string palabra, vector<pair<char,bool> > lej){   /// COMPRUEBA SI LA PALABRA SE PUEDE FORMAR CON LAS LETRAS DE UNA BOLSA  ///
	unsigned int i=0,numle=lej.size(),j=0;
	bool encontrada=true;
	pair<char,bool> nuevo;
	nuevo.second = true;

	while(encontrada && i<palabra.size()){
		nuevo.first=palabra[i];
		while(j<numle && nuevo!=lej[j]){
			j++;
		}
		if(j==numle){
			encontrada=false;
		}else{
			lej[j].second=false;
		}
		j=0;
		i++;
	}
return encontrada;
}

int main(int argc, char* argv[]){
	if(argc < 4 || (*(argv[4])!='P' && *(argv[4])!='L')){
		cout << "Argumentos no validos: <Diccionario> <letras_a_jugar> <letras_a_generar> <modo_de_juego[P,L]>" << endl;
		return -1;
	}
	Bolsa_letras mibolsa;
	Diccionario midiccionario;
	Diccionario::iterator it;
	Bolsa_letras::iterator itb;
	unsigned int numle = atoi(argv[3]);
	vector<pair<char,bool> > lej;
	pair<char,bool> nuevo;
	nuevo.second = true;
	bool continua = true, sigue;

	
	ifstream fi(argv[1]);
	fi>>midiccionario;
	fi.close();
	fi.open(argv[2]);
	fi>>mibolsa;
	fi.close();

	bool encontrada = true;
	vector<string> res;
	string resuser;
	int random = 0;
	int acumm = 0;
	int max = 0,act;
	unsigned int i=0;
	
	while(continua){
		res.clear();
		lej.clear();
////////////////////////////////////////////////////////   SACANDO LETRAS DE LA BOLSA  ////////////////////////////////////////////////////
	
		for(itb=mibolsa.begin(); itb!=mibolsa.end(); ++itb){
			act += (*itb).Cantidad();
		}
		srand(time(NULL));
		
		for(i=0; i<numle; i++){
			acumm = 0;
			random = rand()%act;
			sigue=true;
			for(itb=mibolsa.begin(); itb!=mibolsa.end(); ++itb){
				acumm += (*itb).Cantidad();
				if(acumm >= random && sigue){	
					nuevo.first = tolower((*(*itb)));
					lej.push_back(nuevo);
					sigue = false;
				}
			}
		}
//////////////////////////////////////////////////////////   SACAR SOLUCIÓN ÓPTIMA   //////////////////////////////////////////////////////
		
		i=0;
		max=0;
		res.clear();
		for(it=midiccionario.begin(); it!=midiccionario.end(); ++it){
			if((*it).size()<=numle){
				if(Chequea(*it,lej)){
					act=Score(mibolsa,*it,argv[4][0]);
					if(act == max){
						res.push_back(*it);
					}else if(act > max){
						res.clear();
						res.push_back(*it);
						max = act;
						*it ;
					}
				}
			}
		}
//////////////////////////////////////////////////////////    INTERFAZ DE JUEGO    ////////////////////////////////////////////////////////
	
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nLas letras son:   ";
		for(i=0; i<lej.size();i++){
			cout << lej[i].first << "  " ;
		} 
		cout << endl << endl;
		cout << "Dime tu solucion: ";
		cin >> resuser ;
		for(i=0;i<resuser.size();){
			resuser[i]=tolower(resuser[i]);
			i++;
		}
		while(!midiccionario.Esta(resuser) || !Chequea(resuser,lej)){
			cout << "La palabra no se encuentra en el diccionario o no se puede formar, prueba con otra: ";
			cin >> resuser ;
			for(i=0;i<resuser.size();){
				resuser[i]=tolower(resuser[i]);
				i++;
			}
		}
		cout << endl;
		cout << resuser << " --> " << Score(mibolsa,resuser,argv[4][0]) << " puntos." << endl << endl;
		cout << "Tengo " << res.size() << " soluciones: " <<  endl;
		acumm=Score(mibolsa,res[0],argv[4][0]);
		for(i=0;i<res.size();i++){
			cout << res[i] << " --> " << max << " puntos." << endl;
		}
		encontrada = true;
		while(encontrada){
			cout << "¿Quieres seguir jugando? [Y/N]" << endl;
			cin >> resuser;
			resuser[0]=tolower(resuser[0]);
			if(resuser[0] == 'n'){
				continua=false;
				encontrada=false;
			}else if(resuser[0] == 'y'){
				continua=true;
				encontrada=false;
			}else{
				cout << "Creo que no te he entendido bien.";
			} 				
		}
	}
}
