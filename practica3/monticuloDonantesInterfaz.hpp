/*! 
  \file     monticuloDonantesInterfaz.hpp
  \brief    monticuloDonantesInterfaz.hpp representa la clase de preRequisitos para la clase monticuloDonantes definida posteriormente en el archivo monticuloDonantes.hpp.
  \author   Teófilo Rojas Mata
  \date     10/04/2016
*/
#ifndef MONTICULODONANTESINTERFAZ_HPP
#define MONTICULODONANTESINTERFAZ_HPP

#include "donante.hpp"
#include <vector>
#include <cassert>
#include <cstdlib>
/*!
   \brief Partes necesiaras de espacio de nombres para la asignatura de Estructura de datos.
*/
using std::cin;
using std::cout;
using std::ostream;
using std::istream;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::vector;

namespace ed{
//!  Definición de la plantilla de la clase MonticuloDonantesInterfaz
	class MonticuloDonantesInterfaz{

		public:
        /*! 
            \brief Declaración virtual pura de la función isEmpty
            \return variable tipo bool si está vacía
            \pre El montículo debe existir
            \post Ninguna
        */	
			virtual bool isEmpty() const=0;

        /*! 
            \brief Declaración virtual pura de la función top
            \return variable tipo Donante del elemento que está en la cima del Montículo.
            \pre El montículo debe existir
            \post Ninguna
        */	
			virtual Donante top() const=0;

        /*! 
            \brief Declaración virtual pura de la función insertarDonante
            \param d de tipo Donante
            \pre El Monticulo debe existir
            \post Ninguna
        */      			
			virtual void insertarDonante(Donante &d)=0;

        /*! 
            \brief Declaración virtual pura de la función remove
            \pre El Monticulo debe existir
            \post Ninguna
        */ 			
			virtual void remove()=0;



	};
}

#endif
