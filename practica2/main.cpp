#include <iostream>
#include <string>
#include <cstdlib> // Para los systems del menú en linux
#include "donanteinterfaz.hpp"
#include "donante.hpp"
#include "menuDonante.hpp"

using namespace std;


int main(){
	system("clear");

	Donante D1("Teófilo", "Rojas Mata", "A", "positivo"), D2(D1), D3;

	menu(D1, D2, D3);


	///////////////////////////////////////

	return 0;
}

