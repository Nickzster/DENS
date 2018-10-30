BUILD: fx.cpp abm.cpp rk4.cpp em.cpp main.cpp
	g++ -std=c++11 -O -o DENS src/fx.cpp src/abm.cpp src/rk4.cpp src/em.cpp src/main.cpp