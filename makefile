CXXFLAGS = -std=c++11

BUILD: src/fx.o src/abm.o src/rk4.o src/em.o src/main.o
	g++ -std=c++11 -O -o DENS src/fx.o src/abm.o src/rk4.o src/em.o src/main.o

fx.o: src/fx.cpp src/fx.h
	g++ -c src/fx.cpp
abm.o: src/abm.cpp src/abm.h
	g++ -c src/abm.cpp
rk4.o: src/rk4.cpp src/rk4.h
	g++ -c src/rk4.cpp
em.o: src/em.cpp src/em.h
	g++ -c src/em.cpp
main.o: src/main.cpp
	g++ -std=c++11 -c src/main.cpp
clean: 
	rm src/*.o DENS