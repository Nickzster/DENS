#ifndef RK4
#define RK4
#include <iostream>
#include <vector>
#include "fx.h"
using std::vector;

namespace DENS
{
	class rk4 : public Function
	{
	public:
		//Constructors
		rk4();
		// rk4(float xIn, float yIn, float h);
		rk4(float xIn, float yIn, float h, float xTerminal);
		// rk4(float xIn, float yIn, float h, int xTerminal, int p);
		//Functions
		virtual void equals(float xIn, float yIn);
		float rk4Function();
		void method();
		void method(int count);
		//Used for ABM. Returns the value at the given index.
		float getX(int i);
		float getY(int i);
	};
}
#endif