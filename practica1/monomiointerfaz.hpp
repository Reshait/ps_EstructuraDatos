#ifndef __MONOMIOINTERFAZ_HPP__
#define __MONOMIOINTERFAZ_HPP__

namespace ed{
class MonomioInterfaz {
public:
    virtual int getGrado() const = 0;
    virtual double getCoeficiente() const = 0;
    virtual void setGrado(int grado) = 0;
    virtual void setCoeficiente(double coeficiente) = 0;

};
}

#endif
