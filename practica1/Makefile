OBJECTS = polinomio.o monomio.o 
CPPFLAGS = -c -g -ansi -Wall -lm

all: monomio polinomio

monomio: main.o
	g++ main.o -o monomio
	
polinomio: main2.o
	g++ main2.o -o polinomio

main2.o: main2.cpp polinomiointerfaz.hpp polinomio.hpp monomio.hpp
	g++ $(CPPFLAGS) main2.cpp -lm 
	
main.o: main.cpp monomiointerfaz.hpp monomio.hpp
	g++ $(CPPFLAGS) main.cpp -lm

clean:
	rm -f *.o


