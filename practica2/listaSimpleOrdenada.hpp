/*! 
  \file     listaSimpleOrdenada.hpp
  \brief    Representa la lista de nodos simulando el objeto list de la stl.
  \author   Teófilo Rojas Mata
  \date     10/04/2016
*/

#ifndef __LISTA_SIMPLE_ORDENADA_HPP
#define __LISTA_SIMPLE_ORDENADA_HPP

#include <cassert>
#include "nodo.hpp"
#include "donante.hpp"

namespace ed{
	//!  Definición de la plantilla de la clase ListaSimpleOrdenada
	class ListaSimpleOrdenada{
		//! \name Atributos privados de la clase ListaSimpleOrdenada{una cabeza y el número de elementos}
		private:
			Nodo * cabeza_;
			int nEle_;

		//! \name Métodos públicos de la clase ListaSimpleOrdenada
		public: 
	        //! \name Constructores de la clase ListaSimpleOrdenada
	        /*! 
	        \brief Constructor que crea una lista con una cabeza y el número de elementos inicializado a 0
	        \attention Función sobrecargada con Constructor de copia        
	        \note Los parámetros no tienen valores por defecto
	        \param x valor por referencia tipo Donante.
	        \pre Ninguna
	        \post Ninguna
	        */ 
			ListaSimpleOrdenada(Donante &x){
				cabeza_ = new Nodo (x);
				nEle_ = 0;
			}

	        /*! 
	            \brief Constructor de "copia" que crea una ListaSimpleOrdenada a partir de otra
	            \attention Función sobrecargada de Constructor       
	            \pre La lista debe existir
	            \post Ninguna
	        */        
			ListaSimpleOrdenada(){
				cabeza_ = NULL;
				nEle_ = 0;
			}

	        /*! 
	            \brief Inserta un nuevo nodo en la lista, ordenado alfabéticamente atendiendo a los datos del donante.
	            \param x de tipo Donante por referencia
	            \pre El Donante debe existir
	            \post Ninguna
	            \sa insertarElemento()
	        */ 
			void insertarElemento(Donante &x){
				Nodo * nuevo = new Nodo (x);

				if(estaVacia())
					cabeza_ = nuevo;									//Si la lista está vacía, el nodo creado va a ser la cabeza de la lista.


				else{
					Nodo *aux = cabeza_;
					Nodo *ant = cabeza_;
					bool encontrado = false;
																		//INSERTAR ORDENADO ALFABÉTICAMENTE
					if(nuevo->getData() <= aux->getData()){				//El nuevo nodo pasa a ser la cabeza y apunta a la anterior cabeza.
						nuevo->setNext(aux);							//El nuevo nodo pasa a ser el primero de la lista(cabeza).
						cabeza_ = nuevo;					
					}

					else{												//Si el nuevo nodo NO es lexicográficamente menor que el primero(va detrás):
						while(aux && !encontrado){ 						//Mientras que haya nodos y el nodo nuevo no encuentre su sitio:
							if(nuevo->getData() <= aux->getData())		//Si el nuevo nodo va antes que el siguiente a comparar, ha encontrado su sitio.
								encontrado = true;

							else{										//Si no, avanza de posición.
								ant = aux;
								aux = aux->next();
							}


						}
						ant->setNext(nuevo);							//Como ha encontrado su sitio, el que tenía detrás ahora apunta al nuevo.
						nuevo->setNext(aux);							//El nuevo ahora apunta al siguiente.
					}
					
				}

				nEle_ ++;												//Al insertar aumenta el número de nodos en la lista.(cantidad de donantes)
			}

	        /*! 
	            \brief Devuelve el número de nodos en lista.
	            \pre La lista debe existir
	            \post Ninguna
	            \sa tamanio()
	        */ 
			inline int tamanio(){ return nEle_; }

	        /*! 
	            \brief Devuelve si la lista está vacía
	            \pre La lista debe existir
	            \post Ninguna
	            \sa estaVacia()
	        */ 
			bool estaVacia() const{
				if(cabeza_ == 0)
					return true;
				else
					return false;
			}

	        /*! 
	            \brief Busca un elemento en la lista
	            \pre La lista debe existir
	            \post Ninguna
	            \sa findItem()
	        */ 
			int findItem(Donante D){ 									// Al principio la hice igual que en las diapos, pasándole tb una posición, pero como no le ví el sentido, se lo he quitado. EXPLICARMELO PORFA.
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

	        /*! 
	            \brief Devuelve si la posición pasada es válida
	            \pre La lista debe existir
	            \post Ninguna
	            \sa isValid()
	        */ 
			bool isValid(int pos) const {
				if(pos <= nEle_)
					return true;
				return false;				
			}

	        /*! 
	            \brief Devuelve si el nodo es el último en la lista
	            \pre La lista debe existir
	            \post Ninguna
	            \sa isLast()
	        */ 
			bool isLast(int pos){
				if(pos == nEle_)
					return true;
				return false;
			}

	        /*! 
	            \brief Devuelve los datos del donante que contiene un nodo.
	            \pre La lista debe existir
	            \post Ninguna
	            \sa item()
	        */ 
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

	        /*! 
	            \brief Elimina un nodo en la lista.
	            \pre La lista debe existir
	            \post Ninguna
	            \sa delPosicion()
	        */ 
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
