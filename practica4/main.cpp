#include <iostream>
#include <string>
#include <fstream>
#include "vertice.hpp"
#include "lado.hpp"
#include "grafo.hpp"
#include "funciones.hpp"

using namespace ed;
using namespace std;

int main(){
	Grafo *G;
	G = new Grafo(0,1);
	string fichero;
	double **distancia;
	int **intermedio;
	int opcion;

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
				cabecera(4);

				Floyd(G, distancia, intermedio);
 		       	cout << "==========================================" << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");			
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


