#ifndef __DONANTES_HPP__
#define __DONANTES_HPP__

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <sstream> //para cazar las líneas del fichero
#include "donantesinterfaz.hpp"
#include "donante.hpp"
#include "listaSimpleOrdenada.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;
using std::ofstream;

namespace ed{
	class Donantes: public DonantesInterfaz {
		private:
			ListaSimpleOrdenada lista_;

		public:
			Donantes(){} //¿Qué quiere que recibamos aquí?
			
			bool comprobar() const{
				return lista_.estaVacia();
			}

			bool buscarDonante(Donante &D){ //buscar un donante para añadirle el factor y el grupo
				int cont = 0;

				while(!lista_.isLast(cont)){
					if(lista_.item(cont) == D){
						D = lista_.item(cont);
						return true;
					}
					cont++;
				}
				return false;
			}

			void insertarDonante(Donante &D){

				if(lista_.estaVacia()){
					lista_.insertarElemento(D);
				}

				else{
					int cont = 0;
					bool encontrado = false;

					while(not lista_.isLast(cont) && !encontrado){
						if(lista_.item(cont) == D)
							encontrado = true;

						cont++;
					}

					if(encontrado == false){
						lista_.insertarElemento(D);
					}
				}
				

			}

			void mostrarDatos(){
				int cont = 0; Donante D;
				while(not lista_.isLast(cont)){ 
					D = lista_.item(cont);
					cout << D;
					cont++;
				}
			}

			bool cargarBBDD(string nombreFichero){
				Donante D;
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

						insertarDonante(D); 
					}

					bbddEntrada.close(); 
				}
				return true;
			}

			void guardarBBDD(string nombreFichero){
				
				ofstream bbddSalida(nombreFichero.c_str()); 

				int cont = 0; Donante data;
				while(not lista_.isLast(cont)){
				data=lista_.item(cont); 
					bbddSalida 	<< data.getApellidos() << ";" 
								<< data.getNombre() << ";"
								<< data.getGrupo() << ";"
								<< data.getFactor() << "\n";
					cont++;
				}
	

				bbddSalida.close(); 
			}

			bool estaVacia() const{
				return lista_.estaVacia();
			}
/*
			Donantes(const Donante &x){
				cabeza_ = new Nodo(x);e
				cursor_ = new Nodo(x);
			}

			Donantes(){
				cabeza_ = cursor_ = NULL;
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
*/
	};

}

#endif