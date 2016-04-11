/*! 
  \file     nodo.hpp
  \brief    Nodo representa el objeto individual que se va a almacenar en la lista.
  \author   Teófilo Rojas Mata
  \date     10/04/2016
*/

#ifndef __NODO_HPP__
#define __NODO_HPP__
#include "donante.hpp"

namespace ed{
	//!  Definición de la clase Donantes
	class Nodo{
	    //! \name Atributos privados de la clase Nodo (data y siguiente)
		private:
			Donante data_;
			Nodo *sig_;

		public:
			//! \name Constructor de la clase Nodo
	        /*! 
	        \brief Constructor que crea un objeto con los datos de Donante inicializados al valor que se le pasa y sin apuntar a nadie.
	        \note Los parámetros tienen valores inicializados a x y apuntado a 0.
	        \param x tipo Donante por referencia
	        \pre Ninguna
	        \post Ninguna
	        */ 
			Nodo(Donante &x){
				data_ = x;
				sig_ = 0;
			}

	        /*! 
	            \brief cambia la dirección de apunte a otro nodo.
	            \param *aux tipo Nodo
	            \pre El Nodo debe existir
	            \post Ninguna
	            \sa setNext()
	        */      
			void setNext(Nodo *aux){
				sig_ = aux;
			}

	        /*! 
	            \brief devuelve la dirección de apunte del nodo.
	            \pre El Nodo debe existir
	            \post Ninguna
	            \sa next()
	        */      
			Nodo * next() const {
				return sig_;
			}

	        /*! 
	            \brief devuelve los datos del Donante que contiene el nodo.
	            \pre El Nodo debe existir
	            \post Ninguna
	            \sa getData()
	        */       
			Donante getData(){
				return data_;
			}

	        /*! 
	            \brief Asigna valor de los datos del Donante que contiene el nodo.
	            \param D tipo Donante
	            \pre El Nodo debe existir
	            \post Ninguna
	            \sa setItem()
	        */   
			void setItem(Donante D){
				data_ = D;
			}
	};
}

#endif
