#include <iostream>
#include <string>
#include <cstdlib> // Para los systems del menú en linux
#include "donanteinterfaz.hpp"
#include "donante.hpp"

using namespace std;


int main(){
	system("clear");
	Donante D;
	D.leeDonante();
	D.escribeDonante();
	
	return 0;
}

