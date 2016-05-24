#include <vector>
#include <stack>
#include <string.h>
#include <iostream>
#include <Diccionario.h>

	Diccionario::Diccionario(){
		info* aux = new info;
		aux->fin=false;
		aux->c=' ';
		datos.AsignaRaiz(*aux);
	}

	int Diccionario::size(){
		int tam = 0;
		ArbolGeneral<info>::iter_preorden ite;
		for(ite = datos.begin(); ite != datos.end(); ++ite){
			if((*ite).fin){
				tam++;
			}
		}
	return tam;
	}

	vector<string> Diccionario::PalabrasLongitud(int longitud){
		vector<string> palabras;
		string palabra;
		stack<char> aux;
		ArbolGeneral<info>::Nodo nod;
		ArbolGeneral<info>::iter_preorden ite;

		for(ite = datos.begin(); ite != datos.end(); ++ite){
			if((*ite).fin && ite.getlevel()==longitud){
				nod=ite.Elem();
				while(nod!=NULL){
					aux.push((nod->etiqueta).c);
					nod=nod->padre;
				}
				for(int i=longitud; i>=0; i--){
					palabra.push_back(aux.top());
					aux.pop();
				}
				palabras.push_back(palabra);
				palabra.clear();
			}
		}
	return palabras;
	}
	
	bool Diccionario::Esta(string palabra){
		int tam=palabra.size();
		bool encontrada=true;
		ArbolGeneral<info>::Nodo nod=datos.raiz();
		int i=0;

		
		while(i<tam && encontrada){
			nod=nod->izqda;
			while(nod->drcha!=NULL && nod->etiqueta.c != palabra[i]){
				nod=nod->drcha;
			}	
			if(nod->etiqueta.c != palabra[i]){
				encontrada=false;
			}
			i++;
		}
	return encontrada;
	}

	std::istream& operator>> (std::istream& is,Diccionario& D){
		string palabra;
		typename ArbolGeneral<info>::Nodo nod;
		int tam ;
		int i = 0;
		info aux;
		ArbolGeneral<info> mem;

		while(getline(is,palabra)){
			tam = palabra.size();
			nod = D.datos.raiz();
			i=0;	
			while(i<tam){
				if(nod->izqda==NULL){
					aux.c=palabra[i];
					if(tam==i+1){
						aux.fin=true;
					}else{
						aux.fin=false;
					}
					mem.AsignaRaiz(aux);
					D.datos.insertar_hijomasizquierda(nod,mem);
					nod=nod->izqda;
					nod->izqda=NULL;
					nod->drcha=NULL;
				}else{
					nod=nod->izqda;
					while(nod->drcha!=NULL && nod->etiqueta.c != palabra[i]){
						nod=nod->drcha;
					}	
					if(nod->etiqueta.c != palabra[i]){
						aux.c=palabra[i];
						if(tam==i+1){
							aux.fin=true;
						}else{
							aux.fin=false;
						}
						mem.AsignaRaiz(aux);
						D.datos.insertar_hermanoderecha(nod,mem);
						nod=nod->drcha;
						nod->izqda=NULL;
					}
				}
				i++;
			}	
		}
	return is;
	}

	std::ostream& operator<< (std::ostream& os, const Diccionario& D){
		Diccionario::iterator ite;
		for(ite = ++(D.begin()); ite != D.end(); ++ite){
			os << *ite << endl;
		}
	return os;
	}

	Diccionario::iterator::iterator(){
		cad.clear();
	}

	string Diccionario::iterator::operator*(){
	return cad;
	}
		 
	typename Diccionario::iterator& Diccionario::iterator::operator ++(){
		typename ArbolGeneral<info>::Nodo nod;
		stack<char> aux;

		++it;
		while(it.Elem()!=NULL && (*it).fin==false){
			++it;
		}
		if(it.Elem()!=NULL){
			nod = it.Elem();
			while(nod->padre!=NULL){
				aux.push(nod->etiqueta.c);
				nod=nod->padre;
			}
			cad.clear();
			while(!aux.empty()){
				cad.push_back(aux.top());
				aux.pop();
			}
		}else{
			cad.clear();
		}
	return *this;
	}
			
	bool Diccionario::iterator::operator == (iterator i){
	return it==i.it;
	}

	bool Diccionario::iterator::operator != (iterator i){
	return (it!=i.it);
	}

	Diccionario::iterator Diccionario::begin() const{
		Diccionario::iterator ite;
		ite.it = datos.begin();
		ite.cad.clear();
	return ite;
	}
	
	Diccionario::iterator Diccionario::end() const{
		Diccionario::iterator ite;
		ite.it = datos.end();
		ite.cad.clear();
	return ite; 
	}
