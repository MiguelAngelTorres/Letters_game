#include <cassert>
#include <iostream>

template <class Tbase>    
void ArbolGeneral<Tbase>::destruir(nodo * n){
	if(n!=NULL){
		if(n->drcha!=NULL){
			destruir(n->drcha);	
		}if(n->izqda!=NULL){
			destruir(n->izqda);
		}
		delete &(n->etiqueta);
		n = NULL;
	}	
}

template <class Tbase>  
void ArbolGeneral<Tbase>::copiar(nodo *& dest, nodo * orig){
	nodo* nuevo = new nodo;	
	nuevo->drcha=NULL;
	nuevo->izq=NULL;
	nuevo->padre=NULL;
	nuevo->etiqueta=orig->etiqueta;
	if(orig->drcha!=NULL){
		copiar(nuevo->izqda,orig->izqda);
	}
	if(orig->izqda!=NULL){
		copiar(nuevo->drcha,orig->drcha);
	}
	dest=&nuevo;
}

template <class Tbase>      
int ArbolGeneral<Tbase>::contar(const nodo * n) const{
	int cuenta=1;
	if(n!=NULL){	
		cuenta+=contar(n->izqda);
		cuenta+=contar(n->drcha);
	}else
		return 0;
	return cuenta;
}

template <class Tbase>   
bool ArbolGeneral<Tbase>::soniguales(const nodo * n1, const nodo * n2) const{
	bool iguales=false;
	if(n1==NULL||n2==NULL){
		iguales=(n1==NULL)&&(n2==NULL);
	}else if(n1->etiqueta==n2->etiqueta){
		iguales=soniguales(n1->drcha,n2->drcha) && soniguales(n1->izqda,n2->izqda);
	}
return iguales;
}

template <class Tbase>
void ArbolGeneral<Tbase>::escribe_arbol(std::ostream& out, nodo * nod) const{
	if(nod==NULL){
		out << "x,";
	}else{
		out << "n " << nod->etiqueta << ", " ;
	}
	escribe_arbol(out,nod->izqda);
	escribe_arbol(out,nod->drcha);
}


template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(){
	laraiz = NULL;
}

template <class Tbase>   
ArbolGeneral<Tbase>::ArbolGeneral(const Tbase& e){
	laraiz = new nodo;
	laraiz->padre = NULL;
	laraiz->izqda = NULL;
	laraiz->drcha = NULL;
	laraiz->etiqueta = e ; 
}

template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral (const ArbolGeneral<Tbase>& v){
	copiar(&laraiz,v.laraiz);
}

template <class Tbase>
ArbolGeneral<Tbase>::~ArbolGeneral(){
	destruir(laraiz);
}

template <class Tbase>
ArbolGeneral<Tbase>& ArbolGeneral<Tbase>::operator = (const ArbolGeneral<Tbase> &v){
	if(this!=&v){
		destruir(laraiz);
		copiar(&laraiz,v.laraiz);
	}
}

template <class Tbase>
void ArbolGeneral<Tbase>::AsignaRaiz(const Tbase& e){
	destruir(laraiz);
	laraiz = new nodo;
	laraiz->padre = NULL;
	laraiz->izqda = NULL;
	laraiz->drcha = NULL;
	laraiz->etiqueta = e ; 
}

template <class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::raiz() const{
return laraiz;
}

template <class Tbase>
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::hijomasizquierda(const Nodo n) const{
return n->izqda;
}
  
template <class Tbase>  
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::hermanoderecha(const typename ArbolGeneral<Tbase>::Nodo n) const{
	Nodo aux = n;
	if(aux->drcha!=NULL){
		while(aux->drcha!=NULL){
			aux=aux->drcha;
		}
	}else
		aux=NULL;
return aux;
}
  
template <class Tbase>  
typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::padre(const typename ArbolGeneral<Tbase>::Nodo n) const{
	Nodo aux;
	if(n->padre!=NULL)
		aux=n->padre;
	else
		aux=NULL;
return aux;
}

template <class Tbase>
Tbase& ArbolGeneral<Tbase>::etiqueta(const typename ArbolGeneral<Tbase>::Nodo n){
return n->etiqueta;
}

template<class Tbase>   
const Tbase& ArbolGeneral<Tbase>::etiqueta(const typename ArbolGeneral<Tbase>::Nodo n) const{
	const Tbase ret = n->etiqueta;
return ret;
}

template <class Tbase>
void ArbolGeneral<Tbase>::asignar_subarbol(const ArbolGeneral<Tbase>& orig, const typename ArbolGeneral<Tbase>::Nodo nod){
	destruir(laraiz);
	copiar(laraiz, nod);
}
    
template <class Tbase>
void ArbolGeneral<Tbase>::podar_hijomasizquierda(typename ArbolGeneral<Tbase>::Nodo n, ArbolGeneral<Tbase>& dest){
	destruir(dest.laraiz);
	Nodo aux = n->izqda;
	if(n->izqda!=NULL){
		n->izqda=n->izqda->drcha;
		aux->drcha = NULL;
		aux->padre = NULL;
	}else{
		dest.laraiz=aux;
	}
}

template <class Tbase>
void ArbolGeneral<Tbase>::podar_hermanoderecha(typename ArbolGeneral<Tbase>::Nodo n, ArbolGeneral<Tbase>& dest){
	destruir(dest.laraiz);	
	Nodo aux = n->drcha;
	if(n->drcha!=NULL){
		n->drcha=n->drcha->drcha;
		aux->padre = NULL;
		aux->drcha = NULL;
	}else
		dest.laraiz=NULL;
}

