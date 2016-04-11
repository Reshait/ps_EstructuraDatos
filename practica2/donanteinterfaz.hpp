/*! 
  \file     donanteinterfaz.hpp
  \brief    DonanteInterfaz representa la clase de preRequisitos para la clase Donante.
  \author   Teófilo Rojas Mata
  \date     10/04/2016
*/
#ifndef __DONANTEINTERFAZ_HPP__
#define __DONANTEINTERFAZ_HPP__

#include <string>

using std::string; 
//!  Definición del espacio de nombres ED de la asignatura
namespace ed{

//!  Definición de la plantilla de la clase Donante
    class DonanteInterfaz {
    public:
        //! \name Funciones de obtención de datos de Donante
        
        /*! 
            \brief Declaración virtual pura de la función getNombre
            \return componente "nombre" del Donante
            \pre El Donante debe existir
            \post Ninguna
        */
        virtual string getNombre() const = 0;

        /*! 
            \brief Declaración virtual pura de la función getApellidos
            \return componente "apellidos" del Donante
            \pre El Donante debe existir
            \post Ninguna
        */
        virtual string getApellidos() const = 0;

        /*! 
            \brief Declaración virtual pura de la función getGrupo
            \return componente "grupo" del Donante
            \pre El Donante debe existir
            \post Ninguna
        */
        virtual string getGrupo() const = 0;

        /*! 
            \brief Declaración virtual pura de la función getFactor
            \return componente "factor" del Donante
            \pre El Donante debe existir
            \post Ninguna
        */
        virtual string getFactor() const = 0;         

        //! \name Funciones de modificación de Donante

        /*! 
            \brief Declaración virtual pura de la función setNombre
            \param nombre de tipo string
            \pre El Donante debe existir
            \post Ninguna
        */        
        virtual void setNombre(string nombre) = 0;

       /*! 
            \brief Declaración virtual pura de la función setApellidos
            \param apellidos de tipo string
            \pre El Donante debe existir
            \post Ninguna
        */
        virtual void setApellidos(string apellidos) = 0;

        /*! 
            \brief Declaración virtual pura de la función setGrupo
            \param nombre de tipo string
            \pre El Donante debe existir
            \post Ninguna
        */
        virtual void setGrupo(string nombre) = 0;

        /*! 
            \brief Declaración virtual pura de la función setFactor
            \param nombre de tipo string
            \pre El Donante debe existir
            \post Ninguna
        */    
        virtual void setFactor(string nombre) = 0;        
    };
}

#endif
