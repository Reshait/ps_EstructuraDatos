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

			inline int tamanio(){ return nEle_; }

			bool estaVacia() const{
				if(cabeza_ == 0)
					return true;
				else
					return false;
			}

			int findItem(Donante D){ // busca un elemento a partir de una posición y devuelve su posición o -1
				int cont = 0;
				Nodo * aux = cabeza_;
				
				while(aux){
					
					if(aux->getData() == D)
						return cont;
								
					cont++;
					aux = aux->next();
				}

				return -1;
			}

			bool isValid(int pos) const {
				//assert(pos < 0);
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
				Donante D;

				Nodo *aux = cabeza_;
				while(aux){
					if(cont == pos){
						D = aux->getData();
					}
					cont++;
					aux = aux->next();
				}
				return D;

			}

			void delPosicion(int pos){
				assert(!estaVacia());
				assert(isValid(pos));
				Nodo *aux = cabeza_;
				int cont = 0;

				if(pos == 0){
					cabeza_ = cabeza_->next();
					delete aux;
				}

				else{
					Nodo * ant;
					bool enc = false;

					while(aux && !enc){

						if(cont == pos)
							enc = true;

						else{
							ant = aux;
							cont++;
							aux = aux->next();
						}
					}

					ant->setNext(aux->next());
					delete aux;
				}

				nEle_--;
			}


	};
}

#endif
