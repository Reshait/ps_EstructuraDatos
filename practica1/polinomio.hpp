#ifndef __POLINOMIO_HPP__
#define __POLINOMIO_HPP__
#include "polinomiointerfaz.hpp"
#include "monomio.hpp"

class Polinomio:public ed::PolinomioInterfaz{
    private:
        int grado_;
        int numMonomios_;
        //bool esVacio_;
        //Me falta el vector o la lista
    public:
        Polinomio(int grado = 2, int numMonomios = 2){
            setGrado(grado);
            setNumMonomios(numMonomios);
        }
        Polinomio(const Polinomio &p){
            setGrado(p.grado_);
            setNumMonomios(p.numMonomios_);
        }

        int getGrado(){ return grado_; }
        int getNumMonomios(){ return numMonomios_;}
        //virtual bool getEsVacio() const = 0;

        void setGrado(int grado){
            grado_ = grado;
        }
        void setNumMonomios(int numMonomios){
            numMonomios_ = numMonomios;
        }
        //virtual void setEsVacio() = 0;
};

#endif
