#ifndef __DONANTE_HPP__
#define __DONANTE_HPP__

#include <string>
#include <iostream>
#include "donanteinterfaz.hpp"

using std::string; 
using std::cin;
using std::cout;
using std::endl;

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
        void setGrupo(string grupo){ grupo_ = grupo; }        
        void setFactor(string factor){ factor_ = factor; }    
        
        Donante(string nombre = "XXXXX", string apellidos = "XXXXX XXXXX", string grupo = "X", string factor = "XXXXXXXX"){
        	setNombre(nombre);
        	setApellidos(apellidos);
        	setGrupo(grupo);
        	setFactor(factor);  
        }   
        
        Donante(const Donante &D);
        //¿Acceso y modificación?
        void leeDonante(){
        	string nombre, apellidos, grupo, factor;
        	cout << "Introduzca el nombre del donante\t..: ";
        	getline(cin, nombre);
        	cout << "Introduzca los apellidos del donante\t..: ";
        	getline(cin, apellidos);
        	cout << "Introduzca el grupo sanguíneo\t..: ";
        	getline(cin, grupo);
        	cout << "Introduzca el factor RH\t\t..: ";
        	getline(cin, factor);
        	cout << "==========================================" << endl;
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
};


#endif
