#ifndef MONTICULODONANTES_HPP
#define MONTICULODONANTES_HPP

#include "monticuloDonantesInterfaz.hpp"


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
				assert(!isEmpty());
			
				int i=0;

				while(i<_v.size()){ //Aqui va _lastItem 
					if(_v[i]==d){
						return true;
					}
					i++;
				}
			return false;
			}


			void insert(Donante d){
					
				//assert (!isFull());
				bool enc;

				enc = has(d);

				if(!enc){
//					string n;
//					cout << "Introduzca el factor\t..: " << endl;
//					cin >> n;
//					d.setFactor(n);
//					cout << "Introduzca el grupo\t..: " << endl;
//					cin >> n;
//					d.setGrupo(n);
					_v.push_back(d);
					shiftUp(_v.size()-1);
				}
				else
					cout << "La persona ya está introducida." << endl;
			}

			
			void crear(string nombreF){

				ifstream entrada(nombreF.c_str());
				char nombre[50], apellidos[50], grupo[50], rh[50], donacion[50];				

				Donante d;

				while( entrada.getline(nombre,256,',') )
				{
					  entrada.getline(apellidos,256,',');
					  entrada.getline(grupo,256,',');
					  entrada.getline(rh,256,',');
					  entrada.getline(donacion,256,'\n');

					  d.setNombre(nombre);
					  d.setApellidos(apellidos);
					  d.setGrupo(grupo);
					  d.setRH(rh);
				          d.setDonacion(atoi(donacion));
					 
					  insert(d);
				}
				entrada.close();



			}

			void grabar(string nombreF){

				ofstream salida(nombreF.c_str());
				Donante d;
				for(int i=0; i< _v.size(); i++){
				
				  	salida<<_v[i].getNombre()<<","<< _v[i].getApellidos()<<","<<_v[i].getGrupo()<<","<<_v[i].getRH()<<","<<_v[i].getDonacion()<<endl;
					 
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
