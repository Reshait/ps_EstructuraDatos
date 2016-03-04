#ifndef __POLINOMIO_HPP__
#define __POLINOMIO_HPP__
#include <cassert>
//#include <list>
#include "polinomiointerfaz.hpp"
#include "monomio.hpp"

class Polinomio:public ed::PolinomioInterfaz{
    private:
        int grado_;
        int numMonomios_;
        list<Monomio> lista_;
        //bool esVacio_;
        //Me falta el vector o la lista
    public:
        Polinomio(int grado = 0, int numMonomios = 1){
            assert(getGrado()+1 > numMonomios);
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
        //virtual bool getEsVacio() const = 0;

        void setGrado(int grado){
            grado_ = grado;
        }
        void setNumMonomios(int numMonomios){
            numMonomios_ = numMonomios;
        }
        //virtual void setEsVacio() = 0;
        void setList(list<Monomio> lista){
            lista_ = lista;
        }
        list<Monomio> getList() const{
            return lista_;
        }
};

#endif
