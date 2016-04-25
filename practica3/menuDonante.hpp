/*! 
  \file     menuDonante.hpp
  \brief    Menú para realizar las funciones requeridas en la parte Donante de la práctica de ED.
  \author   Teófilo Rojas Mata
  \date     10/04/2016
*/

//compilar con:
//g++ main.cpp

#ifndef __MENU_DONANTE_HPP__
#define __MENU_DONANTE_HPP__

#include <cstdlib> // para los systems
#include <string>
#include <iostream>
#include "donanteinterfaz.hpp"
#include "donante.hpp"
#include "cabecera.hpp"
#include "monticuloDonantes.hpp"

using namespace std;
using namespace ed;

/*! 
	\brief Menú para gestionar la parte de la lista de donante (singular) de la práctica2
        \post Ninguna
        \sa menu()
*/
void menu(){
	int opcion;
	int donaciones;
	string fichero;
	Donante D1("Teófilo", "Rojas Mata", "A", "positivo");
	MonticuloDonantes Monticulo;

	do{
		system("clear");

		cabecera(3);
		cout << "1.- Para comprobar si el montículo está vacío." << endl;
		cout << "2.- Cargar un montículo desde un fichero." << endl;
		cout << "3.- Guardar el montículo en un fichero." << endl;
		cout << "4.- Mostrar el donante que se encuentra en la cima." << endl;
		cout << "5.- Realizar una donación." << endl;
		cout << "6.- Mostrar toda la lista de donantes." << endl;
		cout << "7.- Borrar cima del montículo." << endl;
		cout << "0.- Para Salir." << endl;
		cout << "\tIntroduzca una opción >> ";
		cin >> opcion;
		getchar();

		system("clear");

		switch(opcion){
			case 1: 
				if(Monticulo.isEmpty())
					cout << "El montículo está vacío" << endl;
				else
					cout << "El montículo NO está vacío" << endl;
 		       	cout << "==========================================" << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");
				break;
			case 2:
				cout << "Introduzca el nombre (sin espacios) del archivo que desea cargar (ej. bbdd.txt)\t..: ";
				cin >> fichero;
				while(!Monticulo.cargarBBDD(fichero)){
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
				Monticulo.guardarBBDD(fichero);
 		       	cout << "==========================================" << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");			
				break;
			case 4:
				if(Monticulo.isEmpty())
					cout << "El montículo está actualmente vacío." << endl;
				else
					cout << Monticulo.top();
 		       	cout << "==========================================" << endl;		
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");	
				break;	
			case 5:
				cout << "Introduzca el número de donaciones a añadir" << endl;
				cin >> donaciones;
				Monticulo.aniadeDonacion(donaciones);
 		       	cout << "==========================================" << endl;		
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");					
				break;	
			case 6:
				if(Monticulo.isEmpty())
					cout << "El montículo está vacío" << endl;
				else
					Monticulo.mostrar();
 		       	cout << "==========================================" << endl;		
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");				
				break;	
			case 7:
				if(Monticulo.isEmpty())
					cout << "El montículo está vacío." << endl;
				else{
					Monticulo.remove();
					cout << "Cima eliminada Correctamente." << endl;
				}
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
