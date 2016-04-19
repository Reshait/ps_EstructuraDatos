#ifndef MONTICULODONANTES_HPP
#define MONTICULODONANTES_HPP

#include <cstdlib>
#include <string>
#include <sstream> //para cazar las líneas del fichero.
#include "monticuloDonantesInterfaz.hpp"
#include "donante.hpp"


using std::ifstream;
using std::stringstream;
using std::ofstream;

namespace ed{

	class MonticuloDonantes : public ed::MonticuloDonantesInterfaz{

		private:
			
			vector<Donante> _v; //vector dinámico stl
			
			int leftChild(int i){				// averigua el hijo izqudo
				return i*2+1;
			}
			
			int rightChild(int i){				// averigua el hijo derecho
				return i*2+2;
			}

			int parent(int i){ 					// averigua el padre
				return (i-1)/2;
			}		

			void shiftUp(int i){
				if((i>0) && (_v[i]<=_v[parent(i)])){ //si el padre es mayor que el hijo se intercambian, el i>0 para la recursividad
					std::swap(_v[i],_v[parent(i)]);		
					shiftUp(parent(i));//llamada recursiva para comprobar que el padre es menor que el hijo				
				}
			}

			//int _lastItem;

			/*void shiftDown(int i){
				
				int n=i;

				int lc=leftchild(i);

				int rc=rightChild(i); 

				if((lc < lastItem()) and (_v[lc] > _v[n])){
					n=lc;					
				}
				else if((rc < lastItem()) and (_v[rc] > _v[n])){
					n=rc;					
				}
				else if((lc < lastItem()) and (_v[lc] > _v[n])){
					n=lc;					
				}

				shiftDown(parent(i));
			}*/
			
			

		public:
					
			/*MonticuloDonantes(int lastItem){
				_v.reserve(_lastItem);
				_lastItem=0;
			}*/
			
			/*int getlastItem(){
				_lastItem;
			}
			
			void setlastItem(int lastItem){
				_lastItem=lastItem;
			}*/

			/*bool getVector(){
			
			}
		
			void setVector (Donante d){
		
			}*/

			Donante top() const{					//en la diapo top, en la práctica cima
				assert (!isEmpty());
				return _v.front();
			}
			
			bool isEmpty()const {					//en la diapo isEmpty, en la práctica vacía
				return _v.empty();
			}
			
			/*bool isFull(){
				return _lastItem==_v.size();
			}*/

			bool has(Donante d){
				//assert(!isEmpty());
			
				int i=0;

				while(i<_v.size()){ //Aqui va _lastItem 
					if(_v[i]==d){
						return true;
					}
					i++;
				}
			return false;
			}


			void insertarDonante(Donante d){

				if(!has(d)){
					_v.push_back(d);
					shiftUp(_v.size()-1);
				}
				else
					cout << "La persona ya está introducida." << endl;
			}

			
	        /*! 
	            \brief Carga la base de datos desde un fichero pasado por teclado.
	            \param nombreFichero de tipo string
	            \pre El Fichero debe existir.
	            \post Ninguna
	            \sa cargarBBDD()
	        */
			bool cargarBBDD(string nombreFichero){
				Donante D;
				string linea, apellidos, nombre, grupo, factor, donaciones;

				ifstream bbddEntrada(nombreFichero.c_str());

				if(!bbddEntrada)
					return false;

				else{
					while (getline(bbddEntrada, linea))
					{
					    stringstream lineaCompleta(linea);

					    getline(lineaCompleta, apellidos, ';');
					    getline(lineaCompleta, nombre, ';');
					    getline(lineaCompleta, grupo, ';');
					    getline(lineaCompleta, factor, ';');
					    getline(lineaCompleta, donaciones, '\n');

						D.setApellidos(apellidos);
						D.setNombre(nombre);
						D.setGrupo(grupo);
						D.setFactor(factor);
						int auxiliar = atoi(donaciones.c_str());
						cout << "Donaciones Prueba..: " << auxiliar << endl;
						//D.setDonaciones(atoi(donaciones.c_str()));
						D.setDonaciones(auxiliar);

						insertarDonante(D); 
					}

					bbddEntrada.close(); 
				}
				return true;
			}

	        /*! 
	            \brief Guarda la base de datos a un fichero pasado por teclado.
	            \param nombreFichero de tipo string
	            \post Ninguna
	            \sa guardarBBDD()
	        */
			void guardarBBDD(string nombreFichero){
				
				ofstream bbddSalida(nombreFichero.c_str()); 

				int cont = 0; Donante data;
				while(cont < _v.size()){
				data = _v[cont]; 
					bbddSalida 	<< data.getApellidos() << ";" 
								<< data.getNombre() << ";"
								<< data.getGrupo() << ";"
								<< data.getFactor() << ";"
								<< data.getDonaciones() << "\n";
					cont++;
				}
	

				bbddSalida.close(); 
			}			

			void grabar(string nombreF){

				ofstream salida(nombreF.c_str());
				Donante d;
				for(int i=0; i< _v.size(); i++){
				
				  	salida<<_v[i].getNombre()<<","<< _v[i].getApellidos()<<","<<_v[i].getGrupo()<<","<<_v[i].getFactor()<<","<<_v[i].getDonaciones()<<endl;
					 
				}
				salida.close();



			}
			
			void mostrar(){

				for(int i=0; i< _v.size(); i++){
				
				  	cout<<_v[i];
					 
				}

			}
			
			/*void remove(){

				assert(!isEmpty());


			}*/

	};

}

#endif
