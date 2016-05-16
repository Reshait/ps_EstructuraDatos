/*! 
  \file     vertice.hpp
  \brief    Vertice representa la clase vertice definida para hacer los vertices de la matriz de adyacencia
  \author   Teófilo Rojas Mata
  \date     16/05/2016
*/

#ifndef __VERTICE_HPP__
#define __VERTICE_HPP__

#include <iostream>
#include <string>

/*!
   \brief Parte necesiara de espacio de nombres para la asignatura de Estructura de datos.
*/
using std::string;

//!  Espacio de nombre creado para las prácticas de la asignatura de Estructura de Datos.
namespace ed{
    //!  Definición de la clase Vertice
	class Vertice{
        //! \name Atributos privados de la clase Vertice (data, label)
		private:
			string data_;			//datos con el nombre de la ciudad
			int label_;				//etiqueta con el número de la ciudad

	    //! \name Métodos públicos de la clase Vertice     	
		public:
            //! \name Funciones de obtención de datos de Vertice
            /*! 
                \brief Devuelve el nombre de una ciudad del Vertice
                \return componente data_ del Vertice
                \pre El Vertice debe existir
                \post Ninguna
                \sa getData()
            */
			inline const string getData() const { return data_; }

            /*! 
                \brief Devuelve la etiqueta de una ciudad del Vertice
                \return componente label_ del Vertice
                \pre El Vertice debe existir
                \post Ninguna
                \sa getLabel()
            */
			inline const int getLabel() const { return label_; }

            //! \name Funciones de modificación de Vertice
            /*! 
                \brief Asigna un valor "data" a la coordenada "data_" de un Vertice
                \param data de tipo string
                \pre El Vertice debe existir
                \post Ninguna
                \sa setData()
            */
			inline void setData(string data){ data_ = data; }

            /*! 
                \brief Asigna un valor "label" a la coordenada "label_" de un Vertice
                \param data de tipo int
                \pre El Vertice debe existir
                \post Ninguna
                \sa setLabel()
            */
			inline void setLabel(int label){ label_ = label; }

            /*! 
                \brief Sobrecarga del operador == para poder comparar Vertices.
                \param V de tipo Vertice por referencia
                \pre El Vertice debe existir
                \post Ninguna
                \sa operator==()
            */ 
			inline const bool operator==(const Vertice &V){ return getData() == V.getData(); }

            /*! 
                \brief Sobrecarga del operador != para poder comparar Vertices.
                \param V de tipo Vertice por referencia
                \pre El Vertice debe existir
                \post Ninguna
                \sa operator!=()
            */ 			
			inline const bool operator!=(const Vertice &V){ return getData() != V.getData(); }

	};
}

#endif