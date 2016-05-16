#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__
#define INFINITO 32000

#include <vector>
#include <iostream>
#include <cassert>
#include <limits>
#include "vertice.hpp"
#include "lado.hpp"

using std::vector;
using std::string;

namespace ed{
	class Grafo{
		private:
			vector<Vertice> v_; //aquí van todas las ciudades
			double **matriz_; 	//Matriz de adyacencia
			//mejor vector de vectores de float pq es más eficiente. vector<vector<double>> v_;
			bool dirigido_; 	//bandera de dirigido o no
			int a_;				//cursor para los vértices 
			int b_;				//cursor para los lados
			int numVertices_;	//numero de vértices
			int numLados_;		//numero de lados
			int tamanio_;		//capacidad del grafo

		public:
			Grafo(int tam = 0, bool dirigido = true){
				if(tam < 0)
					tam = 0;
<<<<<<< HEAD
				//matriz_ = new double *[tamanio_];				//Inicio reserva de memoria para matriz
//						tamanio_ = tam;
		
				//for(int i = 0; i < tam; i++)
				//	matriz_[i] = new double [tamanio_];			//Fin reserva de memoria para matriz

				for(int i = 0; i < tam; i++){					//Inicializo matriz a valor infinito
					matriz_[i] = new double [tamanio_];
=======
				matriz_ = new double *[tam];				//Inicio reserva de memoria para matriz

				for(int i = 0; i < tam; i++){					//Inicializo matriz a valor infinito
					matriz_[i] = new double [tam];
>>>>>>> 358f9c307c947eb3026ad04b4d55392bef7967f6
					for(int j = 0; j < tam; j++){
						matriz_[i][j] = INFINITO;
					}
				}

				numVertices_ = 0;	
				numLados_ = 0;
				dirigido_ = dirigido;
			}

			inline int getNumV() const { return numVertices_; }
			inline int getNumL() const { return numLados_; }
			inline int getTam() const { return tamanio_; }
			inline bool getDiri() const { return dirigido_; }
			inline bool estaVacio() const { return getNumV() == 0 && getNumL() == 0; }
			inline double adyacencia(Vertice &U, Vertice &V){ 	//Comprueba si dos vertices son adyacentes
				//Recibes dos vertices, si con sus posiciones en la matriz el valor es menor que infinito, es que sí existen.
				assert(V.getLabel() < numVertices_);
				assert(U.getLabel() < numVertices_);
				return matriz_[U.getLabel()][V.getLabel()];
			} 
			inline bool verticeCorrecto(){
				if(a_ < getNumV())
					return true;
				return false;
			}
			inline bool ladoCorrecto(){
				if(b_ < getNumV())
					return true;
				return false;
			}
			inline Vertice verticeActual(){
				assert(verticeCorrecto());					//Comprueba que el valor privado de la posición sea correcto
				return v_[a_];
			}
			inline Lado ladoActual(){
				assert(ladoCorrecto());
				Lado L;
				L.setDistancia(matriz_[a_][b_]);			//Rellena la distancia que hay entre dos nodos en la matriz de adyacencia
				L.setInicio(v_[a_]);							//Rellena el primer nodo
				L.setFin(v_[b_]);								//Rellena el último nodo
				return L;
			} 

			inline void setDirecto(){ dirigido_ = true; }

			inline void setIndirecto(){ dirigido_ = false; }

			inline void aniadeVertice(string nombre){
				Vertice V;
				V.setData(nombre);
				V.setLabel(numVertices_);
				numVertices_++;
				numLados_++;
				v_.push_back(V);
			}
<<<<<<< HEAD
			inline void aniadeLado(Vertice U, Vertice V, double distancia){	
				//assert(U.getLabel() < numVertices_);
				//assert(V.getLabel() < numVertices_);	
=======

			inline void aniadeLado(Vertice U, Vertice V, double distancia){		
>>>>>>> 358f9c307c947eb3026ad04b4d55392bef7967f6
				matriz_[U.getLabel()][V.getLabel()] = distancia;
				if(!dirigido_)								//Si el grafo no es dirigido, en la otra dirección tiene la misma distancia
					matriz_[V.getLabel()][U.getLabel()] = distancia;
			}

/*			inline void buscarVertice(string ciudad){		//Lleva el cursor de vertices a la posición de la ciudad pasada
				bool encontrado = false;
				for(int i = 0; i < numVertices_ && encontrado == false; i++){
					if(v_[i].getData() == ciudad){
						a_ = i;
						encontrado = true;
					}
				}
			}
*/
			inline bool buscarVertice(string ciudad){		//Lleva el cursor de vertices a la posición de la ciudad pasada
				bool encontrado = false;
				for(int i = 0; i < numVertices_ && encontrado == false; i++){
					if(v_[i].getData() == ciudad){
						a_ = i;
						encontrado = true;
					}
				}
				return encontrado;
			}

			inline void irA(Vertice &V){					//Se posiciona en un vértice de la matriz
				bool encontrado = false;
				for(int i = 0; i < numVertices_ && encontrado == false; i++){
					if(v_[i] == V){
						a_ = i;
						encontrado = true;
					}
				}				
			}

			inline void irA(int pos){
				bool encontrado = false;
				for(int i = 0; i < numVertices_ && encontrado == false; i++){
					if(v_[i].getLabel() == pos){
						a_ = i;
						encontrado = true;
					}
				}					
			}

			inline void buscarLado(Vertice &U, Vertice &V){	//Pone el cursor en el lado referenciado
				assert(V.getLabel() < numVertices_);
				assert(U.getLabel() < numVertices_);
				bool encontrado = false;
				a_ = U.getLabel();
				b_ = V.getLabel();
			}

			inline void posicionaVerticeCero(){						//Devuelve el primer vértice
				a_ = 0;
			} 

			inline void siguienteVertice(){							//Devuelve el vértice siguiente al cursor
				a_++;
			}

			inline bool sobrepasaLosVertices(){ 						//Comprueba si el cursor ha sobrepasado la última posición válida
				return a_ == numVertices_;
			}

			inline void beginEdge(Vertice &V){							//Lleva el cursor al primer vértice del lado recibido
				a_ = V.getLabel();
				b_ = 0;
				while(matriz_[a_][b_] == INFINITO && !sobrepasaLosLados()){
					b_++;
				}
			}

			inline void siguienteLado(){								//Devuelve el siguiente lado del cursor que tiene valor válido
				b_++;
				while(matriz_[a_][b_] == INFINITO && !sobrepasaLosLados()){
					b_++;
				}
			}

			inline bool sobrepasaLosLados(){							//Comprueba si el cursor ha sobrepasado la última posición válida
				return b_ == numLados_;
			}

	};
}

#endif