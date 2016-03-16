#include <iostream>
#include <string>
#include <cstdlib> // Para los systems del menú en linux
#include "donanteinterfaz.hpp"
#include "donante.hpp"

using namespace std;


int main(){
	system("clear");

	Donante D1, D2;
	D1.leeDonante();
	D2.leeDonante();
	D1.escribeDonante();
	D2.escribeDonante();

/*
	string antonio = "antonio", pedro = "pedro";
	if( pedro >= antonio)
		cout << "Están ordenados" << cout << endl;
	else
		cout << "No están ordenados" << cout << endl;
*/
	if(D1 <= D2){
		cout << D1.getApellidos() << " " << D1.getNombre() << " está antes alfabéticamente que ";
		cout << D2.getApellidos() << " " << D2.getNombre() << endl;
	}
	else
		cout << "Mal ordenados" << endl;
	return 0;
}

