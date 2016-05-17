/*! 
  \file     grafo.hpp
  \brief    Grafo representa la clase Grafo definida para hacer los Grafos con la matriz de adyacencia
  \author   Teófilo Rojas Mata
  \date     16/05/2016
*/

#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__
/*! 
 \brief Simulación de distancias rellenas al máximo para inicializar la matriz
 \sa INFINITO
*/   
#define INFINITO 999999

#include <vector>
#include <iostream>
#include <cassert>
#include <limits>
#include "vertice.hpp"
#include "lado.hpp"

/*!
   \brief Parte necesiara de espacio de nombres para la asignatura de Estructura de datos.
*/
using std::vector;
using std::string;

//!  Espacio de nombre creado para las prácticas de la asignatura de Estructura de Datos.
namespace ed{
    //!  Definición de la clase Grafo
	class Grafo{
		private:
	        //! \name Atributos privados de la clase Grafo (v_, matriz_, dirigido_, a_, b_ numVertices_, numLados_, tamanio_)
			vector<Vertice> v_; 								//aquí van todas las ciudades
			double **matriz_; 									//Matriz de adyacencia
			bool dirigido_; 									//bandera de dirigido o no
			int a_;												//cursor para los vértices 
			int b_;												//cursor para los lados
			int numVertices_;									//numero de vértices
			int numLados_;										//numero de lados
			int tamanio_;										//capacidad del grafo

	    //! \name Métodos públicos de la clase Grafo     	
		public:
            //! \name Constructores de la clase Grafo
            /*! 
            \brief Constructor que crea una matriz de adyacencia inicializada a infinito y obtiene los datos del grafo
            \note Los parámetros tienen valores por defecto
            \param tam valor por defecto 0
            \param dirigido valor por defecto true
            \post Ninguna
            \sa Grafo()
            */ 
			Grafo(int tam = 0, bool dirigido = true){
				if(tam < 0)
					tam = 0;
				matriz_ = new double *[tam];					//Inicio reserva de memoria para matriz

				for(int i = 0; i < tam; i++){					//Inicializo matriz a valor infinito
					matriz_[i] = new double [tam];
					for(int j = 0; j < tam; j++){
						matriz_[i][j] = INFINITO;
					}
				}

				numVertices_ = 0;	
				numLados_ = 0;
				tamanio_ = tam;
				dirigido_ = dirigido;
			}

           	//! \name Funciones de obtención de datos de Grafo
            /*! 
                \brief Devuelve el número de vertices de un grafo
                \return componente numVertices_ del Grafo
                \pre El Grafo debe existir
                \post Ninguna
                \sa getNumV()
            */	
			inline int getNumV() const { return numVertices_; }

            /*! 
                \brief Devuelve el número de lados de un grafo
                \return componente numLados_ del Grafo
                \pre El Grafo debe existir
                \post Ninguna
                \sa getNumL()
            */				
			inline int getNumL() const { return numLados_; }

            /*! 
                \brief Devuelve el tamaño de un grafo
                \return componente tamanio_ del Grafo
                \pre El Grafo debe existir
                \post Ninguna
                \sa getTam()
            */				
			inline int getTam() const { return tamanio_; }

            /*! 
                \brief Devuelve el si el grafo es dirigido o no
                \return componente dirigido_ del Grafo
                \pre El Grafo debe existir
                \post Ninguna
                \sa getDiri()
            */				
			inline bool getDiri() const { return dirigido_; }

            /*! 
                \brief Devuelve si el grafo está vacío o no
                \return componente condición de vacío
                \pre El Grafo debe existir
                \post Ninguna
                \sa estaVacio()
            */			
			inline bool estaVacio() const { return getNumV() == 0 && getNumL() == 0; }

