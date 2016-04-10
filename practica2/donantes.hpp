/*! 
  \file     donantes.hpp
  \brief    Donante representa la calse donante definida por la interfaz donantesinterfaz.hpp
  \author   Teófilo Rojas Mata
  \date     10/04/2016
*/

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

/*!
   \brief Partes necesiaras de espacio de nombres para la asignatura de Estructura de datos.
*/
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;
using std::ofstream;

namespace ed{
	//!  Definición de la clase Donantes
	class Donantes: public DonantesInterfaz {
	    //! \name Atributo privado de la clase Donantes (lista)
		private:
			ListaSimpleOrdenada lista_;

		public:
			//! \name Constructor de la clase Donantes
	        /*! 
	        \brief Constructor que crea una lista de Donantes de tipo ListaSimpleOrdenada
	        \pre Ninguna
	        \post Ninguna
	        */ 
			Donantes(){} 

	        /*! 
	            \brief Comprueba si la lista está vacía.
	            \pre la lista existir
	            \post Ninguna
	            \sa comprobar()
	        */			
			bool comprobar() const{
				return lista_.estaVacia();
			}

	        /*! 
	            \brief inserta un objeto Donante en la lista
	            \param por referencia D, de tipo Donante
	            \pre El Donante debe existir
	            \post Ninguna
	            \sa insertarDonante()
	        */
			void insertarDonante(Donante &D){						//Para controlar que no se insertan repetidos se hace:

				if(lista_.estaVacia()){
					lista_.insertarElemento(D);						//Si la lista está vacía, insértalo sin miramientos.
				}

				else{
					int cont = 0;
					bool encontrado = false;

					while(!lista_.isLast(cont) && !encontrado){ 	//Mientras que no sea el último nodo y no se haya encontrado.
						if(lista_.item(cont) == D)					//Si lo encuentra en la posición cont marca que se ha encontrado.		
							encontrado = true;

						cont++;
					}

					if(encontrado == false){ 						//Si no lo ha encontrado en la lista, insértalo.
						lista_.insertarElemento(D);
					}
				}
				

			}

	        /*! 
	            \brief Muestra por pantalla la lista completa.
	            \pre La lista debe tener Donantes
	            \post Ninguna
	            \sa mostrarDatos()
	        */
			void mostrarDatos(){
				int cont = 0; Donante D;
				while(not lista_.isLast(cont)){ 
					D = lista_.item(cont);
					cout << D;
					cont++;
				}
			}

	        /*! 
	            \brief Carga la base de datos desde un fichero pasado por teclado.
	            \param nombreFichero de tipo string
	            \pre El Fichero debe existir.
	            \post Ninguna
	            \sa cargarBBDD()
	        */
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

	        /*! 
	            \brief Guarda la base de datos a un fichero pasado por teclado.
	            \param nombreFichero de tipo string
	            \post Ninguna
	            \sa guardarBBDD()
	        */
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

	        /*! 
	            \brief Devuelve si la lista está vacía.
	            \pre El Fichero debe existir.
	            \post Ninguna
	            \sa estaVacia()
	        */
			bool estaVacia() const{
				return lista_.estaVacia();
			}

	        /*! 
	            \brief elimina un Donante de la lista
	            \param D de tipo Donante
	            \pre El Donante debe existir.
	            \post Ninguna
	            \sa delDonante()
	        */
			bool delDonante(Donante D){
				int pos = lista_.findItem(D);

				if(pos != -1){
					lista_.delPosicion(pos);
					return true;
				}

				return false;
			}

	        /*! 
	            \brief busca un Donante de la lista.
	            \param D de tipo Donante por referencia.
	            \pre El Donante debe existir.
	            \post Ninguna
	            \sa buscarDonante()
	        */
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

	        /*! 
	            \brief Devuelve los datos de un donante para completarlo si se le pasa solo nombre y apellidos.
	            \param D de tipo Donante.
	            \pre El Donante debe existir.
	            \post Ninguna
	            \sa devuelveDatosDonante()
	        */
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
