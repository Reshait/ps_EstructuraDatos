/*! 
  \file		ponomio.hpp
  \brief 	Polinomio representa la clase polinomio definida por la interfaz polinomiointerfaz.hpp
  \author 	Teófilo Rojas Mata
  \date 	13/03/2016
*/

#ifndef __POLINOMIO_HPP__
#define __POLINOMIO_HPP__
#include <cassert>
#include <string>
#include <list>
#include <algorithm> //Para poder usar la función sort y unique
#include "polinomiointerfaz.hpp"
#include "monomio.hpp"

/*!
   \brief Partes necesiaras de espacio de nombres para la asignatura de Estructura de datos.
*/
using std::string;
using std::sort;

//Tiene que estar antes de la clase, para que la pille la función ordenaPolinomio
//!  Funciones para Ordenar e Igualar
bool ordenaGrados (const Monomio mayor, const Monomio menor) { return (mayor.getGrado() > menor.getGrado()); }
bool sonIguales(const Monomio m1, const Monomio m2){ return m1.getCoeficiente() == m2.getCoeficiente() && m1.getGrado() == m2.getGrado();}

//!  Definición de la plantilla de la clase Ponomio
class Polinomio:public ed::PolinomioInterfaz{
	//! \name Atributos privados de la clase Ponomio (numero de monomios, grado y la lista de monomios)
    private:
        int grado_;
        int numMonomios_;
        list<Monomio> lista_;

    //! \name Métodos públicos de la clase Polinomio    
    public:
    	//! \name Constructores de la clase Polinomio
		/*! 
		\brief Constructor que crea un Polinomio a partir de su numero de monomios y grado
		\attention Función sobrecargada        
	 	\note Los parámetros tienen valores por defecto
		\param grado valor por defecto 0
		\param numero de monomios valor por defecto 1
		\pre Ninguna
		\post Ninguna
		\sa setNumMonomios(), setGrado()
		*/
        Polinomio(int grado = 0, int numMonomios = 1){
            setGrado(grado);
            setNumMonomios(numMonomios);
        }

	/*! 
		\brief Constructor de "copia" que crea un Polinomio a partir de otro Monomio
		\attention Función sobrecargada        
		\param p de tipo Polinomio pasado como referencia constante
		\pre El Polinomio q debe existir
		\post Ninguna
		\sa setNumMonomios(), setGrado(), setList()
	*/
        Polinomio(const Polinomio &p){
            setGrado(p.getGrado());
            setNumMonomios(p.getNumMonomios());
            setList(p.getList());
        }

       	//! \name Funciones de obtención de Polinomio

	/*! 
		\brief Devuelve el grado de un Polinomio
		\return componente "grado_" del Polinomio
		\pre El Polinomio debe existir
		\post Ninguna
	*/       	
        int getGrado() const{ return grado_; }

	/*! 
		\brief Devuelve el número de Monomios
		\return componente "numMonomios_" del Polinomio
		\pre El Polinomio debe existir
		\post Ninguna
	*/ 
        int getNumMonomios() const{ return numMonomios_;}

	/*! 
		\brief Devuelve la lista de forma constante del polinomio. Función virtual pura
		\return componente "lista_" del Polinomio
		\pre El Polinomio debe existir
		\post Ninguna
	*/         
        list<Monomio> getList() const{
            return lista_;
        }

	/*! 
		\brief Devuelve la lista del polinomio.
		\return componente "lista_" del Polinomio
		\pre El Polinomio debe existir
		\post Ninguna
	*/
        list<Monomio> &getListForChange(){
            return lista_;
        }

       	//! \name Funciones de modificación de Monomio
       	
	/*! 
		\brief Asigna un valor "grado" a la coordenada "grado_" de un Polinomio
		\param grado de tipo int
		\pre El Polinomio debe existir
		\post Ninguna
		\sa setGrado()
	*/
        void setGrado(int grado){
            grado_ = grado;
        }
        
