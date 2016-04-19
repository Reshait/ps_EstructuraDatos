#ifndef MONTICULODONANTESINTERFAZ_HPP
#define MONTICULODONANTESINTERFAZ_HPP

#include "donante.hpp"
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <fstream>

using std::cin;
using std::cout;
using std::string;
using std::ostream;
using std::istream;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::vector;

namespace ed{

	class MonticuloDonantesInterfaz{

		public:
	
			virtual bool isEmpty() const=0;
			virtual Donante top() const=0;
			virtual void insertarDonante(Donante d)=0;
			//virtual void remove()=0;



	};
}

#endif
