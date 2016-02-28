#include "monomiointerfaz.hpp"
#include "monomio.hpp"

using namespace std;

int main(){
    int opcionMenu;
    double valorX;
    Monomio::Monomio monomio1, monomio2(2.3,3), monomio3(monomio1);

    opcionMenu = menu();
    if(opcionMenu == 1){
        cout << endl << "Monomios que se resolverán..: ";
        monomio1.escribirMonomio();
        cout << ", ";
        monomio2.escribirMonomio();
        cout << ", ";
        monomio3.escribirMonomio();
        cout << endl;

        cout << "Introduzca el valor de X para resolver los monomios..: ";
        cin >> valorX;
        cout << "El resultado de los monomios es..: " <<
        monomio1.resuelveMonomio(valorX) << ", " <<
        monomio2.resuelveMonomio(valorX) << ", " <<
        monomio3.resuelveMonomio(valorX) << endl;
    }
    if(opcionMenu == 2){
        cout << "El resultado de la operación..:" << endl;
        monomio1.escribirMonomio();
        cout << " * ";
        monomio2.escribirMonomio();
        cout << " = ";
        Monomio monomioAuxiliar(multiplicaMonomios(monomio1, monomio2));
        monomioAuxiliar.escribirMonomio();
        cout << endl;
    }

 return 0;
}