	/*! 
		\brief Asigna un valor "numMonomios" a la coordenada "numMonomios_" de un Polinomio
		\param grado de tipo int
		\pre El Polinomio debe existir
		\post Ninguna
		\sa setNumMonomios()
	*/
        void setNumMonomios(int numMonomios){
            numMonomios_ = numMonomios;
        }

	/*! 
		\brief Asigna un valor "lista" a la coordenada "lista_" de un Polinomio
		\param grado de tipo list<Monomio>
		\pre El Polinomio debe existir
		\post Ninguna
		\sa setNumMonomios()
	*/
        void setList(list<Monomio> lista){
            lista_ = lista;
        }

	/*! 
		\brief Añade un monomio a la "lista_" de un Polinomio
		\param monomioAintroducir de tipo Monomio
		\pre El Polinomio debe existir
		\post Ninguna
		\sa setNumMonomios()
	*/        
        void aniadeMonomioAlista(Monomio monomioAintroducir){
            lista_.push_back(monomioAintroducir);
        }

       	//! \name Funciones de información de Monomio

	/*! 
		\brief Indica si la lista está vacía.
		\pre El Polinomio debe existir
		\post Ninguna
		\sa getList()
	*/ 
        bool vacio() const{
            return getList().empty();
        }

	/*! 
		\brief Busca si el monomio está en la lista ya incluído.
		\param monomioAencontrar de tipo Monomio
		\pre El Polinomio debe existir
		\post Ninguna
		\sa getList()
	*/
        bool encuentraMonomio(Monomio monomioAecontrar){
            list<Monomio>::iterator i;
            list<Monomio> aux = getList();

            for(i = aux.begin(); i != aux.end(); i++)
                if(monomioAecontrar == *i)//operador == sobrecargado en monomio.hpp
                    return true;
            return false;
        }

	//! \name Funciones lectura y escritura de la clase Monomio      
	
	/*! 
		\brief Asigna a un Polinomio los monomios introducidos por el teclado
		\pre El Polinomio debe existir
		\post Ninguna
		\warning Se deben teclear números flotante/coeficiente y entero/grado
		\sa leerMonomio(), getList(), encuentraMonomio(), aniadeMonomioAlista(), ordenaPolinomio()
	*/	
        void leerPolinomio(){
            string opcionMenu;
            Monomio aux;

            do{
                aux.leerMonomio();
                if(!getList().empty()){
                    if(encuentraMonomio(aux))
                        cout << "El grado introducido ya está ocupado, por favor, introduzca un polinomio de otro grado" << endl;
                    else
                        aniadeMonomioAlista(aux);
                }
                else
                    aniadeMonomioAlista(aux);
                
                cout << "Introduzca [s/S] para salir, cualquier otra letra o número para introducir otro monomio..: ";
                cin >> opcionMenu;
            }while(opcionMenu != "s" && opcionMenu != "S");
            this->ordenaPolinomio();
        }

	/*! 
		\brief Asigna a un Polinomio los monomios introducidos por el teclado, sobrecargando el operador de flujo >>
		\pre El Polinomio debe existir
		\post Ninguna
		\warning Se deben teclear números flotante/coeficiente y entero/grado
		\sa leerMonomio(), getList(), encuentraMonomio(), aniadeMonomioAlista(), ordenaPolinomio()
	*/
        friend istream &operator>>(istream &stream, Polinomio &P){
            string opcionMenu;
            Monomio aux;

            do{
                aux.leerMonomio();
                if(!P.getList().empty()){
                    if(P.encuentraMonomio(aux))
                        cout << "El grado introducido ya está ocupado, por favor, introduzca un polinomio de otro grado" << endl;
                    else
                        P.aniadeMonomioAlista(aux);
                }
                else
                    P.aniadeMonomioAlista(aux);
                
                cout << "Introduzca [s/S] para salir, cualquier otra letra o número para introducir otro monomio..: ";
                cin >> opcionMenu;
            }while(opcionMenu != "s" && opcionMenu != "S");
            P.ordenaPolinomio();
            
            return stream;
        }

