#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <vector>
#include <iostream>
#include "vertice.hpp"
#include "lado.hpp"

using std::vector;
using std::string;

namespace ed{
	class Grafo{
		private:
			vector<Vertice> v_; //aquí van todas las ciudades
			double **matriz_; 	//Matriz de adyacencia
			bool dirigido_; 	//bandera de dirigido o no
			int a_;				//cursor para los vértices 
			int b_;				//cursor para los lados
			int numVertices_;	//numero de vértices
			int numLados_;		//numero de lados
			int tamanio_;		//capacidad del grafo

		public:
			Grafo(unsigned int tam = 0, bool dirigido = true){
				if(tam < 0)
					tam = 0;
				matriz_ = new double *[tamanio_];				//Inicio reserva de memoria para matriz
				
				for(int i = 0; i < tam; i++)
					matriz_[i] = new double [tamanio_];			//Fin reserva de memoria para matriz

				for(int i = 0; i < tam; i++){					//Inicializo matriz a valor infinito
					for(int j = 0; j < tam; j++){
						matriz_[i][j] = 32000;
					}
				}

				numVertices_ = 0;	
				numLados_ = 0;
				tamanio_ = tam;
				dirigido_ = dirigido;
			}

			inline int getNumV() const { return numVertices_; }
			inline int getNumL() const { return numLados_; }
			inline int getTam() const { return tamanio_; }
			inline bool getDiri() const { return dirigido_; }
			inline bool estaVacia() const { return getNumV() == 0 && getNumL() == 0; }
			inline bool adyacencia(Vertice &U, Vertice &V){ 	//Comprueba si dos vertices son adyacentes
				assert(tiene(U));
				assert(tiene(V));
				return U.otro(V) == U || V.otro(U) == V;
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
				L.inicio(v_[a_]);							//Rellena el primer nodo
				L.fin(v_[b_]);								//Rellena el último nodo
				return L;
			} 

			inline void setDirecto(){ dirigido_ = true; }
			inline void setIndirecto(){ dirigido_ = false; }
			inline void aniadeVertice(string nombre){
				Vertice V;
				V.setData(nombre);
				V.setLabel(numVertices_);
				numVertices_++;
				v_.push_back(V);
			}
			inline void aniadeLado(Vertice U, Vertice V, double distancia){		
				matriz_[U.label()][V.label()] = distancia;
				numLados_++;
				if(!dirigido_)								//Si el grafo no es dirigido, en la otra dirección tiene la misma distancia
					matriz_[V.label()][U.label()] = distancia;
			}

	};
}

#endif