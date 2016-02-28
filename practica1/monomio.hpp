#ifndef __MONOMIO_HPP__
#define __MONOMIO_HPP__
#include "monomiointerfaz.hpp"
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

class Monomio:public MonomioInterfaz{
    private:
        double coeficiente_;
        int grado_;
    public:
        //Monomio(); --> Constructor normal
        Monomio(double coeficiente = 1, int grado = 1){ //Constructor inicializado
            setGrado(grado);
            setCoeficiente(coeficiente);
        }
        Monomio(const Monomio &m){ //Si el interior se deja en blanco, ¿debería funcionar??, compilar, sí me compila.
            setGrado(m.grado_);
            setCoeficiente(m.coeficiente_);
        }

        int getGrado() const{
            return grado_;
        }
        int getCoeficiente() const{
            return coeficiente_;
        }
        void setGrado(int grado){
            grado_ = grado;
        }
        void setCoeficiente(double coeficiente){
            coeficiente_ = coeficiente;
        }
        void escribirMonomio(){
            cout << getCoeficiente() << "x^" << getGrado();
        }
        void leerMonomio(){
            int grado;
            double coeficiente;

            cout << "Introduzca el coeficiente del monomio..: " << endl;
            cin >> coeficiente;
            cout << "Introduzca el grado del monomio..: " << endl;
            cin >> grado;
            setGrado(grado);
            setCoeficiente(coeficiente);
        }
        Monomio operator= (const Monomio &recibido){
            Monomio resultado;

            resultado.setGrado(recibido.getGrado());
            resultado.setCoeficiente(recibido.getCoeficiente());

            return resultado;
        }
        Monomio operator* (const Monomio &recibido){
            Monomio resultado;

            resultado.setGrado(resultado.getGrado()+recibido.getGrado());
            resultado.setCoeficiente(resultado.getCoeficiente()*recibido.getCoeficiente());

            return resultado;
        }
        double resuelveMonomio(double valorX){
            double resultado;
            resultado = pow(valorX * getCoeficiente(), getGrado());

            return resultado;
        }
};

int menu(){
    int opcion = -1;

    do{
        system("clear");
        system("tput bold");
        system("tput setab 12");
        cout << "+-------------------------------------------------------+" << endl;
        cout << "| Teófilo Rojas Mata, Práctica 1 de Estructura de Datos |" << endl;
        cout << "+-------------------------------------------------------+" << endl;
        system("tput sgr0");

        cout << endl;
        cout << "1.- Obtener el valor de un monomio para un dato concreto de X." << endl;
        cout << "2.- Obtener la multiplicación de dos monomios para almacenar el resultado en un tercero." << endl;
        cout << "0.- Salir sin hacer nada." << endl;
        cout << endl;

        cout << ">> Introduzca la opción deseada..: ";
        cin >> opcion;
        if(opcion == 0)
            cout << "Saliendo..." << endl;
        if(opcion < 0 || opcion > 2){
            system("tput setaf 1");
            cout << "Error de opcion." << endl;
            system("tput sgr0");
            cout << "Presione intro para continuar..." << endl;
            cin.ignore();
            cin.get();
        }
    }while(opcion < 0 || opcion > 2);

    return opcion;
}

Monomio multiplicaMonomios(const Monomio &m1, const Monomio &m2){
    Monomio maux(m1);

    maux = maux * m2;

    return maux;
}

#endif
