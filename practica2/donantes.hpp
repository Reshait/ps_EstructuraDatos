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
using std::ofstream;

namespace ed{
	template <class T>
	struct Nodo{
		T data;
		Nodo *sig;
		Nodo(const T &x){
			data = x;
			sig = 0;
		}
	};

	template <class T>
	class Donantes: public DonantesInterfaz <T>{
		private:
			Nodo <T> *cabeza_;
			Nodo <T> *cursor_;

		public:
			Donantes(const T &x){
				cabeza_ = new Nodo <T> (x);
				cursor_ = new Nodo <T> (x);
			}

			Donantes(){
				cabeza_ = cursor_ = NULL;
			}

			bool estaVacia() const{
				if(cabeza_ == 0)
					return true;
				else
					return false;
			}

			void insertarElemento(const T &x){
				Nodo <T> * nuevo = new Nodo <T> (x);

				if(estaVacia())
					cursor_ = cabeza_ = nuevo;

				else{
					Nodo <T> *aux = cabeza_;
					Nodo <T> *ant;
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

			bool buscarElemento(T &x){
				assert(! estaVacia());
				Nodo <T> *aux = cabeza_;
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
///////////////////////
			/*
			Nodo <T> &buscarNodo(T &x){
				assert(! estaVacia());
				Nodo <T> *aux = cabeza_;
				bool encontrado = false;

				while(aux && !encontrado){
					if(x == aux->data){
						x = aux->data;
						cursor_ = aux;
						encontrado = true;
						return aux->data;
					}

					else
						aux = aux->sig;
				}
				return 0;
			}

			void modificaDonante(T &x){
				T aux;
				T = buscarNodo(x)
				T.modificaDonante();
			}
			*/
////////////////////////
			void leerDatos(){
				T D;
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
				Nodo <T> *aux = cabeza_;
				while(aux){
					cout << aux->data;
					aux = aux->sig;
				}
			}

			bool cargarBBDD(string nombreFichero){
				T D;
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

			void guardarBBDD(string nombreFichero){
				Nodo <T> *aux = cabeza_;
				ofstream bbddSalida(nombreFichero.c_str()); 
	
				while(aux){
					bbddSalida 	<< aux->data.getApellidos() << ";" 
								<< aux->data.getNombre() << ";"
								<< aux->data.getGrupo() << ";"
								<< aux->data.getFactor() << "\n";
					aux = aux->sig;
				}

				bbddSalida.close(); 
			}

	};

}

#endif