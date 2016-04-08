#ifndef __DONANTES_INTERFAZ_HPP_
#define __DONANTES_INTERFAZ_HPP_
#include "donante.hpp"

namespace ed{
	class DonantesInterfaz{
		public:
			virtual void insertarDonante(Donante &x) = 0;
			virtual bool delDonante(Donante D) = 0;
			virtual bool buscarDonante(Donante &x) = 0;
			virtual bool estaVacia() const = 0;
	};
}

#endif
