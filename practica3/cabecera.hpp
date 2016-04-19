/*! 
  \file     cabecera.hpp
  \brief    Cabecera es la combinación de colores ideal para la presentación de la práctica en todos sus apartados, tanto donante.hpp como donantes.hpp
  \author   Teófilo Rojas Mata
  \date     10/04/2016
*/

#ifndef __CABECERA_HPP__
#define __CABECERA_HPP__
#include <iostream>

/*!
   \brief Partes necesiaras de espacio de nombres para la asignatura de Estructura de datos.
*/
using std::cout;
using std::endl;

/*! 
  \brief Muestra la cabecera de la práctica3 con mis datos personales.
  \post Ninguna
  \sa cabecera()
  \param x, entero con el número de la práctica
*/
void cabecera(int x){
    system("clear");
    system("tput bold");
    system("tput setab 12");

    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃ Teófilo Rojas Mata, Práctica " << x << " de Estructura de Datos ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
    system("tput sgr0");

    cout << endl;
}
#endif
