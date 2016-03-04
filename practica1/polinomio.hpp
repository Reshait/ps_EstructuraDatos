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
        //bool esVacio_;
        //Me falta el vector o la lista
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

        int getGrado(){ return grado_; }
        int getNumMonomios(){ return numMonomios_;}

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
        bool vacio(){
            return getList().empty();
        }
        //bool encuentraMonomio(list<Monomio> aux){
        bool encuentraMonomio(Monomio monomioAecontrar){
            list<Monomio>::iterator i;
            for(i = getList().begin(); i != getList().end(); i++)
                //if(monomioAecontrar == *i)
                if(monomioAecontrar.getGrado() == i->getGrado())
                    if(monomioAecontrar.getCoeficiente() == i->getCoeficiente())
                        return true;
            return false;
        }
        void leerPolinomio(){
            string opcionMenu;
            Monomio aux;
            bool monomioIntroducido;
            do{
                monomioIntroducido = false;
                aux.leerMonomio();
                if(encuentraMonomio(aux))
                    cout << "El grado introducido ya está ocupado, por favor, introduzca un polinomio de otro grado" << endl;
                else{
                    aniadeMonomioAlista(aux);
                    monomioIntroducido = true;
                }
                cout << "Introduzca [s/S] para salir, cualquier otra letra o número para introducir otro monomio..: ";
                cin >> opcionMenu;
            }while(opcionMenu != "s" || opcionMenu != "S");
        }
};

#endif
