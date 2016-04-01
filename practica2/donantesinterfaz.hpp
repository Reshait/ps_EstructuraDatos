#ifndef __DONANTES_INTERFAZ_HPP_
#define __DONANTES_INTERFAZ_HPP_

namespace ed{
	template <class T>
	class DonantesInterfaz{
		virtual void insertarElemento(const T &x) = 0;
		//virtual void borrarElemento() = 0;
		virtual bool buscarElemento(T &x) = 0;
		virtual bool estaVacia() const = 0;
	};
}

#endif