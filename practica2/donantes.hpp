#ifndef __DONANTES_HPP__
#define __DONANTES_HPP__

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <sstream> //para cazar las líneas del fichero
#include "donantesinterfaz.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;

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
				if(cabeza_ == 0)
					return true;
				else
					return false;
			}

			void insertarElemento(const G &x){
				Nodo <G> * nuevo = new Nodo <G> (x);

				if(estaVacia())
					cursor_ = cabeza_ = nuevo;

				else{
					Nodo <G> *aux = cabeza_;
					Nodo <G> *ant;
					bool encontrado = false;
					//El nodo a insertar va a ser la cabeza
					if(nuevo->data <= aux->data){
						nuevo->sig = aux;
						cursor_ = cabeza_ = nuevo;
					}

					else{
						//Se recorre mientras no llegue al final y no lo encuentro
						while(aux && !encontrado){ 
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

			bool buscarElemento(G &x){
				assert(! estaVacia());
				Nodo <G> *aux = cabeza_;
				bool encontrado = false;
				while(aux && !encontrado){
					if(x == aux->data){
						x = aux->data;
						encontrado = true;
						cursor_ = aux;
					}
					//Si no lo encuentra, no vamos a buscar por encima, factor eficiencia; la lista tiene que estar ordenada obviamente.
					else if(x <= aux->data) 
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
						insertarElemento(D);

					else{
						encontrado = buscarElemento(D);

						if(!encontrado)
							insertarElemento(D);

						else
							cout << "El donante introducido ya está en la lista" << endl;

						cout << "Introduzca S/s para salir, cualquier otra tecla para introduzir otro donante." << endl;
						cin >> opcion;
					}

				}while(opcion != "S" && opcion != "s");

			}

			void mostrarDatos(){
				Nodo <G> *aux = cabeza_;
				while(aux){
					cout << aux->data;
					aux = aux->sig;
				}
			}

			bool cargarBBDD(string nombreFichero){
				G D;
				string linea, apellidos, nombre, grupo, factor;

				ifstream bbddEntrada(nombreFichero.c_str());

				if(!bbddEntrada)
					return false;

				else{
					while (getline(bbddEntrada, linea))
					{
					    stringstream lineaCompleta(linea);

					    getline(lineaCompleta, apellidos, ';');
					    getline(lineaCompleta, nombre, ';');
					    getline(lineaCompleta, grupo, ';');
					    getline(lineaCompleta, factor, '\n');

						D.setApellidos(apellidos);
						D.setNombre(nombre);
						D.setGrupo(grupo);
						D.setFactor(factor);

						insertarElemento(D); 
					}

					bbddEntrada.close(); 
				}
	
				return true;

			}

	};

}

#endif