	/*! 
		\brief Imprime por pantalla la lista de Monomios que componen el Polinomio.
		\pre El Polinomio debe existir
		\post Ninguna
		\sa getList(), getCoeficiente()
	*/
        void escribirPolinomio(){
            list<Monomio>::iterator i;
            int contador = 0;
            if(getList().empty())
                cout << "Su polinomio está vacío" << endl;
            else{
                for(i = lista_.begin(); i !=  lista_.end(); i++){

                    if(i != getList().begin() && i->getCoeficiente() >= 0)
                        if(contador != 0 && i->getCoeficiente() >= 0)
                            cout << "+ ";
                    cout << *i << " ";
                    contador++;
                }
                cout << endl;
            }
        }

	/*! 
		\brief Imprime por pantalla la lista de Monomios que componen el Polinomio Sobrecargando el operador de flujo <<.
		\pre El Polinomio debe existir
		\post Ninguna
		\sa getList(), getCoeficiente()
	*/        
        friend ostream &operator<< (ostream &salida, const Polinomio &P){
            list<Monomio>::const_iterator i;
            int contador = 0;
            if(P.getList().empty())
                salida << "Su polinomio está vacío" << endl;
            else{
                for(i = P.lista_.begin(); i !=  P.lista_.end(); i++){

                    if(i != P.lista_.begin() && i->getCoeficiente() >= 0)
                        if(contador != 0 && i->getCoeficiente() >= 0)
                            salida << "+ ";
                    salida << *i << " ";
                    contador++;
                }
                //salida << endl;
            }
            return salida;
        }

	//! \name Sobrecargas de operadores =, +, *, == para operaciones entre Monomios
	
	/*! 
		\brief Asigna a un Polinomio auxiliar la suma de dos Polinomios
		\attention Función sobrecargada        
		\pre Los Polinomios deben existir
		\post Ninguna
		\param tipo Polinomio "recibido"
		\sa setGrado(), setCoeficiente(), getGrado(), getCoeficiente(), getList(), aniadeMonomioAlista(), setNumMonomios
	*/	
        Polinomio operator+(Polinomio recibido){
            list<Monomio>::iterator i1, i2;
            Polinomio resultado;
            
            if(this->getGrado() < recibido.getGrado())
                resultado.setGrado(recibido.getGrado());
            else
            	resultado.setGrado(this->getGrado());
           
           resultado.setList(this->getList());

           for(i2 = recibido.lista_.begin(); i2 != recibido.lista_.end(); i2++){
	            bool encontrado = false;
	            
	            for(i1 = resultado.lista_.begin(); i1 != resultado.lista_.end(); i1++){
                    if(i1->getGrado() == i2->getGrado()){
                        i1->setCoeficiente(i1->getCoeficiente() + i2->getCoeficiente());
                    	encontrado = true;
                    }
                }
                
                if(!encontrado)
                	resultado.aniadeMonomioAlista(*i2);
            }            	
           
            resultado.setNumMonomios(resultado.lista_.size());
            return resultado;
        }

	/*! 
		\brief Asigna a un Polinomio la suma de otros 2 polinomios
		\attention Función sobrecargada        
		\pre El Polinomio debe existir
		\post Ninguna
		\param tipo Monomio, constante y por referencia "recibido"
		\sa setGrado(), setCoeficiente(), getGrado(), getCoeficiente()
	*/        
        Polinomio operator+(Monomio recibido){
            list<Monomio>::iterator i1;
            Polinomio resultado;
            bool encontrado;
            
            if(this->getGrado() < recibido.getGrado())
                resultado.setGrado(recibido.getGrado());
            else
            	resultado.setGrado(this->getGrado());
           
           resultado.setList(this->getListForChange());

            for(i1 = resultado.lista_.begin(); i1 != resultado.lista_.end(); i1++){
	            if(i1->getGrado() == recibido.getGrado()){
	                i1->setCoeficiente(i1->getCoeficiente() + recibido.getCoeficiente());
					encontrado = true;
				}
            }   
            
            if(!encontrado)
            	resultado.aniadeMonomioAlista(recibido);     	
           
            resultado.setNumMonomios(resultado.lista_.size());
            return resultado;
        }

