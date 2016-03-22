//Meter en comentarios buscar y borrar para que no de error al compilar.
#ifndef __DONANTES_INTERFAZ_HPP_
#define __DONANTES_INTERFAZ_HPP_

namespace ed{
	template <class G>
	class DonantesInterfaz{
		virtual void insertar(const G &x) = 0;
		//virtual void borarElemento() = 0;
		//virtual bool buscarElemento(G &x) = 0;
		virtual bool estaVacia() const = 0;
	};
}

#endif