#ifndef __POLINOMIO_HPP__
#define __POLINOMIO_HPP__
#include <cassert>
#include <string>
#include <list>
#include <algorithm> //Para poder usar la función sort y unique
#include "polinomiointerfaz.hpp"
#include "monomio.hpp"

using std::string;
using std::sort;

//Tiene que estar antes de la clase, para que la pille la función ordenaPolinomio
bool ordenaGrados (const Monomio mayor, const Monomio menor) { return (mayor.getGrado() > menor.getGrado()); }
bool sonIguales(const Monomio m1, const Monomio m2){ return m1.getCoeficiente() == m2.getCoeficiente() && m1.getGrado() == m2.getGrado();}

class Polinomio:public ed::PolinomioInterfaz{
    private:
        int grado_;
        int numMonomios_;
        list<Monomio> lista_;

    public:
        //list<Monomio> lista_;
        Polinomio(int grado = 0, int numMonomios = 1){
            //assert(getGrado()+1 >= numMonomios);
            setGrado(grado);
            setNumMonomios(numMonomios);
        }

        Polinomio(const Polinomio &p){
            setGrado(p.getGrado());
            setNumMonomios(p.getNumMonomios());
            setList(p.getList());
        }

        int getGrado() const{ return grado_; }

        int getNumMonomios() const{ return numMonomios_;}

        void setGrado(int grado){
            grado_ = grado;
        }
        void setNumMonomios(int numMonomios){
            numMonomios_ = numMonomios;
        }

        void aniadeMonomioAlista(Monomio monomioAintroducir){
            lista_.push_back(monomioAintroducir);
        }

        void setList(list<Monomio> lista){
            lista_ = lista;
        }

        list<Monomio> getList() const{
            return lista_;
        }

        list<Monomio> &getListForChange(){
            return lista_;
        }

        bool vacio() const{
            return getList().empty();
        }

        bool encuentraMonomio(Monomio monomioAecontrar){
            list<Monomio>::iterator i;
            list<Monomio> aux = getList();

            for(i = aux.begin(); i != aux.end(); i++)
                if(monomioAecontrar == *i)//operador == sobrecargado en monomio.hpp
                    return true;
            return false;
        }

        void leerPolinomio(){
            string opcionMenu;
            Monomio aux;

            do{
                aux.leerMonomio();
                if(!getList().empty()){
                    if(encuentraMonomio(aux))
                        cout << "El grado introducido ya está ocupado, por favor, introduzca un polinomio de otro grado" << endl;
                    else
                        aniadeMonomioAlista(aux);
                }
                else
                    aniadeMonomioAlista(aux);
                
                cout << "Introduzca [s/S] para salir, cualquier otra letra o número para introducir otro monomio..: ";
                cin >> opcionMenu;
            }while(opcionMenu != "s" && opcionMenu != "S");
            this->ordenaPolinomio();
        }

        void escribirPolinomio(){
            list<Monomio>::iterator i;
            int contador = 0;
            if(getList().empty())
                cout << "Su polinomio está vacío" << endl;
            else{
                for(i = lista_.begin(); i !=  lista_.end(); i++){

                    if(i != getList().begin() && i->getCoeficiente() >= 0)
                        if(contador != 0 && i->getCoeficiente() >= 0)
                            cout << "+ ";
                    cout << *i << " ";
                    contador++;
                }
                cout << endl;
            }
        }
        
        friend ostream &operator<< (ostream &salida, const Polinomio &P){
            list<Monomio>::const_iterator i;
            int contador = 0;
            if(P.getList().empty())
                salida << "Su polinomio está vacío" << endl;
            else{
                for(i = P.lista_.begin(); i !=  P.lista_.end(); i++){

                    if(i != P.lista_.begin() && i->getCoeficiente() >= 0)
                        if(contador != 0 && i->getCoeficiente() >= 0)
                            salida << "+ ";
                    salida << *i << " ";
                    contador++;
                }
                //salida << endl;
            }
            return salida;
        }