	/*! 
		\brief Multiplica el valor de un Polinomio por otro Polinomio
		\pre Los Polinomios deben existir
		\post Ninguna
		\param tipo Polinomio, por referencia "recibido"
		\sa aniadeMonomioAlista()
	*/
        Polinomio operator*(Polinomio recibido){
            list<Monomio>::iterator i1, i2;
            Polinomio auxiliar, auxiliar2;

            for(i1 = this->lista_.begin(); i1 != this->lista_.end(); i1++){
                for(i2 = recibido.lista_.begin(); i2 != recibido.lista_.end(); i2++){
                    auxiliar.aniadeMonomioAlista( (*i1) * (*i2) );
                }
            }

            auxiliar.ordenaPolinomio();
            auxiliar.setGrado(auxiliar.getList().begin()->getGrado());

            //Suma de polinomios del mismo grado en la lista
            for(int i = auxiliar.getGrado(); i > 0; i--){
                Monomio mAux(0,i);

                for(i1 = auxiliar.lista_.begin(); i1 != auxiliar.lista_.end(); i1++){
                    if( i1->getGrado() == i)
                        if(i1->getCoeficiente() != 0)
                            mAux.setCoeficiente(mAux.getCoeficiente()+i1->getCoeficiente());
                }
                if(mAux.getCoeficiente() != 0)
                    auxiliar2.aniadeMonomioAlista(mAux);
            }

            return auxiliar2;
        }

	/*! 
		\brief Suma a un Polinomio el valor completo de otro Polinomio
		\pre El Polinomio debe existir
		\post Ninguna
		\sa setGrado(), setList(), setNumMonomios()
	*/
        Polinomio& operator=(Polinomio recibido){
            this->setGrado(recibido.getGrado());
            this->setNumMonomios(recibido.getNumMonomios());
            this->setList(recibido.getList());

            return *this;
        }
 
 
	/*! 
		\brief Ordena a un Polinomio 
		\pre El Polinomio debe existir
		\post Ninguna
		\sa getLisfForchange(), sort()
	*/       
        void ordenaPolinomio(){
            getListForChange().sort(&ordenaGrados);
        }

	/*! 
		\brief Elimina los monomios repetidos en un Polinomio 
		\pre El Polinomio debe existir
		\post Ninguna
		\sa getLisfForchange(), unique()
	*/         
        void eliminaRepetidos(){
            getListForChange().unique(&sonIguales);
        }

	/*! 
		\brief Resuelve un Polinomio con el valor pasado
		\pre El Polinomio debe existir
		\post Ninguna
		\param tipo double "valorX", con el valor de resolución
		\sa resuelveMonomio()
	*/        
        double resuelvePolinomio(double valorX){
        	list<Monomio>::iterator i;
        	double resultado = 0;
        	
        	for(i = lista_.begin(); i != lista_.end(); i++){
        		resultado += i->resuelveMonomio(valorX);		
        	}
        	
        	return resultado;
        }
        
};// Fin de la definición de la clase Monomio y del namespace ed

	/*! 
		\brief Menú de selección
	*/
int menuPolinomio(){
    int opcion = -1;

    do{
        cabeceraEjercicios();
        cout << "1.- Obtener el valor de un Polinomio para un dato concreto de X." << endl;
        cout << "2.- Obtener la suma de dos Polinomios." << endl;
        cout << "3.- Obtener la multiplicación de dos Polinomios." << endl;
        cout << "4.- Leer y escribir polinomio." << endl;
        cout << "0.- Salir sin hacer nada." << endl;
        cout << endl;

        cout << ">> Introduzca la opción deseada..: ";
        cin >> opcion;
        if(opcion == 0)
            cout << "Saliendo..." << endl;
        if(opcion < 0 || opcion > 4){
            system("tput setaf 1");
            cout << "Error de opcion." << endl;
            system("tput sgr0");
            cout << "Presione intro para continuar..." << endl;
            cin.ignore();
            cin.get();
        }
    }while(opcion < 0 || opcion > 4);

    return opcion;
}

#endif
