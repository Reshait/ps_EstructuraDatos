//Compilar con:
//g++ menu2.cpp

#ifndef __MENU_DONANTES_HPP__
#define __MENU_DONANTES_HPP__
#include <iostream>
#include <string>
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

void menuModificaDonante(Donante &D){
	int opcion;
	string valorDonante;
	bool flagEdit = false;

	 do{
	 	system("clear");
    	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    	cout << "┃            DONANTE A MODIFICAR          ┃" << endl;
    	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
	 	cout << D;
	 	cout << "==========================================" << endl;
		cout << "1.- Para modificar el nombre." << endl;
		cout << "2.- Para modificar los apellidos." << endl;
		cout << "3.- Para modificar el grupo sanguíneo." << endl;
		cout << "4.- Para modificar el factor RH." << endl;
		cout << "0.- Para Salir." << endl;
		cout << "\tIntroduzca una opción >> ";
		cin >> opcion;
		getchar();
	   	cout << "==========================================" << endl;

		switch(opcion){
			case 1: 
	        	cout << "Introduzca el NUEVO nombre del donante\t..: ";
	        	getline(cin, valorDonante);
				D.setNombre(valorDonante);
				flagEdit = true;
				break;

			case 2:
	        	cout << "Introduzca los NUEVOS apellidos del donante\t..: ";
	        	getline(cin, valorDonante);
				D.setApellidos(valorDonante);
				flagEdit = true;
				break;
			
			case 3:
	        	cout << "Introduzca el NUEVO sanguíneo (0|A|B|AB)\t..: ";
	        	getline(cin, valorDonante);
				D.setGrupo(valorDonante);
				flagEdit = true;
				break;
			
			case 4:
	        	cout << "Introduzca el NUEVO factor RH (positivo|negativo)..: ";
	        	getline(cin, valorDonante);
				D.setFactor(valorDonante);
				flagEdit = true;
				break;
			
			case 0:
				break;
			
			default:
				cout << "Opción introducida incorrecta." << endl;
				cout << "Pulse intro para continuar..." << endl;
				system("read");
				break;	
		}
	}while(opcion != 0);

	if(flagEdit)
		cout << "Cambio/s en el donante realizado/s correctamente." << endl;
	else
		cout << "No se realizaron cambios en el donante." << endl;
}

void menuDonantes(){
	int opcion;
	Donantes lista;
	Donante D1;
	string nombre, apellidos;

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
    			cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    			cout << "┃           INTRODUCA EL DONANTE          ┃" << endl;
    			cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
				cin >> D1;
				lista.insertarDonante(D1);
				cout << "Donante Introducido correctamente." << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");
				break;	
			case 5:
    			cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    			cout << "┃           INTRODUCA EL DONANTE A MODIFICAR         ┃" << endl;
    			cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
	        	cout << "Introduzca el nombre del donante\t..: ";
    	    	getline(cin, nombre);
        		cout << "Introduzca los apellidos del donante\t..: ";
        		getline(cin, apellidos);
        		D1.setNombre(nombre);
        		D1.setApellidos(apellidos);

    			//Menu para leer si se modifica el nombre, el apellido el grupo o el factor.
				if(lista.buscarDonante(D1)){
					cout << "El donante a modificar es :" << endl;
					D1 = lista.devuelveDatosDonante(D1); 	// AutoCompleto factor y grupo del nombre y apellidos introducidos.
					lista.delDonante(D1); 					// Elimino de la lista el que se va a editar
					//cout << D1;
					menuModificaDonante(D1);				// Edito por referencia el valor independiente del campo que se elija
				}

				else{
					cout << "El donante introducido no se encuentra en la lista." << endl;
				}

	    		lista.insertarDonante(D1);
				cout << "==========================================" << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");
				break;	
			case 6:
    			cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    			cout << "┃          INTRODUCA EL DONANTE A ELIMINAR         ┃" << endl;
    			cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    			cin >> D1;

    			if(lista.delDonante(D1))
    				cout << "Donante eliminado correctamente." << endl;
				else
					cout << "El donante introducido no existe." << endl; 
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
