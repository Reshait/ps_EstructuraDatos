/*! 
  \file     lado.hpp
  \brief    Lado representa la clase lado definida para hacer los lados de la matriz de adyacencia
  \author   Teófilo Rojas Mata
  \date     16/05/2016
*/

#ifndef __LADO_HPP__
#define __LADO_HPP__

#include "vertice.hpp"

namespace ed{
    //!  Definición de la clase Lado
	class Lado{
        //! \name Atributos privados de la clase Lado (distancia_, inicio_, fin_)
		private:
			double distancia_;			//Distancia entre dos vértices
			Vertice inicio_;			//Vertice de partida
			Vertice fin_; 				//Vertice de llegada

	    //! \name Métodos públicos de la clase Lado     	
		public:
            //! \name Funciones de obtención de datos de Lado
            /*! 
                \brief Devuelve la distancia de un Lado
                \return componente distancia_ del Lado
                \pre El LAdo debe existir
                \post Ninguna
                \sa getDistancia()
            */			
			inline const double getDistancia() const{ return distancia_; }

            /*! 
                \brief Devuelve el Vertice inicio_ de un Lado
                \return componente inicio_ del Lado
                \pre El Lado debe existir
                \post Ninguna
                \sa getInicio()
            */					
			inline Vertice getInicio() const{ return inicio_; }

            /*! 
                \brief Devuelve el Vertice fin_ de un Lado
                \return componente fin_ del Lado
                \pre El Lado debe existir
                \post Ninguna
                \sa getFin()
            */				
			inline Vertice getFin() const{ return fin_; }

            //! \name Funciones de modificación de Lado
            /*! 
                \brief Asigna un valor "distancia" a la coordenada "distancia_" de un Lado
                \param distancia de tipo double
                \pre El Lado debe existir
                \post Ninguna
                \sa setDistancia()
            */
			inline void setDistancia(double distancia) {distancia_ = distancia; }

            /*! 
                \brief Asigna un valor "inicio" a la coordenada "inicio_" de un Lado
                \param inicio de tipo Vertice
                \pre El Lado debe existir
                \post Ninguna
                \sa setInicio()
            */			
			inline void setInicio(Vertice inicio) {inicio_ = inicio; }

            /*! 
                \brief Asigna un valor "fin" a la coordenada "fin_" de un Lado
                \param fin de tipo Vertice
                \pre El Lado debe existir
                \post Ninguna
                \sa setFin()
            */				
			inline void setFin(Vertice fin){fin_ = fin; }

            /*! 
                \brief Sobrecarga del operador == para poder comparar LAdos.
                \param L de tipo Lado por referencia
                \pre El Lado debe existir
                \post Ninguna
                \sa operator==()
            */ 
			inline const bool operator==(const Lado &L){ return getInicio() == L.getFin(); }

            /*! 
                \brief Comprueba que un lado posee a un determinado Vertice
                \param V de tipo Vertice por referencia
                \pre El Lado debe existir
                \post Ninguna
                \sa tiene()
            */ 			
			inline const bool tiene(Vertice &V){ return V == getInicio() || V == getFin(); }

            /*! 
                \brief Comprueba el otro Vertice de un Vertice de un Lado
                \param V de tipo Vertice por referencia
                \pre El Lado debe existir
                \post Ninguna
                \sa otro()
            */ 				
			inline const Vertice otro(Vertice &V){ 
				Vertice aux;
				if (V == getInicio())
					aux = getFin();
				else if(V == getFin())
					aux = getInicio();
				return aux;
			}

	};
}

#endif