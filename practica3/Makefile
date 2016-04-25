OBJECTS = donante.o donantes.o 
CPPFLAGS = -c -g -ansi -Wall

all: Monticulo

Monticulo: main.o
	g++ main.o -o Monticulo
	
main.o: main.cpp donanteinterfaz.hpp donante.hpp menuDonante.hpp cabecera.hpp nodo.hpp monticuloDonantes.hpp monticuloDonantesInterfaz.hpp
	g++ $(CPPFLAGS) main.cpp

clean:
	rm -f *.o


