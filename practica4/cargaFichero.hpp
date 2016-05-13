#ifndef __CARGAR_FICHERO_HPP__
#define __CARGAR_FICHERO_HPP__

#include <iostream>
#include <string>
#include <fstream>
#include "vertice.hpp"
#include "lado.hpp"
#include "grafo.hpp"

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;

namespace ed{
	Grafo * cargarFichero(string nombreFichero){

		ifstream f(nombreFichero.c_str());
		int numVertices, d;
		double distancia;
		Grafo *G;
		bool dirigido;
		string cad, cad2;
		Vertice first, second;

		f >> numVertices;
		f >> d;

		if(d == 0)
			dirigido = false;
		else
			dirigido = true;
		
		G = new Grafo(numVertices, dirigido);


		for(int i = 0; i < numVertices; i++){
			f >> cad;
			G->aniadeVertice(cad);
		}



		//hasta aquí cargados y metidos los vértices en el grafo
		while(f >> cad >> cad2 >> distancia){
			G->buscarVertice(cad); // posiciono el cursor
			first.setData(cad);		
			first.setLabel(G->verticeActual().getLabel()); //Devuelves ese vértice y obtiene esa label

			//Pendiente sobrecargar el operador = y hacer first = G->verticeActual()

			G->buscarVertice(cad2); // posiciono el cursor
			second.setData(cad2);
			second.setLabel(G->verticeActual().getLabel());

			G->aniadeLado(first, second, distancia);
		}
		
		f.close();
		return G;

		}

	//Mostrar Grafo
	void mostarGrafo(Grafo *G)
	{
	Vertice aux;

	G->posicionaVerticeCero();
	while(!G->sobrepasaLosVertices()){
		aux = G->verticeActual();
	
			std::cout<<aux.getData()<<":"<<aux.getLabel()<<std::endl;

			G->siguienteVertice();
		}
		Lado l;
		G->posicionaVerticeCero();
	while(!G->sobrepasaLosVertices()){
		aux = G->verticeActual();
	
			G->beginEdge(aux);
		while(not G->sobrepasaLosLados()){
			l = G->ladoActual();
			std::cout << l.getInicio().getData() << "," << l.getFin().getData() << "," << l.getDistancia() << std::endl;
			G->siguienteLado();
		}

			G->siguienteVertice();
		}


	}

/////////////////////////

void camino(Grafo *g,Vertice &origen,Vertice &destino,int **intermedios){

	if(intermedios[origen.getLabel()][destino.getLabel()] != -1){
		g->irA(intermedios[origen.getLabel()][destino.getLabel()]);
		Vertice intermedio=g->verticeActual();
		camino(g,origen,intermedio,intermedios);
		cout<<intermedio.getData()<<" ";
		camino(g,intermedio,destino,intermedios);
	}
}

	void Floyd(Grafo * &g,double **distancias,int **intermedios)
{
int i,j,k;
double distanciaT;
Vertice u,v;
string origen,destino;

//Reservamos memoria para las dos matrices
distancias=new double*[g->getTam()];
for(int i=0;i<g->getTam();i++)
distancias[i]=new double[g->getTam()];


intermedios=new int*[g->getTam()];
for(int i=0;i<g->getTam();i++)
intermedios[i]=new int[g->getTam()];



	for(i=0;i<g->getNumV();i++)
	{
		for(j=0;j<g->getNumV();j++)
		{
		intermedios[i][j]=-1;
		if(i==j)
		distancias[i][j]=0;
		else{
		g->irA(i);
		u=g->verticeActual();
		g->irA(j);
		v=g->verticeActual();
		distancias[i][j]=g->adyacencia(u,v);}
		}
	}

for(k=0;k<g->getNumV();k++)
{
	for(i=0;i<g->getNumV();i++)
	{
		for(j=0;j<g->getNumV();j++)
		{
			if( distancias[i][j] > ( (distancias[i][k]) + (distancias[k][j]) ) )
			{
			distancias[i][j]=( distancias[i][k]+distancias[k][j] );
			intermedios[i][j]=k;
			}	
		}
	}
}

cout<<"Introduce el primer nodo: ";
cin>>origen;
g->buscarVertice(origen);
u=g->verticeActual();


cout<<"Introduce el segundo nodo: ";
cin>>destino;
g->buscarVertice(destino);
v=g->verticeActual();

	if( distancias[u.getLabel()][v.getLabel()] == 32000 )
	cout<<"No existe distancia mínima"<<endl;
	else
	cout<<"La distancia mínima entre "<<u.getData()<<" y "<<v.getData()<<" es: "<<distancias[u.getLabel()][v.getLabel()]<<endl;

	cout<<"El camino mínimo es: ";
	cout<<origen<<" ";
	camino(g,u,v,intermedios);
	cout<<destino<<endl;

}


//////////////////////
	

}
#endif