            /*! 
                \brief Comprueba si dos vértices son adyacentes o no
                \return componente distancia
                \pre El Grafo debe existir
                \post Ninguna
                \sa adyacencia()
            */			
			inline double adyacencia(Vertice &U, Vertice &V){ 	//Comprueba si dos vertices son adyacentes (INFINITO o no)
				assert(V.getLabel() < numVertices_);			//Recibes dos vertices, si con sus posiciones en la matriz el valor es menor que infinito, es que sí existen.
				assert(U.getLabel() < numVertices_);
				return matriz_[U.getLabel()][V.getLabel()];
			} 

            /*! 
                \brief Comprueba si la posición del vertice está dentro del rango
                \return componente bool
                \pre El Grafo debe existir
                \post Ninguna
                \sa verticeCorrecto()
            */					
			inline bool verticeCorrecto(){
				if(a_ < getNumV())
					return true;
				return false;
			}

            /*! 
                \brief Comprueba si la posición del vertice está dentro del rango
                \return componente bool
                \pre El Grafo debe existir
                \post Ninguna
                \sa verticeCorrecto()
            */				
			inline bool ladoCorrecto(){
				if(b_ < getNumV())
					return true;
				return false;
			}

            /*! 
                \brief Obtiene la posición actual del vertice
                \return posición actual
                \pre El Grafo debe existir
                \post Ninguna
                \sa verticeActual()
            */				
			inline Vertice verticeActual(){
				assert(verticeCorrecto());						//Comprueba que el valor privado de la posición sea correcto
				return v_[a_];
			}

            /*! 
                \brief Obtiene el Lado actual
                \return Lado actual
                \pre El Grafo debe existir
                \post Ninguna
                \sa ladoActual()
            */			
			inline Lado ladoActual(){
				assert(ladoCorrecto());
				Lado L;
				L.setDistancia(matriz_[a_][b_]);				//Rellena la distancia que hay entre dos nodos en la matriz de adyacencia
				L.setInicio(v_[a_]);							//Rellena el primer nodo
				L.setFin(v_[b_]);								//Rellena el último nodo
				return L;
			} 

            /*! 
                \brief Obtiene la posición actual del vertice
                \return posición actual
                \pre El Grafo debe existir
                \post Ninguna
                \sa VerticeActual()
            */

            //! \name Funciones de modificación de Lado
            /*! 
                \brief Asigna un valor "true" a la variable privada "dirigido_" de un Grafo
                \pre El grafo debe existir
                \post Ninguna
                \sa setDirecto()
            */                
			inline void setDirecto(){ dirigido_ = true; }

            /*! 
                \brief Asigna un valor "false" a la variable privada "dirigido_" de un Grafo
                \pre El grafo debe existir
                \post Ninguna
                \sa setIndirecto()
            */     
			inline void setIndirecto(){ dirigido_ = false; }

            /*! 
                \brief añade un Vertice al grafo
                \param nombre de tipo string
                \pre El Grafo debe existir
                \post Ninguna
                \sa aniadeVertice()
            */
			inline void aniadeVertice(string nombre){
				Vertice V;
				V.setData(nombre);								//Mete el nombre al vertice
				V.setLabel(numVertices_);						//Mete la posición al vertice
				numVertices_++;									//acctualiza contadores
				numLados_++;
				v_.push_back(V);								//insertalo en el vector/grafo
			}

            /*! 
                \brief añade un Lado al grafo
                \param U de tipo Vertice
                \param V de tipo Vertice                                
                \param distancia de tipo double                
                \pre El Grafo debe existir
                \post Ninguna
                \sa aniadeLado()
            */
			inline void aniadeLado(Vertice U, Vertice V, double distancia){		
				matriz_[U.getLabel()][V.getLabel()] = distancia;
				if(!dirigido_)									//Si el grafo no es dirigido, en la otra dirección tiene la misma distancia
					matriz_[V.getLabel()][U.getLabel()] = distancia;
			}

