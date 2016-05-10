#include <iostream>
#include <string>
#include "vertice.hpp"
#include "lado.hpp"
#include "grafo.hpp"
#include "cargaFichero.hpp"

using namespace ed;
using namespace std;

int main(){
	Grafo G;
	string nombreFichero;
//	int opc;

//	switch(opc){
//		case 1:
			cout << "Introduzca el nombre del fichero\t..: ";
			cin >> nombreFichero;
			cargarFichero(G, nombreFichero);
//		break;
//	}

	return 0;
}


