#ifndef __DONANTES_HPP__
#define __DONANTES_HPP__

#include <iostream>
#include <string>
#include "donantesinterfaz.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace ed{
template <class G>
	struct Nodo{
		G data;
		Nodo *sig;
		Nodo(const G &x){
			data = x;
			sig = 0;
		}
	};

template <class G>
	class Donantes: public DonantesInterfaz <G>{
		private:
			Nodo <G> *cabeza_;
			Nodo <G> *cursor_;

		public:
			bool estaVacia() const{
				if(*cabeza_ == 0)
					return true;
				else
					return false;
			}

			void insertar(const G &x){
				Nodo <G> * nuevo = new Nodo <G> (x);

				if(estaVacia())
					cursor_ = cabeza_ = nuevo;

				else{
					Nodo <G> *aux = cabeza_;
					Nodo <G> *ant;
					bool encontrado = false;
					if(nuevo->data <= aux->data){//El nodo a insertar va a ser la cabeza
						nuevo->sig = aux;
						cursor_ = cabeza_ = nuevo;
					}

					else{
						while(aux && !encontrado){ //Se recorre mientras no llegue al final y no lo encuentro
							if(nuevo->data <= aux->data)
								encontrado = true;

							else{
								ant = aux;
								aux = aux->sig;
							}

						}
						ant->sig = nuevo;
						nuevo->sig = aux;
						cursor_ = nuevo;
					}
				}
			}

			bool buscar(G &x){
				assert(! estaVacia());
				Nodo <G> *aux = cabeza_;
				bool encontrado = false;
				while(aux && !encontrado){
					if(x == aux->data){
						x = aux->data;
						encontrado = true;
						cursor_ = aux;
					}

					else if(x <= aux->data) //Si no lo encuentra, no vamos a buscar por encima, factor eficiencia; la lista tiene que estar ordenada obviamente.
						return false;

					else
						aux = aux->sig;
				}
				return encontrado;
			}

			void leerDatos(){
				G D;
				bool encontrado;
				string opcion;

				do{
					cin >> D;
					if(estaVacia())
						insertar(D);

					else{
						encontrado = buscar(D);

						if(!encontrado)
							insertar(D);

						else
							cout << "El donante introducido ya está en la lista" << endl;

						cout << "Introduzca S para salir, cualquier otra tecla para introduzir otro donante." << endl;
						cin >> opcion;
					}

				}while(opcion != "S");

			}

			void mostrarDatos(){
				Nodo <G> *aux = cabeza_;
				while(aux){
					cout << aux->data;
					aux = aux->sig;
				}
			}

	};

}

#endif