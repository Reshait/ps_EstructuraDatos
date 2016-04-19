/*! 
  \file     donante.hpp
  \brief    Donante representa la calse donante definida por la interfaz donanteinterfaz.hpp
  \author   Teófilo Rojas Mata
  \date     10/04/2016
*/

#ifndef __DONANTE_HPP__
#define __DONANTE_HPP__

#include <string>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "donanteinterfaz.hpp"

/*!
   \brief Partes necesiaras de espacio de nombres para la asignatura de Estructura de datos.
*/
using std::string; 
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

//!  Definición de la plantilla de la clase Donante
class Donante: public ed::DonanteInterfaz {
    //! \name Atributos privados de la clase Donante (nombre, apellidos, grupo y factor)
    private:
    	string nombre_;
    	string apellidos_;
    	string grupo_;
    	string factor_;
        int donaciones_;

//! \name Métodos públicos de la clase Donante     	
    public:
        //! \name Funciones de obtención de datos de Donante
        /*! 
            \brief Devuelve el nombre de un Donante
            \return componente "nombre" del Donante
            \pre El Donante debe existir
            \post Ninguna
            \sa getNombre()
        */
        string getNombre() const{ return nombre_; }

        /*! 
            \brief Devuelve los apellidos de un Donante
            \return componente "apellidos" del Donante
            \pre El Donante debe existir
            \post Ninguna
            \sa getApellidos()
        */
        string getApellidos() const{ return apellidos_; }

        /*! 
            \brief Devuelve el grupo de un Donante
            \return componente "grupo" del Donante
            \pre El Donante debe existir
            \post Ninguna
            \sa getGrupo()
        */
        string getGrupo() const{ return grupo_; }

        /*! 
            \brief Devuelve el factor de un Donante
            \return componente "factor" del Donante
            \pre El Donante debe existir
            \post Ninguna
            \sa getFactor()
        */
        string getFactor() const{ return factor_; }         

        //! \name Funciones de modificación de Donante

        int getDonaciones() const{ return donaciones_; }

        /*! 
            \brief Asigna un valor "nombre" a la coordenada "nombre_" de un Donante
            \param nombre de tipo string
            \pre El Donante debe existir
            \post Ninguna
            \sa setNombre()
        */
        void setNombre(string nombre){ nombre_ = nombre; }

        /*! 
            \brief Asigna un valor "apellidos" a la coordenada "apellidos_" de un Donante
            \param apellidos de tipo string
            \pre El Donante debe existir
            \post Ninguna
            \sa setApellidos()
        */
        void setApellidos(string apellidos){ apellidos_ = apellidos; }

        /*! 
            \brief Asigna un valor "grupo" a la coordenada "grupo_" de un Donante
            \param grupo de tipo string
            \pre El Donante debe existir
            \post Ninguna
            \sa setGrupo()
        */
        void setGrupo(string grupo){
        	while(grupo != "0" && grupo != "A" && grupo != "B" && grupo != "AB" && grupo != "@"){
        		cout << "El Grupo sanguíneo no puede ser distinto de 0|A|B|AB." << endl;
        		cout << "Por favor Introduzca de nuevo el Grupo sanguíneo ..: ";
        		cin >> grupo;
                getchar();
        	}
        	grupo_ = grupo; 
        }

        /*! 
            \brief Asigna un valor "factor" a la coordenada "factor_" de un Donante
            \param factor de tipo string
            \pre El Donante debe existir
            \post Ninguna
            \sa setFactor()
        */        
        void setFactor(string factor){ 
        	while(factor != "positivo" && factor != "Positivo" && factor != "POSITIVO" && factor != "negativo" && factor != "Negativo" && factor != "NEGATIVO" && factor != "@@@@@@@@"){
        		cout << "El Factor RH no puede ser distinto de 'Positivo' o 'Negativo'." << endl;
        		cout << "Por favor Introduzca de nuevo el Factor RH ..: ";
        		cin >> factor;
                getchar();
        	}
        	factor_ = factor; 
        } 

        void setDonaciones(int donaciones){
            if(donaciones >= 0)
                donaciones_ = donaciones;
        }   
 
