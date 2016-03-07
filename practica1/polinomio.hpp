#ifndef __POLINOMIO_HPP__
#define __POLINOMIO_HPP__
#include <cassert>
#include <string>
//#include <list>
#include "polinomiointerfaz.hpp"
#include "monomio.hpp"

using std::string;

class Polinomio:public ed::PolinomioInterfaz{
    private:
        int grado_;
        int numMonomios_;
        list<Monomio> lista_;

    public:
        Polinomio(int grado = 0, int numMonomios = 1){
            assert(getGrado()+1 >= numMonomios);
            setGrado(grado);
            setNumMonomios(numMonomios);
        }

        Polinomio(const Polinomio &p){
            setGrado(p.grado_);
            setNumMonomios(p.numMonomios_);
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

        bool vacio() const{
            return getList().empty();
        }

        bool encuentraMonomio(Monomio monomioAecontrar){
            list<Monomio>::iterator i;
            for(i = getList().begin(); i != getList().end(); i++)
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
        }

        //FALLA AL PASARLE POLINOMIO DE 4 MONOMIOS O MÁS.
        //PQ NO PUEDO USAR GETLIST().BEGIN() Y GETLIST().END() EN EL FOR?????
        void escribirPolinomio(){
            list<Monomio>::iterator i;
            int contador = 0;
            if(getList().empty())
                cout << "Su polinomio está vacío" << endl;
            else{
                //for(i = getList().begin(); i !=  getList().end(); i++){
                for(i = lista_.begin(); i !=  lista_.end(); i++){

                    if(i != getList().begin() && i->getCoeficiente() >= 0)
                        if(contador != 0 && i->getCoeficiente() >= 0)
                            cout << "+ ";
                    cout << *i << " ";
                    contador++;
                }
                cout << endl;
                //cout << "Contador..: " << contador << endl;
                //cout << "Tamaño de la lista..: " << getList().size() << endl;
            }
        }

        Polinomio& operator+(Polinomio recibido){
            list<Monomio>::iterator i1, i2;
            if(this->getGrado() < recibido.getGrado()){
                this->setGrado(recibido.getGrado());
            }

            for(i1 = this->lista_.begin(); i1 != this->lista_.end(); i1++){
                for(i2 = recibido.lista_.begin(); i2 != recibido.lista_.end(); i2++){

                    if(i1->getGrado() == i2->getGrado())
                        //this->lista_[i1].setCoeficiente(i1->getCoeficiente() + i2->getCoeficiente());
                        i1->setCoeficiente(i1->getCoeficiente() + i2->getCoeficiente());

                    else{
                        this->aniadeMonomioAlista(*i2);
                        this->setNumMonomios(this->getNumMonomios()+1);
                    }

                }
            }
            return *this;
        }

        Polinomio& operator=(Polinomio recibido){
            this->setGrado(recibido.getGrado());
            this->setNumMonomios(recibido.getNumMonomios());
            this->setList(getList());

            return *this;
        }
};

#endif
