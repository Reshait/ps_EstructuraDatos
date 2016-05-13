#ifndef ALGORITMOS_HPP
#define ALGORITMOS_HPP
#include "graph_matrix.hpp"
using namespace edi;
void reservarMatriz(int tam,double **m);
void reservarMatriz(int tam,int **m);
void Floyd(GraphMatrix * &g,double **distancias,int **intermedios);
void camino(GraphMatrix *g,Vertex &origen,Vertex &destino,int ** intermedios);
void recorridoProfundidad(GraphMatrix *g, Vertex nodo, bool *visitado);
#endif