        //! \name Constructores de la clase Donante
        /*! 
        \brief Constructor que crea un Donante a partir de sus datos.
        \attention Función sobrecargada con Constructor de copia        
        \note Los parámetros tienen valores por defecto
        \param nombre valor por defecto "XXXXX"
        \param apellidos valor por defecto "XXXXX XXXXX"
	\param grupo valor por defecto "@"
	\param factor valor por defecto "@@@@@@@@"
        \pre Ninguna
        \post Ninguna
        \sa setNombre(), setApellidos(), setGrupo(), setFactor()
        */        
        Donante(string nombre = "XXXXX", string apellidos = "XXXXX XXXXX", string grupo = "@", string factor = "@@@@@@@@", int donaciones = 0){
        	setNombre(nombre);
        	setApellidos(apellidos);
        	setGrupo(grupo);
        	setFactor(factor);  
            if(donaciones < 0)
                donaciones = 0;
            setDonaciones(donaciones);
        }   

        /*! 
            \brief Constructor de "copia" que crea un Donante a partir de otro Donante
            \attention Función sobrecargada de Constructor       
            \param D de tipo Donante pasado como referencia constante
            \pre El Donante debe existir
            \post Ninguna
            \sa setCoeficiente(), setGrado()
        */        
        Donante(const Donante &D){
        	setNombre(D.getNombre());
        	setApellidos(D.getApellidos());
        	setGrupo(D.getGrupo());
        	setFactor(D.getFactor());
        }
     	
        //! \name Funciones de tratamiento por pantalla de Donante

        /*! 
            \brief guarda el valor Donante introducido por teclado
            \post Ninguna
            \sa leeDonante()
        */       
        void leeDonante(){
        	string nombre, apellidos, grupo, factor;
            int donaciones;
        	cout << "Introduzca el nombre del donante\t..: ";
        	getline(cin, nombre);
        	cout << "Introduzca los apellidos del donante\t..: ";
        	getline(cin, apellidos);
        	cout << "Introduzca grupo sanguíneo (0|A|B|AB)\t..: ";
        	getline(cin, grupo);
        	cout << "Introduzca factor RH (positivo|negativo)..: ";
        	getline(cin, factor);
            cout << "Introduzca el nº de donaciones\t..:";
            cin >> donaciones;

        	setNombre(nombre);
        	setApellidos(apellidos);
        	setGrupo(grupo);
        	setFactor(factor); 
            setDonaciones(donaciones);
        }

        /*! 
            \brief Muestra por pantalla los datos de un Donante
            \post Ninguna
            \sa escribeDonante()
        */       
        void escribeDonante(){
        	cout << "==========================================" << endl;
        	cout << "\tNombre\t\t..: " << getNombre() << endl;
        	cout << "\tApellidos\t..: " << getApellidos() << endl;
        	cout << "\tGrupo Sanguíneo\t..: " << getGrupo() << endl;
        	cout << "\tFactor RH\t..: " << getFactor() << endl;
            cout << "\tDonaciones\t..: " << getDonaciones() << endl;
        }

        /*! 
            \brief Función para modificar los datos de un Donante
            \pre El Donante debe existir
            \post Ninguna
            \sa modificaDatosDonante()
        */       
		void modificaDatosDonante(){
			int opcion;
			string cadena;

			do{
				system("clear");

				cout << "1.- Para modificar el Nombre." << endl;
				cout << "2.- Para modificar los Apellidos." << endl;
				cout << "3.- Para modificar el Grupo sanguíneo." << endl;
				cout << "4.- Para modificar el Factor RH." << endl;
				cout << "0.- Para Salir." << endl;
				cout << "\tIntroduzca una opción >> ";
				cin >> opcion;
				getchar();

				switch(opcion){
					case 1: 
						cout << "El nombre actual del donante es\t ..: " << getNombre() << endl;
						cout << "Introduzca el nuevo nombre\t ..: ";
						getline(cin, cadena);
						setNombre(cadena);
						cout << endl << ">> Nombre modificado correctamente." << endl;
						cout << " Presione la tecla 'Intro' para continuar..." << endl;
						system("read");
						break;
					case 2:
						cout << "Los apellidos actuales son\t ..: " << getApellidos() << endl;
						cout << "Introduzca los nuevos apellidos\t ..: ";
						getline(cin, cadena);
						setApellidos(cadena);
						cout << endl << ">> Apellidos modificados correctamente." << endl;
						cout << " Presione la tecla 'Intro' para continuar..." << endl;
						system("read");
						break;
					case 3:
						cout << "El Grupo sanguíneo actual es (0|A|B|AB)\t ..: " << getGrupo() << endl;
						cout << "Introduzca el nuevo grupo sanguíneo\t ..: ";
						getline(cin, cadena);
						setGrupo(cadena);
						cout << endl << ">> Grupo sanguíneo modificado correctamente." << endl;
						cout << " Presione la tecla 'Intro' para continuar..." << endl;
						system("read");
						break;
					case 4:
						cout << "Factor RH actual (positivo|negativo)\t ..: " << getFactor() << endl;
						cout << "Introduzca el nuevo factor RH\t\t ..: ";
						getline(cin, cadena);
						setFactor(cadena);
						cout << endl << ">> Factor RH modificado correctamente." << endl;
						cout << " Presione la tecla 'Intro' para continuar..." << endl;
						system("read");
						break;
					case 0:
						cout << "Saliendo..." << endl;
						break;	
					default:
						cout << "Opción incorrecta." << endl;		
				}
			}while(opcion != 0);
		}

