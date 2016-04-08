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

			void insertarDonante(Donante &D){			//Para controlar que no se insertan repetidos se hace:

				if(lista_.estaVacia()){
					lista_.insertarElemento(D);			//Si la lista está vacía, insértalo sin miramientos.
				}

				else{
					int cont = 0;
					bool encontrado = false;

					while(!lista_.isLast(cont) && !encontrado){ 	//Mientras que no sea el último nodo y no se haya encontrado.
						if(lista_.item(cont) == D)		//Si lo encuentra en la posición cont marca que se ha encontrado.		
							encontrado = true;

						cont++;
					}

					if(encontrado == false){ 			//Si no lo ha encontrado en la lista, insértalo.
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

			bool delDonante(Donante D){
				int pos = lista_.findItem(D);

				if(pos != -1){
					lista_.delPosicion(pos);
					return true;
				}

				return false;
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

			Donante devuelveDatosDonante(Donante D){ //Para buscar un donante de la lista y devolverlo con todos sus valores
				int cont = 0;

				while(!lista_.isLast(cont)){
					if(lista_.item(cont) == D)
						D = lista_.item(cont);

					cont++;
				}
				return D;				
			}


	};

}

#endif
