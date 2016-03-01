#ifndef __POLINOMIOINTERFAZ_HPP_
#define __POLINOMIOINTERFAZ_HPP_

namespace ed{
    class PolinomioInterfaz{
        public:
            virtual int getGrado() const = 0;
            virtual int getNumMonomios() const = 0;
            virtual bool getEsVacio() const = 0;

            virtual void setGrado(int grado) = 0;
            virtual void setNumMonomios(int numMonomios) = 0;
            virtual void setEsVacio() = 0;
    };

}

#endif
