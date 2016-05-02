#ifndef __LADO_HPP__
#define __LADO_HPP__

#include "vertice.hpp"

namespace ed{
	class Lado{
		private:
			double distancia_;			//Distancia entre dos vértices
			Vertice inicio_;			//Vertice de partida
			Vertice fin_; 				//Vertice de llegada
		public:
			inline const double getDistancia() const{ return distancia_; }
			inline Vertice getInicio() const{ return inicio_; }
			inline Vertice getFin() const{ return fin_; }

			inline void setDistancia(double distancia) {distancia_ = distancia; }
			inline void setInicio(Vertice inicio) {inicio_ = inicio; }
			inline void setFin(Vertice fin){fin_ = fin; }

			inline const bool operator==(const Lado &L){ return getInicio() == L.getFin(); }
			inline const bool tiene(Vertice &V){ return V == getInicio() || V == getFin(); }
			inline const Vertice otro(Vertice &V){ 
				Vertice aux;
				if (V == getInicio())
					aux = getFin();
					//return getFin();
				else if(V == getFin())
					aux = getInicio();
					//return getInicio();
				return aux;
			}

	};
}

#endif