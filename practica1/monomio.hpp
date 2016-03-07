#ifndef __MONOMIO_HPP__
#define __MONOMIO_HPP__
#include <iostream>
#include <cmath>
#include "monomiointerfaz.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

class Monomio:public ed::MonomioInterfaz{
    private:
        double coeficiente_;
        int grado_;
    public:
        Monomio(double coeficiente = 1, int grado = 1){ //Constructor inicializado
            setGrado(grado);
            setCoeficiente(coeficiente);
        }

        Monomio(const Monomio &m){
            setGrado(m.grado_);
            setCoeficiente(m.coeficiente_);
        }

        int getGrado() const{
            return grado_;
        }

        double getCoeficiente() const{
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

        Monomio &operator= (const Monomio &recibido){
            this->setGrado(recibido.getGrado());
            this->setCoeficiente(recibido.getCoeficiente());

            return *this;
        }

        Monomio &operator+ (const Monomio &recibido){
            if(this->getGrado() == recibido.getGrado()){
                this->setCoeficiente(this->getCoeficiente() + recibido.getCoeficiente());
                return *this;
            }
            cout << "La suma no se ha podido realizar porque los grados de los monomios no son iguales" << endl;
            return *this;
        }

        bool operator== (Monomio &aux){
            return this->getGrado() == aux.getGrado() && this->getCoeficiente() == aux.getCoeficiente();
        }

        Monomio operator* (const Monomio &m2){
            Monomio resultado(1,0);

            resultado.setGrado(this->getGrado() + m2.getGrado());
            resultado.setCoeficiente(this->getCoeficiente() * m2.getCoeficiente());

            return resultado;
        }

        double resuelveMonomio(double valorX){
            double resultado;
            resultado = pow(valorX * getCoeficiente(), getGrado());

            return resultado;
        }

        //friend istream &operator>>(istream &stream, Monomio &m);
        //friend ostream &operator<<(ostream &stream, Monomio const &m);
        friend ostream &operator<< (ostream &salida, const Monomio &m){
            if(m.getCoeficiente() == 1 || m.getCoeficiente() == -1){
                if(m.getGrado() == 1 && m.getCoeficiente() == 1)
                    salida << "x";
                else if(m.getGrado() == 1 && m.getCoeficiente() == -1)
                    salida << "-x";
                else
                    salida << "x^" << m.getGrado();
            }
            else{
                if(m.getGrado() == 1)
                    salida << m.getCoeficiente() << "x^";
                else
                    salida << m.getCoeficiente() << "x^" << m.getGrado();
            }
            return salida;
        }
};

void cabeceraEjercicios(){
    system("clear");
    system("tput bold");
    system("tput setab 12");
    cout << "+-------------------------------------------------------+" << endl;
    cout << "| Teófilo Rojas Mata, Práctica 1 de Estructura de Datos |" << endl;
    cout << "+-------------------------------------------------------+" << endl;
    system("tput sgr0");
    cout << endl;
}

int menu(){
    int opcion = -1;

    do{
        cabeceraEjercicios();
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

#endif
