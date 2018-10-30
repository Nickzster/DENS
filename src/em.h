//Class definition for Euler's Method & Euler's Improved Method
//Written by Nick Zimmermann

#ifndef EM
#define EM
#include <iostream>
#include <vector>
using std::vector;
#include "fx.h"
namespace DENS
{
	class em : public Function
	{
	private:
		bool improved;
	public:
		//Constructors
		em();
		// em(float xIn, float yIn, float h);
		em(float xIn, float yIn, float h, int xTerminal, bool improved);
		// em(float xIn, float yIn, float h, int xTerminal, int p);
		//Destructors
		~em();
		//Functions
		void equals(float xIn, float yIn);
		
		float emFunction();
		void method();

		void improve();
	};
}
#endif
