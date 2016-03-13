#include "monomiointerfaz.hpp"
#include "monomio.hpp"
#include "polinomio.hpp"
#include "polinomiointerfaz.hpp"

using namespace std;

int main(){
	cabeceraEjercicios();
	int opcionMenu;
	double valorX;
    Polinomio P1, P2;
    Monomio m1, m2(1,2), m3(2,1), m4(1,2);

   	P1.aniadeMonomioAlista(m1);
   	P1.aniadeMonomioAlista(m2);
   	P1.ordenaPolinomio();    
   	
    opcionMenu = menuPolinomio();
    if(opcionMenu == 1){

        cout << endl << "Polinomio que se resolverá..: ";
        cout << P1 << endl;

        cout << "Introduzca el valor de X para resolver los monomios..: ";
        cin >> valorX;
        cout << "El resultado del polinomio es..: " <<
        P1.resuelvePolinomio(valorX) << endl;
    }

    else if(opcionMenu == 2){
    	P2.aniadeMonomioAlista(m4);
    	P2.aniadeMonomioAlista(m3);
    	P2.ordenaPolinomio();
	    	
        cout << "El resultado de la operación..:" << endl;
        cout << "[ " << P1 << " ]";
        cout << " + ";
        cout << "[ " << P2 << " ]";
        cout << " = ";
        Polinomio polinomioAuxiliar = P1 + P2;
        cout << polinomioAuxiliar;
        cout << endl;
    }

    else if(opcionMenu == 3){
    	Polinomio P2;
    	P2.aniadeMonomioAlista(m4);
    	P2.aniadeMonomioAlista(m3);
    	P2.ordenaPolinomio();
	    	
        cout << "El resultado de la operación..:" << endl;
        cout << "[ " << P1 << " ]";
        cout << " * ";
        cout << "[ " << P2 << " ]";
        cout << " = ";
        Polinomio polinomioAuxiliar = P1 * P2 ;
        cout << polinomioAuxiliar;
        cout << endl;
    }

    else if(opcionMenu == 4){
    //. Lectura y escritura de un polinomio haciendo uso de los los operadores “>>” y “<<”
    
//    	P2.leerPolinomio();
    	//cin >> P2;
    	cout << "Polinomio introducido..: ";
    	cout << P2 << endl;
    }

}
