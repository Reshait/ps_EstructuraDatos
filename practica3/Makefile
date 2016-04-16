OBJECTS = donante.o donantes.o 
CPPFLAGS = -c -g -ansi -Wall

all: donante donantes

donante: main.o
	g++ main.o -o donante
	
donantes: main2.o
	g++ main2.o -o donantes

main2.o: main2.cpp donantesinterfaz.hpp donantes.hpp donante.hpp menuDonantes.hpp cabecera.hpp
	g++ $(CPPFLAGS) main2.cpp 
	
main.o: main.cpp donanteinterfaz.hpp donante.hpp menuDonante.hpp cabecera.hpp
	g++ $(CPPFLAGS) main.cpp

clean:
	rm -f *.o


