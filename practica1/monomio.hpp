/*! 
  \file		monomio.hpp
  \brief 	Monomio representa la clase monomio definida por la interfaz monomiointerfaz.hpp
  \author 	Teófilo Rojas Mata
  \date 	13/03/2016
*/

#ifndef __MONOMIO_HPP__
#define __MONOMIO_HPP__
#include <iostream>
#include <cmath>
#include <cstdlib> // Para los systems del menú en linux
#include "monomiointerfaz.hpp"

/*!
   \brief Partes necesiaras de espacio de nombres para la asignatura de Estructura de datos.
*/
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

//!  Definición de la plantilla de la clase Monomio
class Monomio:public ed::MonomioInterfaz{
	//! \name Atributos privados de la clase Monomio (coeficiente y grado)
    private:
        double coeficiente_;
        int grado_;
        
    //! \name Métodos públicos de la clase Monomio    
    public:
    
    	//! \name Constructores de la clase Monomio
		/*! 
		\brief Constructor que crea un Monomio a partir de su coeficiente y grado
		\attention Función sobrecargada        
	 	\note Los parámetros tienen valores por defecto
		\param grado valor por defecto 1
		\param coeficiente valor por defecto 1
		\pre Ninguna
		\post Ninguna
		\sa setCoeficiente(), setGrado()
		*/
        Monomio(double coeficiente = 1, int grado = 1){ //Constructor inicializado
            setGrado(grado);
            setCoeficiente(coeficiente);
        }

	/*! 
		\brief Constructor de "copia" que crea un Monomio a partir de otro Monomio
		\attention Función sobrecargada        
		\param m de tipo Monomio pasado como referencia constante
		\pre El Monomio q debe existir
		\post Ninguna
		\sa setCoeficiente(), setGrado()
	*/
        Monomio(const Monomio &m){
            setGrado(m.grado_);
            setCoeficiente(m.coeficiente_);
        }

	/*! 
		\brief Devuelve el grado de un Monomio
		\return componente "grado" del Monomio
		\pre El Monomio debe existir
		\post Ninguna
		\sa getGrado()
	*/
        int getGrado() const{
            return grado_;
        }

	/*! 
		\brief Devuelve el coeficiente de un Monomio
		\return componente "coeficiente" del Monomio
		\pre El Monomio debe existir
		\post Ninguna
		\sa getCoeficiente()
	*/
        double getCoeficiente() const{
            return coeficiente_;
        }
        
       	//! \name Funciones de modificación de Punto2D

	/*! 
		\brief Asigna un valor "grado" a la coordenada "grado_" de un Monomio
		\param grado de tipo int
		\pre El Monomio debe existir
		\post Ninguna
		\sa setGrado()
	*/
        void setGrado(int grado){
            grado_ = grado;
        }

	/*! 
		\brief Asigna un valor "coeficiente" a la coordenada "coeficiente_" de un Monomio
		\param grado de tipo double
		\pre El Monomio debe existir
		\post Ninguna
		\sa setCoeficiente()
	*/
        void setCoeficiente(double coeficiente){
            coeficiente_ = coeficiente;
        }
        
	//! \name Funciones lectura y escritura de la clase Punto2D      
        
	/*! 
		\brief Imprime por pantalla el coeficiente y el grado de un Monomio.
		\param grado de tipo int
		\pre El Monomio debe existir
		\post Ninguna
		\sa setGrado()
	*/
        void escribirMonomio(){
            cout << getCoeficiente() << "x^" << getGrado();
        }

	/*! 
		\brief Asigna a un Monomio el "coeficiente" y "grado" leídas desde el teclado
		\pre El Monomio debe existir
		\post Ninguna
		\warning Se deben teclear números flotante/coeficiente y entero/grado
		\sa setGrado(), setCoeficiente()
	*/
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

	//! \name Sobrecargas de operadores =, +, *, == para operaciones entre Monomios

	/*! 
		\brief Asigna a un Monomio el valor completo de otro Monomio
		\pre El Monomio debe existir
		\post Ninguna
		\sa setGrado(), setCoeficiente()
	*/
        Monomio &operator= (const Monomio &recibido){
            this->setGrado(recibido.getGrado());
            this->setCoeficiente(recibido.getCoeficiente());

            return *this;
        }

	/*! 
		\brief Asigna a un Monomio la suma con otro Monomio
		\pre El Monomio debe existir
		\post Ninguna
		\param tipo Monomio, constante y por referencia "recibido"
		\sa setGrado(), setCoeficiente(), getGrado(), getCoeficiente()
	*/
        Monomio &operator+ (const Monomio &recibido){
            if(this->getGrado() == recibido.getGrado()){
                this->setCoeficiente(this->getCoeficiente() + recibido.getCoeficiente());
                return *this;
            }
            cout << "La suma no se ha podido realizar porque los grados de los monomios no son iguales" << endl;
            return *this;
        }

	/*! 
		\brief Compara el valor de un Monomio con otro Monomio
		\pre Los Monomio deben existir
		\post Ninguna
		\param tipo Monomio por referencia "aux"
		\sa getGrado(), getCoeficiente()
	*/
        bool operator== (Monomio &aux){    
        	return (this->getGrado()==aux.getGrado()) && 
        		   (this->getCoeficiente()==aux.getCoeficiente());
        }

	/*! 
		\brief Multiplica el valor de un Monomio por otro Monomio
		\pre Los Monomio deben existir
		\post Ninguna
		\param tipo Monomio, constante y por referencia "m2"
		\sa getGrado(), getCoeficiente(), setGrado(), setCoeficiente()
	*/
        Monomio operator* (const Monomio &m2){
            Monomio resultado(1,0);

            resultado.setGrado(this->getGrado() + m2.getGrado());
            resultado.setCoeficiente(this->getCoeficiente() * m2.getCoeficiente());

            return resultado;
        }

	/*! 
		\brief Resuelve un Monomio con el valor pasado
		\pre Los Monomio deben existir
		\post Ninguna
		\param tipo double "aux", con el valor de resolución
		\sa getGrado(), getCoeficiente(), setGrado(), setCoeficiente()
	*/
        double resuelveMonomio(double valorX){
            double resultado;
            resultado = pow(valorX * getCoeficiente(), getGrado());

            return resultado;
        }

	/*! 
		\brief Escribe por pantalla Monomio sobrecargando operador >>
		\pre Los Monomio deben existir
		\post Ninguna
		\param tipo stream y Monomio por referencia
	*/
        friend istream &operator>>(istream &stream, Monomio &m){
        	cout << endl << "Introduzca el coeficiente del monomio..: " << endl;
			stream >> m.coeficiente_;
			cout << endl << "Introduzca el grado del monomio..: " << endl;
			stream >>  m.grado_;
			return stream;     
        }

	/*! 
		\brief Lee por teclado Monomio sobrecargando operador <<
		\pre Los Monomio deben existir
		\post Ninguna
		\param tipo stream y Monomio por referencia
	*/
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
                    salida << m.getCoeficiente() << "x";
                else
                    salida << m.getCoeficiente() << "x^" << m.getGrado();
            }
            return salida;
        }
};

	/*! 
		\brief Cabecera personalizada de presentación para el menú
	*/
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

	/*! 
		\brief Menú de selección
	*/
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
}  // Fin de la definición de la clase Punto2D y del namespace ed

#endif
