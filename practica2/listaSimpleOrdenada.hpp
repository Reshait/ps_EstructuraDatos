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

				if(estaVacia())
					cabeza_ = nuevo;						//Si la lista está vacía, el nodo creado va a ser la cabeza de la lista.


				else{
					Nodo *aux = cabeza_;
					Nodo *ant = cabeza_;
					bool encontrado = false;
													//INSERTAR ORDENADO ALFABÉTICAMENTE
					if(nuevo->getData() <= aux->getData()){				//El nuevo nodo pasa a ser la cabeza y apunta a la anterior cabeza.
						nuevo->setNext(aux);					//El nuevo nodo pasa a ser el primero de la lista(cabeza).
						cabeza_ = nuevo;					
					}

					else{								//Si el nuevo nodo NO es lexicográficamente menor que el primero(va detrás):
						while(aux && !encontrado){ 				//Mientras que haya nodos y el nodo nuevo no encuentre su sitio:
							if(nuevo->getData() <= aux->getData())		//Si el nuevo nodo va antes que el siguiente a comparar, ha encontrado su sitio.
								encontrado = true;

							else{						//Si no, avanza de posición.
								ant = aux;
								aux = aux->next();
							}


						}
						ant->setNext(nuevo);					//Como ha encontrado su sitio, el que tenía detrás ahora apunta al nuevo.
						nuevo->setNext(aux);					//El nuevo ahora apunta al siguiente.
					}
					
				}
				nEle_ ++;								//Al insertar aumenta el número de nodos en la lista.(cantidad de donantes)
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