        Polinomio operator+(Polinomio recibido){
            list<Monomio>::iterator i1, i2;
            Polinomio resultado;
            
            if(this->getGrado() < recibido.getGrado())
                resultado.setGrado(recibido.getGrado());
            else
            	resultado.setGrado(this->getGrado());
           
           resultado.setList(this->getList());

           for(i2 = recibido.lista_.begin(); i2 != recibido.lista_.end(); i2++){
	            bool encontrado = false;
	            
	            for(i1 = resultado.lista_.begin(); i1 != resultado.lista_.end(); i1++){
                    if(i1->getGrado() == i2->getGrado()){
                        i1->setCoeficiente(i1->getCoeficiente() + i2->getCoeficiente());
                    	encontrado = true;
                    }
                }
                
                if(!encontrado)
                	resultado.aniadeMonomioAlista(*i2);
            }            	
           
            resultado.setNumMonomios(resultado.lista_.size());
            return resultado;
        }
        
        Polinomio operator+(Monomio recibido){
            list<Monomio>::iterator i1;
            Polinomio resultado;
            bool encontrado;
            
            if(this->getGrado() < recibido.getGrado())
                resultado.setGrado(recibido.getGrado());
            else
            	resultado.setGrado(this->getGrado());
           
           resultado.setList(this->getListForChange());

            for(i1 = resultado.lista_.begin(); i1 != resultado.lista_.end(); i1++){
	            if(i1->getGrado() == recibido.getGrado()){
	                i1->setCoeficiente(i1->getCoeficiente() + recibido.getCoeficiente());
					encontrado = true;
				}
            }   
            
            if(!encontrado)
            	resultado.aniadeMonomioAlista(recibido);     	
           
            resultado.setNumMonomios(resultado.lista_.size());
            return resultado;
        }

        Polinomio operator*(Polinomio recibido){
            list<Monomio>::iterator i1, i2;
            Polinomio auxiliar, auxiliar2;

            for(i1 = this->lista_.begin(); i1 != this->lista_.end(); i1++){
                for(i2 = recibido.lista_.begin(); i2 != recibido.lista_.end(); i2++){
                    auxiliar.aniadeMonomioAlista( (*i1) * (*i2) );
                }
            }

            auxiliar.ordenaPolinomio();
            auxiliar.setGrado(auxiliar.getList().begin()->getGrado());

            //Suma de polinomios del mismo grado en la lista
            for(int i = auxiliar.getGrado(); i > 0; i--){
                Monomio mAux(0,i);

                for(i1 = auxiliar.lista_.begin(); i1 != auxiliar.lista_.end(); i1++){
                    if( i1->getGrado() == i)
                        if(i1->getCoeficiente() != 0)
                            mAux.setCoeficiente(mAux.getCoeficiente()+i1->getCoeficiente());
                }
                if(mAux.getCoeficiente() != 0)
                    auxiliar2.aniadeMonomioAlista(mAux);
            }

            return auxiliar2;
        }

        Polinomio& operator=(Polinomio recibido){
            this->setGrado(recibido.getGrado());
            this->setNumMonomios(recibido.getNumMonomios());
            this->setList(recibido.getList());

            return *this;
        }
        
        void ordenaPolinomio(){
            getListForChange().sort(&ordenaGrados);
        }
        
        void eliminaRepetidos(){
            getListForChange().unique(&sonIguales);
        }
        
        double resuelvePolinomio(double valorX){
        	list<Monomio>::iterator i;
        	double resultado = 0;
        	
        	for(i = lista_.begin(); i != lista_.end(); i++){
        		resultado += i->resuelveMonomio(valorX);		
        	}
        	
        	return resultado;
        }
        
};

int menuPolinomio(){
    int opcion = -1;

    do{
        cabeceraEjercicios();
        cout << "1.- Obtener el valor de un Polinomio para un dato concreto de X." << endl;
        cout << "2.- Obtener la suma de dos Polinomios." << endl;
        cout << "3.- Obtener la multiplicación de dos Polinomios." << endl;
        cout << "4.- Leer y escribir polinomio." << endl;
        cout << "0.- Salir sin hacer nada." << endl;
        cout << endl;

        cout << ">> Introduzca la opción deseada..: ";
        cin >> opcion;
        if(opcion == 0)
            cout << "Saliendo..." << endl;
        if(opcion < 0 || opcion > 4){
            system("tput setaf 1");
            cout << "Error de opcion." << endl;
            system("tput sgr0");
            cout << "Presione intro para continuar..." << endl;
            cin.ignore();
            cin.get();
        }
    }while(opcion < 0 || opcion > 4);

    return opcion;
}

#endif
