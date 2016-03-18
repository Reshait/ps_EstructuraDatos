#ifndef __MENU_DONANTE_HPP__
#define __MENU_DONANTE_HPP__
#include "donanteInterfaz.hpp"
#include "donante.hpp"

void cabeceraEjercicios(){
    system("clear");
    system("tput bold");
    system("tput setab 12");
    cout << "+-------------------------------------------------------+" << endl;
    cout << "| Teófilo Rojas Mata, Práctica 2 de Estructura de Datos |" << endl;
    cout << "+-------------------------------------------------------+" << endl;
    system("tput sgr0");
    cout << endl;
}

void menu(Donante &D1, Donante &D2, Donante &D3){
	int opcion;
	
	do{
		system("clear");

		cabeceraEjercicios();
		//cout << "Menú de Donante" << endl;
		cout << "1.- Para leer un donante desde el teclado." << endl;
		cout << "2.- Escribir un donante por pantalla." << endl;
		cout << "3.- Modificar los datos de un donante." << endl;
		cout << "4.- Comparar lexicográficamente dos donantes." << endl;
		cout << "0.- Para Salir." << endl;
		cout << "\tIntroduzca una opción >> ";
		cin >> opcion;
		getchar();

		system("clear");

		switch(opcion){
			case 1: 
				D1.leeDonante();
 		       	cout << "==========================================" << endl;
				cout << "Donante Introducido correctamente." << endl; 
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");
				break;
			case 2:
				D1.escribeDonante();
 		       	cout << "==========================================" << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");
				break;
			case 3:
				D1.modificaDatosDonante();
				break;
			case 4:
				D1.leeDonante();
				cout << "==========================================" << endl;
				cout << "Donante 1 Introducido correctamente." << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");

				D2.leeDonante();
				cout << "==========================================" << endl;
				cout << "Donante 2 Introducido correctamente." << endl;
				cout << "Presione la tecla 'Intro' para continuar..." << endl;
				system("read");

				if(D1 == D2)
					cout << "Los nombres introducidos son iguales" << endl;
				else if(D1 <= D2)
					cout << D1.getApellidos() << " " << D1.getNombre() << " es lexicográficamente menor que " << D2.getApellidos() << " " <<D2.getNombre() << endl;
				else
					cout << D1.getApellidos() << " " << D1.getNombre() << " es lexicográficamente mayor que " << D2.getApellidos() << " " << D2.getNombre() << endl;
				cout << "Pulse Intro para continuar..." << endl;
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