#include <iostream>
#include <string>
#include "vertice.hpp"
#include "lado.hpp"
#include "grafo.hpp"
#include "Funciones.hpp"

using namespace ed;
using namespace std;

int main(){
	Grafo *G;
	string nombreFichero;
	double **distancia;
	int **intermedio;
//	int opc;

//	switch(opc){
//		case 1:
			cout << "Introduzca el nombre del fichero\t..: ";
			cin >> nombreFichero;
			G=cargarFichero(nombreFichero);
			//case 2
//			mostarGrafo(G);
//		break;
//	}

			//el mostrarGrafo es en case 2, no se puede mostrar el grafo si no se ha introducido el fichero. if(G->numVerte==0)

			//case3
			
				Floyd(G, distancia, intermedio);
			

	return 0;
}