        /*! 
            \brief Sobrecarga del operador = para poder igualar Donantes.
            \param D de tipo Donante por referencia
            \pre El Donante debe existir
            \post Ninguna
            \sa operator=()
        */       
        Donante &operator=(const Donante &D){
        	this->setNombre(D.getNombre());
        	this->setApellidos(D.getApellidos());
        	this->setGrupo(D.getGrupo());
        	this->setFactor(D.getFactor());
            this->setDonaciones(D.getDonaciones());
        	return *this;
        }
        
        /*! 
            \brief Sobrecarga del operador == para poder comparar Donantes.
            \param D de tipo Donante por referencia
            \pre El Donante debe existir
            \post Ninguna
            \sa operator==()
        */ 
/*        bool operator==(const Donante &D){
        	return  this->getNombre() == D.getNombre() && this->getApellidos() == D.getApellidos();
        }
*/
        bool operator==(const Donante &D){ //Volverlo a dejar como estaba
                return  this->getNombre() == D.getNombre() && this->getApellidos() == D.getApellidos();
        }
        /*! 
            \brief Sobrecarga del operador <= para poder comparar Donantes.
            \param D de tipo Donante por referencia
            \pre El Donante debe existir
            \post Ninguna
            \sa operator<=()
        */ 
 /*       bool operator<=(const Donante &D){
        	bool devuelve = false;
        	if(this->getApellidos() == D.getApellidos()){
        		if(this->getNombre() <= D.getNombre())
        			devuelve = true;
        	}
        	else if(this->getApellidos() <= D.getApellidos()){
        		devuelve = true;
        	}

        	return devuelve;
        }
*/
        bool operator<=(const Donante &D){
            if(getDonaciones() <= D.getDonaciones())
                return true;

            return false;
        }
        /*! 
            \brief Sobrecarga del operador de flujo >> para simplificar la introducción de donantes.
            \param D de tipo Donante por referencia
            \param salida de tipo de control de flujo istream
            \pre El Donante debe estar correctamente declarado.
            \post Ninguna
            \sa operator>>()
        */ 
        friend istream &operator>>(istream &salida, Donante &D){
        	string nombre, apellidos, grupo, factor;
            int donaciones;
        	cout << "Introduzca el nombre del donante\t..: ";
        	getline(salida, nombre);
        	cout << "Introduzca los apellidos del donante\t..: ";
        	getline(salida, apellidos);
        	cout << "Introduzca el grupo sanguíneo\t..: ";
        	getline(salida, grupo);
        	cout << "Introduzca el factor RH\t\t..: ";
        	getline(salida, factor);
            cout << "Introduzca el nº de donaciones\t..:";
            cin >> donaciones;
        	cout << "==========================================" << endl;
        	D.setNombre(nombre);
        	D.setApellidos(apellidos);
        	D.setGrupo(grupo);
        	D.setFactor(factor); 
            D.setDonaciones(donaciones);

        	return salida;
        }

        /*! 
            \brief Sobrecarga del operador de flujo << para simplificar la introducción de donantes.
            \param D de tipo Donante por referencia
            \param entrada de tipo de control de flujo ostream
            \pre El Donante debe estar correctamente declarado.
            \post Ninguna
            \sa operator<<()
        */ 
        friend ostream &operator<<(ostream &entrada, const Donante &D){
       		entrada << "==========================================" << endl;
        	entrada << "\tNombre\t\t..: " << D.getNombre() << endl;
        	entrada << "\tApellidos\t..: " << D.getApellidos() << endl;
        	entrada << "\tGrupo Sanguíneo\t..: " << D.getGrupo() << endl;
        	entrada << "\tFactor RH\t..: " << D.getFactor() << endl; 
            entrada << "\tNº Donaciones\t..: " << D.getDonaciones() << endl; 	

        	return entrada;
        }
};


#endif