            /*! 
                \brief Lleva el cursor de vertices a la posición de la ciudad pasada
                \param ciudad tipo string
                \pre El Grafo debe existir
                \post Ninguna
                \sa buscarVertice()
            */
			inline bool buscarVertice(string ciudad){			
				bool encontrado = false;
				for(int i = 0; i < numVertices_ && encontrado == false; i++){
					if(v_[i].getData() == ciudad){				//Si existe:
						a_ = i;									//posicionate en su posición
						encontrado = true;						//indica que lo ha encontrado
					}
				}
				return encontrado;
			}

            /*! 
                \brief Se posiciona en un vértice de la matriz
                \param V tipo Vertice
                \pre El Grafo debe existir
                \post Ninguna
                \sa irA()
            */
			inline void irA(Vertice &V){						//Se posiciona en un vértice de la matriz
				bool encontrado = false;
				for(int i = 0; i < numVertices_ && encontrado == false; i++){
					if(v_[i] == V){								//si existe:
						a_ = i;									//vete a su posición
						encontrado = true;						//indica que lo ha encontrado
					}
				}				
			}

            /*! 
                \brief Se posiciona en un vértice de la matriz.
                \attention sobrecargado de la función irA.
                \param pos tipo int
                \pre El Grafo debe existir
                \post Ninguna
                \sa irA()
            */
			inline void irA(int pos){
				bool encontrado = false;						//identica a la anterior
				for(int i = 0; i < numVertices_ && encontrado == false; i++){
					if(v_[i].getLabel() == pos){
						a_ = i;
						encontrado = true;
					}
				}					
			}

            /*! 
                \brief Busca un lado y posiciona los cursores en su sitio
                \param U tipo Vertice          
                \param V tipo Vertice
                \pre El Grafo debe existir
                \post Ninguna
                \sa buscarLado()
            */
			inline void buscarLado(Vertice &U, Vertice &V){		//Pone el cursor en el lado referenciado
				assert(V.getLabel() < numVertices_);
				assert(U.getLabel() < numVertices_);
				bool encontrado = false;
				a_ = U.getLabel();
				b_ = V.getLabel();
			}

            /*! 
                \brief Se va a la posición 0 de vertices
                \pre El Grafo debe existir
                \post Ninguna
                \sa posicionaVerticeCero()
            */
			inline void posicionaVerticeCero(){					//Actualiza la posición al primer vértice
				a_ = 0;
			} 

            /*! 
                \brief Se va a la posición siguiente de vertices
                \pre El Grafo debe existir
                \post Ninguna
                \sa siguienteVertice()
            */
			inline void siguienteVertice(){						//Actualiza la posición del cursor al siguiente vértice.
				a_++;
			}

            /*! 
                \brief Bandera de aviso por si se sale del rango
                \pre El Grafo debe existir
                \post Ninguna
                \sa sobrepasaLosVertices()
            */
			inline bool sobrepasaLosVertices(){ 				//Comprueba si el cursor ha sobrepasado la última posición válida
				return a_ == numVertices_;
			}

            /*! 
                \brief Lleva el cursor al primer lado
                \param V tipo Vertice                      
                \pre El Grafo debe existir
                \post Ninguna
                \sa beginEdge()
            */
			inline void beginEdge(Vertice &V){					//Lleva el cursor al primer vértice del lado recibido
				a_ = V.getLabel();
				b_ = 0;
				while(matriz_[a_][b_] == INFINITO && !sobrepasaLosLados()){
					b_++;
				}
			}

           /*! 
                \brief Lleva el cursor al siguiente lado
                \pre El Grafo debe existir
                \post Ninguna
                \sa siguienteLado()
            */
			inline void siguienteLado(){						//Devuelve el siguiente lado del cursor que tiene valor válido
				b_++;
				while(matriz_[a_][b_] == INFINITO && !sobrepasaLosLados()){
					b_++;
				}
			}

            /*! 
                \brief Bandera de aviso por si se sale del rango
                \pre El Grafo debe existir
                \post Ninguna
                \sa sobrepasaLosLados()
            */
			inline bool sobrepasaLosLados(){					//Comprueba si el cursor ha sobrepasado la última posición válida
				return b_ == numLados_;
			}

	};
}

#endif