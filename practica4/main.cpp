
/*!
	@mainpage Teófilo Rojas Mata
	@brief Programa principal de la practica 4 de ED, Grafo de Floyd<br>
	@brief Curso: <i>2º Grado de Ingeniería Informática</i><br>
	@brief <center><img src='http://images.slideplayer.es/17/5319031/slides/slide_52.jpg'></center>
	
*/
/*! 
  \file     main.cpp
  \brief    Es el archivo que carga el menú correspondiente exigido por la práctica 4 de la asignatura Estructura de Datos.
  \author   Teófilo Rojas Mata
  \date     16/05/2016
*/

//compilar con:
//g++ main.cpp

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> // para los systems
#include "vertice.hpp"
#include "lado.hpp"
#include "grafo.hpp"
#include "funciones.hpp"

using namespace ed;
using namespace std;

/*! 
  	\brief Menú para gestionar los ejercicios requeridos en la práctica 4 de la asignatura Estructura de Datos
    \pre Ninguna
    \post Ninguna
    \sa main()
*/
int main(){
	Grafo *G;
	G = new Grafo(0,1);
	string fichero;
	double **distancia = NULL;
	int **intermedio = NULL;
	int opcion;
	int opcion2;
	bool floydPasado = false;

	do{

		cabecera(4);
		cout << "1.- Para cargar un grafo desde un fichero." << endl;
		cout << "2.- Mostrar el grafo por pantalla." << endl;
		cout << "3.- Aplicar algoritmo de Floyd." << endl;
		cout << "0.- Para Salir." << endl;
		cout << "\tIntroduzca una opción >> ";
		cin >> opcion;
		getchar();

		switch(opcion){
			
			case 1:
				cabecera(4);

				cout << "Introduzca el nombre (sin espacios) del archivo que desea cargar" << endl;
				cout << "(ej. anda.txt o peni.txt)\t..: ";
				cin >> fichero;

				while(!existeFichero(fichero)){	
 		       		cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
					cout << "El nombre del fichero introducido no existe." << endl;
					cout << "Por favor, introduzca de nuevo el nombre (sin espacios) del archivo que desea cargar." << endl;
					cout << "(ej. anda.txt o peni.txt)\t..: ";
					cin >> fichero;
				}

				G = cargarFichero(fichero);

 		       	cout << "==========================================" << endl;
 		       	cout << "Fichero cargado correctamente." << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");			
				break;
			
			case 2: 
				cabecera(4);

				if(G->estaVacio())
					cout << "El Grafo está vacío" << endl << "Usted debe cargar previamente un fichero." << endl << " (Opción del 1 del menú)" << endl;
				else
					mostrarGrafo(G);

 		       	cout << "==========================================" << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");
				break;
			
			case 3:
				do{
					cabecera(4);

					if(G->estaVacio())
						cout << "El Grafo está vacío" << endl << "Usted debe cargar previamente un fichero." << endl << " (Opción del 1 del menú)" << endl;
					else{
						cout << "\t\t\tFLOYD" << endl;
	 		       		cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
						cout << ">>\t1.- Mostrar el vértice con menor suma." << endl;
						cout << ">>\t2.- Mostrar suma de distancias de cada vértice." << endl;
						cout << ">>\t3.- Aplicar algoritmo de Floyd." << endl;
						cout << ">>\t0.- Para Salir." << endl;
						cout << ">>\t\tIntroduzca una opción >> ";
						cin >> opcion2;
						getchar();

						switch(opcion2){
							case 1:
								cabecera(4);
								if(floydPasado){
									cout << "\t\t>> VERTICE CON MENOR SUMA" << endl;
									verticeMenorSuma(G, distancia);
									cout << endl;
								}
								else
									cout << "Primero Debe realizar FLOYD(pto. 3)" << endl << "para rellenar la matriz de distancias" << endl ;
							break;

							case 2:
								cabecera(4);
								if(floydPasado){
			 		       			cout << "\t>> SUMA DE DISTANCIAS DE CADA VERTICE" << endl;
			 		       			for(int i = 0; i < G->getNumV(); i++){
			 		       				sumaDistancias(G, i, distancia);
			 		       				cout << endl;
			 		       			}
		 		       			}
		 		       			else
									cout << "Primero Debe realizar FLOYD(pto. 3)" << endl << "para rellenar la matriz de distancias" << endl ;
							break;

							case 3:
								cabecera(4);
								cout << "\t>> MINIMA DISTANCIA ENTRE UNA CIUDAD Y OTRA" << endl;						
								Floyd(G, distancia, intermedio);
								floydPasado = true;
							break;

							case 0:
								cabecera(4);
								cout << "Volviendo al menú principal" << endl;
							break;

							default:
								cabecera(4);
								cout << "Opción introducida incorrecta." << endl;
								cout << "Pulse intro para continuar..." << endl;
								system("read");
							break;	
						}
					}
	 		       	cout << "==========================================" << endl;
					cout << "Presione la tecla 'Intro' para continuar..." << endl;
					system("read");	

				}while(opcion2 != 0);	
				break;				
			
			case 0:
				system("clear");

				cout << "Saliendo ..." << endl;
				break;	
			
			default:
				cabecera(4);
				cout << "Opción introducida incorrecta." << endl;
				cout << "Pulse intro para continuar..." << endl;
				system("read");
				break;	
		}
	}while(opcion != 0);		

	return 0;
}


