#include "monomiointerfaz.hpp"
#include "monomio.hpp"
#include "polinomio.hpp"
#include "polinomiointerfaz.hpp"

using namespace std;

int main(){
	cabeceraEjercicios();
    Polinomio P1, P2;
 /*   P.leerPolinomio();
    P.escribirPolinomio();
    P.ordenaPolinomio();
    cout << "Su polinomio Ordenado queda..:" << endl;
    P.escribirPolinomio();
*/
    Monomio m1, m2(1,2), m3(2,2);
 /*   P2.aniadeMonomioAlista(m1);
    P2.aniadeMonomioAlista(m2);
    P2.aniadeMonomioAlista(m3);
    P2.aniadeMonomioAlista(m3);
    P2.aniadeMonomioAlista(m4);


    P2.escribirPolinomio();
    P2.ordenaPolinomio();
    P2.escribirPolinomio();
    P2.eliminaRepetidos();
    P2.escribirPolinomio();
*/

    P1.aniadeMonomioAlista(m1);
    P1.aniadeMonomioAlista(m2);
    P1.ordenaPolinomio();
    P2.aniadeMonomioAlista(m3);
	P2.aniadeMonomioAlista(m1);
	P2.ordenaPolinomio();

	P1 * P2;
	P1.escribirPolinomio();
}
