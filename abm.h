#ifndef ABM
#define ABM

#include <iostream>
#include <vector>
#include "fx.h"
namespace DENS
{
	using std::vector;

	class abm : public rk4
	{
	public:
		//Constructors
		abm();
		abm(float xIn, float yIn, float h);
		abm(float xIn, float yIn, float h, int xTerminal);
		abm(float xIn, float yIn, float h, int xTerminal, int p); 
		//Functions
		virtual void equals(float xIn, float yIn);
		float predictor(float y_prime[]);
		float corrector(float y_prime[]);
		//	float abmFunction(); This is the only method that will not have a respective function. All operations are done in method.
		void method();
	};
}
#endif
