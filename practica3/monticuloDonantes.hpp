#ifndef MONTICULODONANTES_HPP
#define MONTICULODONANTES_HPP

#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream> //para cazar las líneas del fichero.
#include "monticuloDonantesInterfaz.hpp"
#include "donante.hpp"

using std::ifstream;
using std::stringstream;
using std::ofstream;
using std::swap;
using std::string;

namespace ed{

	class MonticuloDonantes : public MonticuloDonantesInterfaz{

		private:
			
			vector<Donante> _v; 							//vector dinámico stl

	        /*! 
	            \brief Obten la posición del hijo izquierdo
	            \param i de tipo int
	            \pre El Montículo debe existir.
	            \post Ninguna
	            \sa leftChild()
	        */			
			int leftChild(int i){							// averigua el hijo izqdo
				return i*2+1;
			}

	        /*! 
	            \brief Obten la posición del hijo derecho
	            \param i de tipo int
	            \pre El Montículo debe existir.
	            \post Ninguna
	            \sa rightChild()
	        */				
			int rightChild(int i){							// averigua el hijo drcho
				return i*2+2;
			}

	        /*! 
	            \brief Obten la posición del padre
	            \param i de tipo int
	            \pre El Montículo debe existir.
	            \post Ninguna
	            \sa parent()
	        */	
			int parent(int i){ 								// averigua el padre
				return (i-1)/2;
			}		

	        /*! 
	            \brief Sube al donante en la lista hasta encontrar su posición.
	            \param i de tipo int
	            \pre El Montículo debe existir.
	            \post Ninguna
	            \sa shiftUp()
	        */
			void shiftUp(int i){
				if((i>0) && (_v[i]<=_v[parent(i)])){ 		//si el padre es mayor que el hijo se intercambian, el i>0 para la recursividad
					swap(_v[i],_v[parent(i)]);		
					shiftUp(parent(i));						//llamada recursiva para comprobar que el padre es menor que el hijo				
				}
			}

	        /*! 
	            \brief Baja al donante en la lista hasta encontrar su posición.
	            \param i de tipo int
	            \pre El Montículo debe existir.
	            \post Ninguna
	            \sa shiftDown()
	        */
			void shiftDown(int i){
				int n = i;
				int lc = leftChild(i);						//Obtiene la posición del hijo izqdo
				int rc = rightChild(i);						//Obtiene la posición del hijo dcho
				if( lc < lastItem() && _v[lc] <= _v[n])		//Si las donaciones del hijo izqdo son menores, marca para bajar al donante y subir al hijoIzqdo
					n = lc;
				if(rc < lastItem() && _v[rc] <= _v[n])		//Si las donaciones del hijo dcho son menores, marca para bajar al donante y subir al hijoDcho
					n = rc;
				if(i != n){
					swap(_v[i], _v[n]);						//Aquí es donde realiza la bajada
					shiftDown(n);							//Sigue recursivamente para abajo
				}
			}

	        /*! 
	            \brief Devuelve el número de posición del último donante.
	            \pre El Montículo debe existir.
	            \pre El Montículo no debe estar vacío.
	            \post Ninguna
	            \sa shiftDown()
	        */
			int lastItem(){
				return _v.size()-1;
			}			

		public:
	        /*! 
	            \brief Obtiene el primer donante del montículo
	            \pre El Montículo debe existir.
	            \pre El Montículo no debe estar vacío.
	            \post Ninguna
	            \sa top()
	        */
			Donante top() const{					//en la diapo top, en la práctica cima
				assert (!isEmpty());
				return _v.front();
  			}
			
	        /*! 
	            \brief Comprueba si el montículo está vacío.
	            \pre El Montículo debe existir.
	            \post Ninguna
	            \sa isEmpty()
	        */
			bool isEmpty()const {					//en la diapo isEmpty, en la práctica vacía
				return _v.empty();
			}

	        /*! 
	            \brief Busca un donante en la lista
	            \param d de tipo Donante
	            \pre El Montículo debe existir.
	            \post Ninguna
	            \sa has()
	        */
			bool has(Donante d){					//busca un donante	
				int i=0;

				while(i<_v.size()){ 
					if(_v[i] == d)
						return true;
					i++;
				}
			return false;
			}

	        /*! 
	            \brief Inserta un donante en la lista ordenándolo hacia abajo.
	            \param d de tipo Donante
	            \pre El Montículo debe existir.
	            \post Ninguna
	            \sa insertarDonante()
	        */
			void insertarDonante(Donante &d){			//inserta un donante
				if(isEmpty()){							//si la lista está vacía
					
					
					_v.push_back(d);					//insertalo
					
				}
				else{									//si la lista no está vacía
					if(!has(d)){						//si no está repetido
						_v.push_back(d);
						shiftUp(_v.size()-1);
					}
					else
						cout << "La persona ya está introducida." << endl;
				}
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

				ifstream bbddEntrada(nombreFichero.c_str());	//Toma el fichero en bbddEntrada

				if(!bbddEntrada)
					return false;								//Si no existe devuelve false para meterlo en un while

				else{
					while (getline(bbddEntrada, linea))
					{
					    stringstream lineaCompleta(linea);		//Toma la línea para poder "trocearla"

					    getline(lineaCompleta, apellidos, ';');	//Toma todo lo que haya antes del primer ; y lo guarda en apellidos
					    getline(lineaCompleta, nombre, ';');	//...
					    getline(lineaCompleta, grupo, ';');		
					    getline(lineaCompleta, factor, ';');
					    getline(lineaCompleta, donaciones, '\n');

						D.setApellidos(apellidos);				//Rellena el donante con sus datos.
						D.setNombre(nombre);
						D.setGrupo(grupo);
						D.setFactor(factor);
						D.setDonaciones(atoi(donaciones.c_str()));

						insertarDonante(D); 					//Inserta el donante en el montículo
					}

					bbddEntrada.close(); 						//Cierra el archivo
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

	        /*! 
	            \brief Muestra todos los donantes por orden en su vector
	            \pre El Montículo debe existir.
	            \post Ninguna
	            \sa mostrar()
	        */
			void mostrar(){

				for(int i = 0; i < _v.size(); i++)
				  	cout << _v[i];
	
			}

	        /*! 
	            \brief Elimina el donante de la cima
	            \pre El Montículo debe existir.
	            \post Ninguna
	            \sa remove()
	        */			
			void remove(){
				assert(!isEmpty());
				if(lastItem() > 0){				//Si es mayor q 0, la nueva cabeza es el último
					_v[0] = _v[lastItem()];		
					_v.pop_back();				//Borra el último
					shiftDown(0);				//Bájalo hasta su posición
				}
				else if(lastItem() == 0)
					_v.pop_back();
			}

	        /*! 
	            \brief Añade donaciones al Donante que esté en la cima.
	            \pre El Montículo debe existir.
	            \param veces de tipo int.
	            \post Ninguna
	            \sa aniadeDonacion()
	        */
			void aniadeDonacion(int veces){
				assert(!isEmpty());
				Donante D;
				for(int i = 0; i < veces; i++){
					D = top();
					D.setDonaciones(D.getDonaciones()+1);
					remove();
					insertarDonante(D);
				}
			}

	};

}

#endif
