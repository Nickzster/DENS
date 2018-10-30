#include <iostream>

#include "fx.h"
#include "em.h"
#include "rk4.h"
#include "abm.h"

using namespace std;
using namespace DENS;

int main()
{
	cout << "This is a DEMO of the DENS tools." << endl;
	cout << "This program will take you through each method, allow you to name the output excel file," << endl;
	cout << "And let you compare the results. For optimal testing results, use the same X(0), Y(0), Terminal, and h (step-size) values." << endl;
	cout << "Let's begin ================================" << endl;
	cout << "Euler's Method" << endl;
	em e(1.0,5.0,0.05, 5.0, false); //Initalize by constructor. Currently glitched.
	//e.initalize(); //Initalize by user input. 
	e.method(); //Runs and calculates the values based on the input. Stores in a vector.
	e.printValues(); //Prints the values to a file. Recommended use: .xls
	cout << "Euler's Improved Method" << endl;
	em eim(1.0,5.0,0.05, 5.0, true);
	eim.improve(); //Specific to Euler's Method class. Call the improve function to upgrade the Euler's Method to Euler's Improved method.
	//eim.initalize();
	eim.method(); 
	eim.printValues();
	cout << "RK4 Method" << endl;
	rk4 r(1.0,5.0,0.05, 5.0);
	//r.initalize();
	r.method();
	r.printValues();
	cout << "ABM Method" << endl;
	abm a(1.0,5.0,0.05, 5.0);
	//a.initalize();
	a.method();
	a.printValues();
	return 0;
}