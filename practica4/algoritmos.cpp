#include "algoritmos.hpp"
#include "vertex.hpp"

void Floyd(edi::GraphMatrix * &g,double **distancias,int **intermedios)
{
int i,j,k;
double distanciaT;
Vertex u,v;
string origen,destino;

//Reservamos memoria para las dos matrices
distancias=new double*[g->getTam()];
for(int i=0;i<g->getTam();i++)
distancias[i]=new double[g->getTam()];


intermedios=new int*[g->getTam()];
for(int i=0;i<g->getTam();i++)
intermedios[i]=new int[g->getTam()];



	for(i=0;i<g->getNumV();i++)
	{
		for(j=0;j<g->getNumV();j++)
		{
		intermedios[i][j]=-1;
		if(i==j)
		distancias[i][j]=0;
		else{
		g->goTo(i);
		u=g->verticeActual();
		g->goTo(j);
		v=g->verticeActual();
		distancias[i][j]=g->adyacencia(u,v);}
		}
	}

for(k=0;k<g->getNumV();k++)
{
	for(i=0;i<g->getNumV();i++)
	{
		for(j=0;j<g->getNumV();j++)
		{
			if( distancias[i][j] > ( (distancias[i][k]) + (distancias[k][j]) ) )
			{
			distancias[i][j]=( distancias[i][k]+distancias[k][j] );
			intermedios[i][j]=k;
			}	
		}
	}
}

cout<<"Introduce el primer nodo: ";
cin>>origen;
g->buscarVertice(origen);
u=g->verticeActual();


cout<<"Introduce el segundo nodo: ";
cin>>destino;
g->buscarVertice(destino);
v=g->verticeActual();

	if( distancias[u.getLabel()][v.getLabel()] == 32000 )
	cout<<"No existe distancia mínima"<<endl;
	else
	cout<<"La distancia mínima entre "<<u.getData()<<" y "<<v.getData()<<" es: "<<distancias[u.getLabel()][v.getLabel()]<<endl;

	cout<<"El camino mínimo es: ";
	cout<<origen<<" ";
	camino(g,u,v,intermedios);
	cout<<destino<<endl;

}

void camino(GraphMatrix *g,Vertex &origen,Vertex &destino,int **intermedios){

	if(intermedios[origen.getLabel()][destino.getLabel()] != -1){
		g->goTo(intermedios[origen.getLabel()][destino.getLabel()]);
		Vertex intermedio=g->verticeActual();
		camino(g,origen,intermedio,intermedios);
		cout<<intermedio.getData()<<" ";
		camino(g,intermedio,destino,intermedios);
	}
}


void recorridoProfundidad(GraphMatrix *g, Vertex nodo, bool *visitado)
{
     int i;
     Vertex u;

     visitado[nodo.getLabel()] = true;
     cout << nodo.getData() << " ";
     
     for (i = 0; i < g->getNumV(); i++)
     {
	g->goTo(i);
	u=g->verticeActual();
         if (g->adyacencia(nodo, u) < 32000 && visitado[i] ==  false)
            recorridoProfundidad(g,u,visitado);
     }     
}