template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hijomasizquierda(typename ArbolGeneral<Tbase>::Nodo n, ArbolGeneral<Tbase>& rama){
	rama.laraiz->drcha = n->izqda;
	rama.laraiz->padre = n;
	n->izqda = rama.laraiz;
	rama.laraiz = NULL;
}

template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& rama){
	rama.laraiz->drcha = n->drcha;
	rama.laraiz->padre = n->padre;
	n->drcha = rama.laraiz;
	rama.laraiz = NULL;
}
 
template <class Tbase>   
void ArbolGeneral<Tbase>::clear(){
	destruir(laraiz);
}

template <class Tbase>
int ArbolGeneral<Tbase>::size() const{
return contar(laraiz);
}

template <class Tbase>
bool ArbolGeneral<Tbase>::empty() const{
return (laraiz == NULL);
}

template <class Tbase>
bool ArbolGeneral<Tbase>::operator == (const ArbolGeneral<Tbase>& v) const{
return soniguales(this->laraiz,v.laraiz);
}

template <class Tbase>
bool ArbolGeneral<Tbase>::operator != (const ArbolGeneral<Tbase>& v) const{
return !(soniguales(this->laraiz,v.laraiz));
}

template<class Tbase>
std::ostream& operator<< (std::ostream& out, const ArbolGeneral<Tbase>& v){
	escribe_arbol(out,v.laraiz);
return out;
}
		template<class Tbase>
	 	ArbolGeneral<Tbase>::iter_preorden::iter_preorden(){
			it = NULL;
			raiz = NULL;
			level = 0;
		}

		template<class Tbase>
	 	Tbase & ArbolGeneral<Tbase>::iter_preorden::operator*(){
		return it->etiqueta ;
		}
	 
		template<class Tbase>
		int ArbolGeneral<Tbase>::iter_preorden::getlevel()const{
		return level;
		}

		template<class Tbase>
		typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::iter_preorden::Elem(){
		return it;
		}

		template<class Tbase>
	 	typename ArbolGeneral<Tbase>::iter_preorden& ArbolGeneral<Tbase>::iter_preorden::operator ++(){
			if(it->izqda!=NULL){
				it = it->izqda;
				level = level + 1;
			}else if(it->drcha!=NULL){
				it = it->drcha;
			}else{
				while(it->drcha==NULL && it->padre!=NULL){
					it = it->padre;
					level--;
				}
				if(it->drcha==NULL){
					it = NULL;
				}else{
					it = it->drcha;
				}
			}
		return *this;
		}

		template<class Tbase>
		bool ArbolGeneral<Tbase>::iter_preorden::operator == (const iter_preorden &i){
			bool iguales;
			iguales = (i.raiz==this->raiz) && (i.it==this->it);
		return iguales;
		}

		template<class Tbase>
		bool ArbolGeneral<Tbase>::iter_preorden::operator != (const iter_preorden &i){
			bool diferentes;
			diferentes = !((i.raiz==this->raiz) && (i.it==this->it));
		return diferentes;
		}

		template<class Tbase>
		ArbolGeneral<Tbase>::const_iter_preorden::const_iter_preorden(){
			it = NULL;
			raiz = NULL;
			level = 0;
		}
		
		template<class Tbase>
	 	const Tbase& ArbolGeneral<Tbase>::const_iter_preorden::operator*(){
		return it->etiqueta;
		}
	
		template<class Tbase>
		typename ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::const_iter_preorden::Elem(){
		return it;
		}

		template<class Tbase>
		int ArbolGeneral<Tbase>::const_iter_preorden::getlevel()const{
			return level;
		}

		template<class Tbase>
   	 	typename ArbolGeneral<Tbase>::const_iter_preorden & ArbolGeneral<Tbase>::const_iter_preorden::operator ++(){
			if(it->izqda!=NULL){
				it = it->izqda;
				level = level + 1;
			}else if(it->drcha!=NULL){
				it = it->drcha;
			}else{
				while(it->drcha==NULL && it->padre!=NULL){
					it = it->padre;
					level--;
				}
				if(it->drcha==NULL){
					it = NULL;
				}else{
					it = it->drcha;
				}
			}
		return *this;
		}
	    
	 	template<class Tbase>
		bool ArbolGeneral<Tbase>::const_iter_preorden::operator == (const const_iter_preorden &i){
			bool iguales;
			iguales = (i.raiz==this->raiz) && (i.it==this->it);
		return iguales;
		}
		 
   		template<class Tbase>
	 	bool ArbolGeneral<Tbase>::const_iter_preorden::operator != (const const_iter_preorden &i){
			bool diferentes;
			diferentes = !((i.raiz==this->raiz) && (i.it==this->it));
		return diferentes;
		}
	 

    	template<class Tbase>
		typename ArbolGeneral<Tbase>::iter_preorden ArbolGeneral<Tbase>::begin() const{
			iter_preorden beg;
			beg.it = laraiz;
			beg.raiz = laraiz;
			beg.level = 0;
		return beg;
		}

		template<class Tbase>
		typename ArbolGeneral<Tbase>::const_iter_preorden ArbolGeneral<Tbase>::el_begin()const{
			const_iter_preorden aux;
			aux.it = laraiz;
			aux.raiz = laraiz;
			aux.level = 0;
		return aux;
		}	
         
		template<class Tbase>
     	typename ArbolGeneral<Tbase>::iter_preorden ArbolGeneral<Tbase>::end() const{
			iter_preorden end;
			end.it = NULL;
			end.raiz = laraiz;
			end.level = 0;		
		return end;
		}

		template<class Tbase>
     	typename ArbolGeneral<Tbase>::const_iter_preorden ArbolGeneral<Tbase>::el_end()const{
			const_iter_preorden aux;
			aux.it = NULL;
			aux.raiz = laraiz;
			aux.level = 0;

		return aux;
		}
