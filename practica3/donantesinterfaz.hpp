#ifndef __DONANTES_INTERFAZ_HPP_
#define __DONANTES_INTERFAZ_HPP_
#include "donante.hpp"

namespace ed{
	//!  Definición de la plantilla de la clase Donantes
	class DonantesInterfaz{
		public:
	        /*! 
	            \brief inserta un objeto Donante en la lista, definición virtual pura
	            \param x por referencia, de tipo Donante
	            \pre El Donante debe existir
	            \post Ninguna
	            \sa insertarDonante()
	        */
			virtual void insertarDonante(Donante &x) = 0;

	        /*! 
	            \brief elimina un Donante de la lista, definición virtual pura
	            \param D de tipo Donante
	            \pre El Donante debe existir.
	            \post Ninguna
	            \sa delDonante()
	        */
			virtual bool delDonante(Donante D) = 0;

	        /*! 
	            \brief busca un Donante de la lista, definición virtual pura
	            \param x de tipo Donante por referencia.
	            \pre El Donante debe existir.
	            \post Ninguna
	            \sa buscarDonante()
	        */
			virtual bool buscarDonante(Donante &x) = 0;

	        /*! 
	            \brief Devuelve si la lista está vacía, definición virtual pura
	            \pre El Fichero debe existir.
	            \post Ninguna
	            \sa estaVacia()
	        */
			virtual bool estaVacia() const = 0;
	};
}

#endif
