#ifndef __LISTA_SIMPLE_ORDENADA_HPP
#define __LISTA_SIMPLE_ORDENADA_HPP

#include <cassert>
#include "nodo.hpp"
#include "donante.hpp"

namespace ed{
	class ListaSimpleOrdenada{
		private:
			Nodo * cabeza_;
			int nEle_;

		public: 
			ListaSimpleOrdenada(Donante &x){
				cabeza_ = new Nodo (x);
				nEle_ = 0;
			}

			ListaSimpleOrdenada(){
				cabeza_ = NULL;
				nEle_ = 0;
			}

			void insertarElemento(Donante &x){
				Nodo * nuevo = new Nodo (x);

				if(estaVacia()){
					cabeza_ = nuevo;
				
					cout<<"hola1"<<endl;
				}

				else{
					Nodo *aux = cabeza_;
					Nodo *ant = cabeza_;
					bool encontrado = false;
					//El nodo a insertar va a ser la cabeza
					if(nuevo->getData() <= aux->getData()){
						nuevo->setNext(aux);
						cabeza_ = nuevo;
						cout<<"hola2"<<endl;
					}

					else{
						//Se recorre mientras no llegue al final y no lo encuentro
						while(aux && !encontrado){ 
							if(nuevo->getData() <= aux->getData())
								encontrado = true;

							else{
								ant = aux;
								aux = aux->next();
							}

						}
						ant->setNext(nuevo);
						nuevo->setNext(aux);
						cout<<"hola3="<<endl;
					}
					
				}
					nEle_ ++;
			}

			bool estaVacia() const{
				if(cabeza_ == 0)
					return true;
				else
					return false;
			}

			int findItem(Donante D, int pos){ // busca un elemento a partir de una posición y devuelve su posición o -1
				assert(isValid(pos));
				int cont = 0;
				Nodo * aux = cabeza_;
				while(aux){
					if(pos <= cont){
						if(aux->getData() == D){
							return cont;
						}
					}
					cont++;
					aux->setNext(aux);
				}
				return -1;
			}

			bool isValid(int pos) const {
				if(pos <= nEle_)
					return true;
				return false;				
			}

			bool isLast(int pos){
				if(pos == nEle_)
					return true;
				return false;
			}

			Donante item(int pos){
				assert(isValid(pos));
				int cont = 0;
				Nodo *aux = cabeza_;
				while(aux){
					if(cont == pos){
						return aux->getData();
					}
					cont++;
					aux = aux->next();
				}
			}


	};
}

#endif