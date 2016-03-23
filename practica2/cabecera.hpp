#ifndef __CABECERA_HPP__
#define __CABECERA_HPP__
#include <iostream>

using std::cout;
using std::endl;

void cabecera(){
    system("clear");
    system("tput bold");
    system("tput setab 12");
    cout << "+-------------------------------------------------------+" << endl;
    cout << "| Teófilo Rojas Mata, Práctica 2 de Estructura de Datos |" << endl;
    cout << "+-------------------------------------------------------+" << endl;
    system("tput sgr0");
    cout << endl;
}

#endif