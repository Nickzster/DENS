#include <iostream>
#include <vector>
#include <ostream>
#include <ostream>
#include <istream>
#include <fstream>
#include "fx.h"
#include "rk4.h"
using namespace std;

namespace DENS
{
	//Constructors
	rk4::rk4()
	{
		rk4(1, 5, 0.5);
	}
	rk4::rk4(float xIn, float yIn, float h)
	{
		rk4(xIn, yIn, h, 5.0);
	}
	rk4::rk4(float xIn, float yIn, float h, int xTerminal)
	{
		rk4(xIn, yIn, h, xTerminal, 0);
	}
	rk4::rk4(float xIn, float yIn, float h, int xTerminal, int p)
	{
		this->xIn = xIn;
		this->yIn = yIn;
		this->h = h;
		this->xTerminal = xTerminal;
		this->p = p;
	}
	//Functions
	void rk4::equals(float xIn, float yIn)
	{
		this->xIn = xIn;
		this->yIn = yIn;
	}
	float rk4::rk4Function()
	{
		float k1 = Eval(this->xIn, this->yIn);
		float k2 = Eval(this->xIn + (0.5 * this->h), this->yIn + (0.5 * h * k1));
		float k3 = Eval(this->xIn + (0.5 * this->h), this->yIn + (0.5 * h * k2));
		float k4 = Eval(this->xIn + this->h, this->yIn + (this->h * k3));
		return this->yIn + (h / 6) * (k1 + (2 * k2) + (2 * k3) + k4);
	}
	void rk4::method()
	{
		try
		{
			int count = (this->xTerminal - this->xIn) / this->h;
			cout << count << " iterations" << endl;
			for (int i = 0; i < count; i++)
			{
				this->xvalues.push_back(this->xIn);
				this->yvalues.push_back(this->yIn);
				this->yIn = rk4Function();
				addH();
			}
		}
		catch (NumberException ne)
		{
			cout << ne.getMessage() << endl;
		}
		catch (...)
		{
			cout << "Something went horribly wrong if you see this message. (caught by RK4)" << endl;
		}
	}
	//This alternate function is used for multistep methods to initalize. This is used by the ABM class.
	void rk4::method(int count)
	{
		try
		{
			for (int i = 0; i < count; i++)
			{
				this->xvalues.push_back(this->xIn);
				this->yvalues.push_back(this->yIn);
				this->yIn = rk4Function();
				addH();
			}
		}
		catch (NumberException ne)
		{
			cout << ne.getMessage() << endl;
		}
	}

	//Used for ABM. Returns the value at the given index.
	float rk4::getX(int i)
	{
		return this->xvalues.at(i);
	}
	float rk4::getY(int i)
	{
		return this->yvalues.at(i);
	}
}