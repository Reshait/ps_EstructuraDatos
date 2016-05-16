#ifndef __CARGAR_FICHERO_HPP__
#define __CARGAR_FICHERO_HPP__

#include <iostream>
#include <string>
#include <fstream>
#include "vertice.hpp"
#include "lado.hpp"
#include "grafo.hpp"

using std::ifstream;
using std::string;

namespace ed{
	void cargarFichero(Grafo &G, string nombreFichero){

		ifstream f(nombreFichero.c_str());
		int numVertices, d;
		double distancia;
		bool dirigido;
		string cad, cad2;
		Vertice first, second;

		f >> numVertices;
		f >> d;

		if(d == 0)
			dirigido = false;
		else
			dirigido = true;
		//G = new Grafo(numVertices, d);
		for(int i = 0; i < numVertices; i++){
			f >> cad;
			G.aniadeVertice(cad);
		}

		//hasta aquí cargados y metidos los vértices en el grafo
		while(f >> cad >> cad2 >> distancia){
			G.buscarVertice(cad); // posiciono el cursor
			first.setData(cad);		
			first.setLabel(G.verticeActual().getLabel()); //Devuelves ese vértice y obtiene esa label

			//Pendiente sobrecargar el operador = y hacer first = G->verticeActual()

			G.buscarVertice(cad2); // posiciono el cursor
			second.setData(cad2);
			second.setLabel(G.verticeActual().getLabel());


			G.aniadeLado(first, second, distancia);
		}
		f.close();
	}

	/* Mostrar Grafo
	Vertex aux;
	G->beinVertex;
	while(!G->afterEndVertex()){
		aux = G->currVertex();
		G->beginEdge(aux);
		while(not G->afterEndEdge()){
			count << G->currEdge().inicio().getData() << "," << G->currEdge().fin().getData() << "," << G->currEdge.getdData() << end;
			G->nextVertex();
		}
	}
	*/
}

#endif