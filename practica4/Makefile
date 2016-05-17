CPPFLAGS = -c -g -ansi -Wall

all: main

main: main.o
	g++ main.o -o main
	
main.o: main.cpp funciones.hpp grafo.hpp vertice.hpp lado.hpp 
	g++ $(CPPFLAGS) main.cpp

clean:
	rm -f *.o


