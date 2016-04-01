#ifndef __MENU_DONANTES_HPP__
#define __MENU_DONANTES_HPP__
#include <iostream>
#include "cabecera.hpp"
#include "donantes.hpp"
#include "donantesinterfaz.hpp"
#include "donante.hpp"
#include "donanteinterfaz.hpp"

using std::endl;
using std::cout;
using std::cin;
using std::string;

using namespace ed;

void menuDonantes(){
	int opcion;
	Donantes lista;
					Donante D1;

	string fichero;

	do{
		system("clear");

		cabecera();
		cout << "1.- Para comprobar si hay donantes." << endl;
		cout << "2.- Para cargar una lista de donantes desde un fichero." << endl;
		cout << "3.- Para grabar la lista de donantes en un fichero." << endl;
		cout << "4.- Para insertar un nuevo donante." << endl;
		cout << "5.- Para modificar la información de un donante." << endl;
		cout << "6.- Para borrar un donante." << endl;
		cout << "7.- Para mostrar por pantalla los donantes." << endl;
		cout << "0.- Para Salir." << endl;
		cout << "\tIntroduzca una opción >> ";
		cin >> opcion;
		getchar();

		system("clear");

		switch(opcion){
			case 1: 
				if(lista.estaVacia())
					cout << "La lista actualmente está vacía." << endl;
				else
					cout << "La lista contiene elementos." << endl;
 		       	cout << "==========================================" << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");
				break;
			case 2:
				cout << "Introduzca el nombre (sin espacios) del archivo que desea cargar (ej. bbdd.txt)\t..: ";
				cin >> fichero;
				while(!lista.cargarBBDD(fichero)){
					cout << "El nombre del fichero introducido no existe." << endl;
					cout << "Por favor, introduzca de nuevo el nombre del fichero ..: ";
					cin >> fichero;
				}
 		       	cout << "==========================================" << endl;
 		       	cout << "Fichero cargado correctamente." << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");
				break;
			case 3:
				cout << "Introduzca el nombre (sin espacios) del archivo que desea guardar (ej. bbddSalida.txt)\t..: ";
				cin >> fichero;
				lista.guardarBBDD(fichero);
 		       	cout << "==========================================" << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");
				break;
			case 4:
				//lista.leerDatos();
				cout << "Introduzca el Donante" << endl;
				cin >> D1;
				lista.insertarDonante(D1);
				cout << "==========================================" << endl;
				cout << "Donante/s Introducido/s correctamente." << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");
				break;	
			case 5:
				//Me falta por hacer.
				cout << "==========================================" << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");
				break;	
			case 6:
				//Me falta por hacer.
				cout << "==========================================" << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");
				break;	
			case 7:
    			cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    			cout << "┃            LISTA DE DONANTES            ┃" << endl;
    			cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
				lista.mostrarDatos();
				cout << "==========================================" << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");
				break;	
			case 0:
				cout << "Saliendo ..." << endl;
				break;	
			default:
				cout << "Opción introducida incorrecta." << endl;
				cout << "Pulse intro para continuar..." << endl;
				system("read");
				break;	
		}
	}while(opcion != 0);
}

#endif