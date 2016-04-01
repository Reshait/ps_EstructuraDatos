#ifndef __NODO_HPP__
#define __NODO_HPP__
#include "donante.hpp"

namespace ed{
	class Nodo{
		private:
			Donante data_;
			Nodo *sig_;

		public:
			Nodo(Donante &x){
				data_ = x;
				sig_ = 0;
			}

			void setNext(Nodo *aux){
				sig_ = aux;
			}

			Nodo * next() const {
				return sig_;
			}

			Donante getData(){
				return data_;
			}

			void setItem(Donante D){
				data_ = D;
			}
	};
}

#endif