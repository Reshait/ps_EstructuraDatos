#include "monomiointerfaz.hpp"
#include "monomio.hpp"
#include "polinomio.hpp"
#include "polinomiointerfaz.hpp"

using namespace std;

int main(){
	cabeceraEjercicios();
    Polinomio P;
    P.leerPolinomio();
    P.escribirPolinomio();
    P.ordenaPolinomio();
    cout << "Su polinomio Ordenado queda..:" << endl;
    P.escribirPolinomio();
}
