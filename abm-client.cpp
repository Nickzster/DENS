#include <iostream>

#include "fx.h"
#include "rk4.h"
#include "abm.h"

using namespace std;
using namespace DENS;

int main()
{
	cout << "ABM Method" << endl;
	abm a(1,5,0.05, 5);
	a.initalize();
	a.method();
	a.printValues();
	return 0;
}