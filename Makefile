OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++11

pro2.exe: pro2.o Poblacion.o Individuo.o Cromosoma.o Especie.o
	g++ -o pro2.exe pro2.o Poblacion.o Individuo.o Cromosoma.o Especie.o
	rm *.o

Especie.o: Especie.cc Especie.hh
	g++ -c Especie.cc $(OPCIONS)

Poblacion.o: Poblacion.cc Poblacion.hh Individuo.hh Cromosoma.hh Especie.hh
	g++ -c Poblacion.cc $(OPCIONS)

Individuo.o: Individuo.cc Individuo.hh Cromosoma.hh Especie.hh
	g++ -c Individuo.cc $(OPCIONS)

Cromosoma.o: Cromosoma.cc Cromosoma.hh Especie.hh
	g++ -c Cromosoma.cc $(OPCIONS)

pro2.o: pro2.cc Poblacion.hh Individuo.hh Cromosoma.hh Especie.hh
	g++ -c pro2.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe
	rm *.gch
