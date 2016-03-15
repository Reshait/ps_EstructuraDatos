#ifndef __DONANTEINTERFAZ_HPP__
#define __DONANTEINTERFAZ_HPP__

#include <string>

using std::string; 

namespace ed{
    class DonanteInterfaz {
    public:
        virtual string getNombre() const = 0;
        virtual string getApellidos() const = 0;
        virtual string getGrupo() const = 0;      
        virtual string getFactor() const = 0;         
        
        virtual void setNombre(string nombre) = 0;
        virtual void setApellidos(string apellidos) = 0;
        virtual void setGrupo(string nombre) = 0;        
        virtual void setFactor(string nombre) = 0;        
    };
}

#endif
