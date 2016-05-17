/*! 
  \file     funciones.hpp
  \brief    Funciones restantes para realizar Floyd, camino, cargar Fichero y varios...
  \author   Teófilo Rojas Mata
  \date     16/05/2016
*/

#ifndef __FUNCIONES_HPP__
#define __FUNCIONES_HPP__
/*! 
 \brief Simulación de distancias rellenas al máximo para inicializar la matriz
 \sa INFINITO
*/   
#define INFINITO 999999

#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include "vertice.hpp"
#include "lado.hpp"
#include "grafo.hpp"

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;
using ed::Grafo;
using ed::Lado;
using ed::Vertice;

	/*! 
	  \brief Muestra la cabecera de la práctica3 con mis datos personales.
	  \post Ninguna
	  \sa cabecera()
	  \param x tipo entero con el número de la práctica.
	*/
	void cabecera(int x){
	    system("clear");
	    system("tput bold");

	    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
	    cout << "┃ Teófilo Rojas Mata, Práctica " << x << " de Estructura de Datos ┃" << endl;
	    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
	    system("tput sgr0");

	    cout << endl;
	}

    /*! 
      \brief Función para cargar los datos desde un fichero
      \param nombreFichero tipo string
      \post Ninguna
      \sa cargarfichero()
    */
	Grafo * cargarFichero(string nombreFichero){

		ifstream f(nombreFichero.c_str());								// abre fichero
		int numVertices, d;
		double distancia;
		Grafo *G;
		bool dirigido;
		string cad, cad2;
		Vertice U, V;

		f >> numVertices;												// lee del archivo los números de vértices
		f >> d;															// lee del archivo si es dirigido o no

		if(d == 0)
			dirigido = false;
		else
			dirigido = true;
		
		G = new Grafo(numVertices, dirigido);							// reserva memoria para el grafo


		for(int i = 0; i < numVertices; i++){							// Lee vértices del archivo y los añade al grafo
			f >> cad;
			G->aniadeVertice(cad);
		}

																		// Lee lados del archivo y los añade al grafo
		while(f >> cad >> cad2 >> distancia){
			G->buscarVertice(cad); 										// posiciona el cursor
			U.setData(cad);												// Se le da nombre de la ciudad al nodo
			U.setLabel(G->verticeActual().getLabel()); 					// Devuelve ese vértice y obtiene esa label

			G->buscarVertice(cad2); 									// posiciona el cursor
			V.setData(cad2);											// Se le da nombre de la ciudad al nodo
			V.setLabel(G->verticeActual().getLabel());					// Devuelve ese vértice y obtiene esa label

			G->aniadeLado(U, V, distancia);								// Añade lado al grafo con los datos obtenidos
		}
		
		f.close();
		return G;

	}

    /*! 
      \brief Imprime el Grafo por pantalla
      \param G tipo Grafo
      \pre El Grafo debe existir
      \post Ninguna
      \sa mostrarGrafo()
    */
	void mostrarGrafo(Grafo *G){
		Vertice aux;
		G->posicionaVerticeCero();										// posiciona al principio del grafo

		while(!G->sobrepasaLosVertices()){								// imprime todos los nodos
			aux = G->verticeActual();
			cout << aux.getData() << ":" << aux.getLabel() << endl;

			G->siguienteVertice();										// avanza el cursor
		}
		
		Lado L;
		G->posicionaVerticeCero();										// posiciona al principio del grafo

		while(!G->sobrepasaLosVertices()){								// imprime todos los lados
			aux = G->verticeActual();
			G->beginEdge(aux);											// fija el primer vertice del lado
				
			while(!G->sobrepasaLosLados()){								// imprime el lado completo
				L = G->ladoActual();
				cout << L.getInicio().getData() << "," << L.getFin().getData() << "," << L.getDistancia() << endl;
				G->siguienteLado();
			}

			G->siguienteVertice();										// pasa al siguiente lado
		}
	}

    /*! 
      \brief Función para controlar/arreglar el error de que el texto se pase en minúscula o con tíldes.
      \param ciudad tipo string
      \pre El Grafo debe existir
      \post Ninguna
      \sa pasarAmayuscula()
    */
	void pasaAmayuscula(string &ciudad){

		string conTildes = "áéíóú", sinTildes = "AEIOU";

		for(int i = 0; i < ciudad.size(); i++){							//El truco está en que un carácter con tilde en c++ pesa dos posiciones.
			for(int j = 0; j < conTildes.size(); j+=2){
				if(ciudad[i] == conTildes[j] && ciudad[i+1] == conTildes[j+1]){
					ciudad[i] = sinTildes[j/2];							//sustituyo el primer caracter con tilde por uno sin tilde
					ciudad.erase(ciudad.begin()+i+1);					//Borro el carácter siguiente que ocupa un 2do espacio por la tilde
				}
			}

			ciudad[i] = toupper(ciudad[i]);
		}

		cout << ciudad << endl;

	}

    /*! 
      \brief Controla que la ciudad introducida exista, si no, la vuelve a pedir.
      \param G tipo Grafo
      \param ordenCiudad tipo int
      \pre El Grafo debe existir
      \post Ninguna
      \sa pideLaCiudad()
    */
	Vertice pideLaCiudad(Grafo *G, int ordenCiudad){
		string ciudad;
		bool primeraVez = true;
		
		while(!G->buscarVertice(ciudad)){
			if(!primeraVez)												//si NO es la primera vez que se entra en el bucle, 
				cout << "La ciudad no existe." << endl;					//es pq la ciudad introducida no existe, 
																		//indica que no existe y vuelve a pedirla
			cout << "Introduzca la " << ordenCiudad << "º ciudad\t..: ";

			primeraVez = false;
			cin >> ciudad;
			pasaAmayuscula(ciudad);
		}		

		return G->verticeActual();
	}

    /*! 
      \brief Función para mostrar el camino mínimo de las ciudades
      \param G tipo Grafo
      \param origen tipo Vertice
      \param destino tipo Vertice
      \param intermedios tipo int
      \pre El Grafo debe existir
      \post Ninguna
      \sa camino()
    */
	void camino(Grafo *G,Vertice &origen,Vertice &destino,int **intermedios){

		if(intermedios[origen.getLabel()][destino.getLabel()] != -1){	// Si hay conexión entre vértices
			G->irA(intermedios[origen.getLabel()][destino.getLabel()]);	// Posicionate en ese punto
			Vertice intermedio = G->verticeActual();					// guarda el vértice intermedio
			camino(G, origen, intermedio, intermedios);					// recursivo
			cout << intermedio.getData() << " ";						// imprime un intermedio
			camino(G, intermedio, destino, intermedios);				// recursivo
		}
	}

    /*! 
      \brief Función para generar el Algoritmo de Floyd
      \param G tipo Grafo
      \param distancias tipo double**
      \param intermedios tipo int**
      \pre El Grafo debe existir
      \post Ninguna
      \sa Floyd()
    */
	void Floyd(Grafo * &G,double **&distancias,int **intermedios){
		int i,j,k;
		double distanciaT;
		Vertice U,V;
		string origen,destino;
																		// Reserva memoria para las dos matrices
		distancias = new double*[G->getTam()];							// matriz para las distancias
		intermedios = new int*[G->getTam()];							// matriz para los intermedios


		for(i = 0; i < G->getNumV(); i++){
			intermedios[i] = new int[G->getTam()];						// trampa que mejora la eficiencia del código
			distancias[i] = new double[G->getTam()];					// trampa que mejora la eficiencia del código

			for(j = 0; j < G->getNumV(); j++){
				intermedios[i][j] = -1;									// inicializa intermedios a NO conexion
				
				if(i == j)												// si es la misma ciudad, distancia consigo 0
					distancias[i][j] = 0;								
				
				else{													// si no, añade la distancia entre ciudades
					G->irA(i);
					U = G->verticeActual();
					G->irA(j);
					V = G->verticeActual();
					distancias[i][j] = G->adyacencia(U,V);
				}
			}
		}

		for(k = 0; k < G->getNumV(); k++){								// aplica Floyd
			for(i = 0; i < G->getNumV(); i++){							// si la distancia es menor usando el nuevo camino
				for(j = 0;j < G->getNumV(); j++){						// sustituye el camino antiguo por el nuevo
					if( (distancias[i][k] + distancias[k][j]) < distancias[i][j]){
						distancias[i][j] = ( distancias[i][k]+distancias[k][j] );
						intermedios[i][j] = k;
					}	
				}
			}
		}

		U = pideLaCiudad(G, 1);											// pide las ciudades
		V = pideLaCiudad(G, 2);

		if( distancias[U.getLabel()][V.getLabel()] == INFINITO )		// si no están conectados, imprímelo
			cout << "No existe distancia mínima" << endl;				

		else{
			cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl; // si están conectados, impríme la distancia
			cout << "La distancia mínima entre "<< U.getData() <<" y " << V.getData()<<" es: " << distancias[U.getLabel()][V.getLabel()] << "km" << endl;
		}

		cout << "El camino mínimo es: ";								// muestra el camino
		cout << U.getData() << " ";
		camino(G, U, V, intermedios);
		cout << V.getData() << endl;

	}	

    /*! 
      \brief Función para controlar el error de que no exista el fichero
      \param nombreFichero tipo string
      \pre El fichero debe existir
      \post Ninguna
      \sa existeFichero()
    */
	bool existeFichero(string nombreFichero){
		bool devuelve = false;
		ifstream f(nombreFichero.c_str());

		if(f)
			devuelve = true;
		
		f.close();
		return devuelve;
	}

    /*! 
      \brief Función obtener la menor suma de los vértices
      \param G tipo Grafo*
      \pre El Grafo debe existir
      \post Ninguna
      \sa verticeMenorSuma()
    */
	void verticeMenorSuma(Grafo *G, double** distancias){
/*		double minimo = INFINITO;
		double sumDistancia;
		double distancia;
		int posicionSolucion = 0;
		Vertice U, V;

		for(int i = 0; i < G->getNumV(); i++)							//Recorre la matriz
		{
			sumDistancia = 0;
			G->irA(i);													//Fija la ciudad 1ª
			U = G->verticeActual();

			for(int j = 0; j < G->getNumV(); j++)
			{
				G->irA(j);
				V = G->verticeActual();									//Fija la ciudad 2ª

				distancia = G->adyacencia(U,V);							//Toma la distancia entre ciudades

				if(distancia < INFINITO)								//Si están unidas añade su distancia
					sumDistancia += distancia;
			}

			if(sumDistancia < minimo)									//Actualiza a mínima distancia
			{
				minimo = sumDistancia;
				posicionSolucion = i;
			}
		}

		G->irA(posicionSolucion);
		U=G->verticeActual();
		cout<<"Vértice con la menor suma de distancias\t..: "<<U.getData()<<endl;
		cout << "Valor de la suma de sus distancias\t..: " << minimo << "km" << endl;
*/
		Vertice U;
		double sumaDistancia;
		double minimaDistancia = INFINITO;
		int posicionMinimo;

		for(int i = 0; i < G->getNumV(); i++){
			sumaDistancia = 0;
			for(int j = 0; j < G->getNumV(); j++)
				sumaDistancia += distancias[i][j];

			if(sumaDistancia < minimaDistancia){
				minimaDistancia = sumaDistancia;
				posicionMinimo = i;
			}
		}		
		G->irA(posicionMinimo);
		U = G->verticeActual();
		cout << U.getData()  << endl;
		cout << "Con una distancia de\t..: " << minimaDistancia;
	}

    /*! 
      \brief Función para obtener la suma de las distancias
      \param G tipo Grafo*
      \param posicionVertice tipo int
      \pre El Grafo debe existir
      \post Ninguna
      \sa sumaDistancias()
    */	
	void sumaDistancias(Grafo *G, int posicionVertice, double** distancias){
		Vertice U;
		double sumaDistancia = 0;
		double minimaDistancia = INFINITO;
		int posicionMinimo;

		G->irA(posicionVertice);

		for(int j = 0; j < G->getNumV(); j++)
			sumaDistancia += distancias[posicionVertice][j];

		if(sumaDistancia < minimaDistancia)
			minimaDistancia = sumaDistancia;
		
		U = G->verticeActual();
		cout << U.getData()  << endl;
		cout << "Con una distancia de\t..: " << minimaDistancia;		


	}

#endif