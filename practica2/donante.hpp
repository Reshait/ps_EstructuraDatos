#ifndef __DONANTE_HPP__
#define __DONANTE_HPP__

#include <string>
#include <iostream>
#include "donanteinterfaz.hpp"

using std::string; 
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

class Donante: public ed::DonanteInterfaz {
    private:
    	string nombre_;
    	string apellidos_;
    	string grupo_;
    	string factor_;
    	
    public:
        string getNombre() const{ return nombre_; }
        string getApellidos() const{ return apellidos_; }
        string getGrupo() const{ return grupo_; }
        string getFactor() const{ return factor_; }         
        
        void setNombre(string nombre){ nombre_ = nombre; }
        void setApellidos(string apellidos){ apellidos_ = apellidos; }
        void setGrupo(string grupo){
        	while(grupo != "0" && grupo != "A" && grupo != "B" && grupo != "AB" && grupo != "@"){
        		cout << "El Grupo sanguíneo no puede ser distinto de 0|A|B|AB." << endl;
        		cout << "Por favor Introduzca de nuevo el Grupo sanguíneo ..: ";
        		cin >> grupo;
                getchar();
        	}
        	grupo_ = grupo; 
        }        
        void setFactor(string factor){ 
        	while(factor != "positivo" && factor != "Positivo" && factor != "POSITIVO" && factor != "negativo" && factor != "Negativo" && factor != "NEGATIVO" && factor != "@@@@@@@@"){
        		cout << "El Factor RH no puede ser distinto de 'Positivo' o 'Negativo'." << endl;
        		cout << "Por favor Introduzca de nuevo el Factor RH ..: ";
        		cin >> factor;
                getchar();
        	}
        	factor_ = factor; 
        }    
        
        Donante(string nombre = "XXXXX", string apellidos = "XXXXX XXXXX", string grupo = "@", string factor = "@@@@@@@@"){
        	setNombre(nombre);
        	setApellidos(apellidos);
        	setGrupo(grupo);
        	setFactor(factor);  
        }   
        
        Donante(const Donante &D){
        	setNombre(D.getNombre());
        	setApellidos(D.getApellidos());
        	setGrupo(D.getGrupo());
        	setFactor(D.getFactor());
        }

        //¿Acceso y modificación?
       	//Si hay problemas usar getchar();       	
        void leeDonante(){
        	string nombre, apellidos, grupo, factor;
        	cout << "Introduzca el nombre del donante\t..: ";
        	//getchar();
        	getline(cin, nombre);
        	cout << "Introduzca los apellidos del donante\t..: ";
        	getline(cin, apellidos);
        	cout << "Introduzca grupo sanguíneo (0|A|B|AB)\t..: ";
        	getline(cin, grupo);
        	cout << "Introduzca factor RH (positivo|negativo)..: ";
        	getline(cin, factor);

        	setNombre(nombre);
        	setApellidos(apellidos);
        	setGrupo(grupo);
        	setFactor(factor); 
        }
        
        void escribeDonante(){
        	cout << "==========================================" << endl;
        	cout << "\tNombre\t\t..: " << getNombre() << endl;
        	cout << "\tApellidos\t..: " << getApellidos() << endl;
        	cout << "\tGrupo Sanguíneo\t..: " << getGrupo() << endl;
        	cout << "\tFactor RH\t..: " << getFactor() << endl;
        }

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

        Donante &operator=(const Donante &D){
        	this->setNombre(D.getNombre());
        	this->setApellidos(D.getApellidos());
        	this->setGrupo(D.getGrupo());
        	this->setFactor(D.getFactor());
        	return *this;
        }
        
        bool operator==(const Donante &D){
        	return  this->getNombre() == D.getNombre() && this->getApellidos() == D.getApellidos();
        }

        bool operator<=(const Donante &D){
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

        friend istream &operator>>(istream &salida, Donante &D){
        	string nombre, apellidos, grupo, factor;
        	cout << "Introduzca el nombre del donante\t..: ";
        	getline(salida, nombre);
        	cout << "Introduzca los apellidos del donante\t..: ";
        	getline(salida, apellidos);
        	cout << "Introduzca el grupo sanguíneo\t..: ";
        	getline(salida, grupo);
        	cout << "Introduzca el factor RH\t\t..: ";
        	getline(salida, factor);
        	cout << "==========================================" << endl;
        	D.setNombre(nombre);
        	D.setApellidos(apellidos);
        	D.setGrupo(grupo);
        	D.setFactor(factor); 

        	return salida;
        }

        friend ostream &operator<<(ostream &entrada, Donante &D){
       		entrada << "==========================================" << endl;
        	entrada << "\tNombre\t\t..: " << D.getNombre() << endl;
        	entrada << "\tApellidos\t..: " << D.getApellidos() << endl;
        	entrada << "\tGrupo Sanguíneo\t..: " << D.getGrupo() << endl;
        	entrada << "\tFactor RH\t..: " << D.getFactor() << endl;  	

        	return entrada;
        }
};


#endif
