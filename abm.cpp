#include <iostream>
#include <vector>
#include <ostream>
#include <istream>
#include <fstream>
#include "fx.h"
#include "rk4.h"
#include "abm.h"
using namespace std;
namespace DENS
{
	//Constructors
	//Arguments are as follows:
	/*
	p - uses switch selection to select a problem. Defaults to the user's defined problem.
	xIn -> 
	*/
	abm::abm(float xIn, float yIn, float h, int xTerminal, int p)
	{
		this->xIn = xIn;
		this->yIn = yIn;
		this->h = h;
		this->p = p;
	}
	abm::abm(float xIn, float yIn, float h, int xTerminal)
	{

	}
	abm::abm(float xIn, float yIn, float h)
	{
		this->xIn = xIn;
		this->yIn = yIn;
		this->h = h;
		this->p = 0;
		abm(xIn, yIn, h, 0);
	}
	abm::abm() 
	{
		abm(1,1,0.5);
	}


	//Functions
	void abm::equals(float xIn, float yIn)
	{
		this->xIn = xIn;
		this->yIn = yIn;
	}
	float abm::predictor(float y_prime[])
	{
		return this->yvalues.back() + (this->h / 24) * ((55 * y_prime[3]) - (59 * y_prime[2]) + (37 * y_prime[1]) - (9 * y_prime[0]));
	}
	float abm::corrector(float y_prime[])
	{
		return yvalues.back() + (h / 24) * ((9 * y_prime[3]) + (19 * y_prime[2]) - (5 * y_prime[1]) + (y_prime[0]));
	}
	void abm::method()
	{
		//Here's where the fun is going to be at.
		try
		{
			int count = (this->xTerminal - this->xIn) / this->h;
			cout << count << " iterations" << endl;
			float predictY; //Predictor value.
			float y_prime[4]; //y' array. It is adjusted each time this function loops.
			bool initalize = true;
			for (int i = 0; i < count; i++)
			{
				if (initalize)
				{
					rk4 r(this->xIn, this->yIn, this->h);
					r.method(4);
					initalize = false;
					//Since ABM is derived from RK4, we have to put the RK4 values into the ABM method. 
					//rather have a 4-lined for-loop versus an entire copy of the RK4 function in ABM.
					for (int i = 0; i < 4; i++)
					{
						abm::xvalues.push_back(r.getX(i));
						abm::yvalues.push_back(r.getY(i));
					}
				}
				//Step one: Fill in y'
				for (int j = 3; j >= 0; j--)
				{
					y_prime[3 - j] = Eval(this->xvalues.at(this->xvalues.size() - j - 1), this->yvalues.at(this->xvalues.size() - j - 1));
				}
				//Step 2: Make a prediction. 
				predictY = predictor(y_prime);
				//Step 3: Adjust array for y(n+1). Newer values are stored in y_prime[3].
				y_prime[0] = y_prime[1];
				y_prime[1] = y_prime[2];
				y_prime[2] = y_prime[3];
				//Step 4: Adjust for x(n+1)
				xvalues.push_back(xvalues.back() + h);
				//Step 5:  get y'(n+1)
				y_prime[3] = Eval(xvalues.back(), predictY);
				//6. Get corrected value, put it in yvalues. Start over.
				yvalues.push_back(corrector(y_prime));
			}
		}
		catch (NumberException ne)
		{
			cout << ne.getMessage() << endl;
		}
		catch (...)
		{
			cout << "Something went horribly wrong if you see this message. (caught by ABM)" << endl;
		}
	}
}