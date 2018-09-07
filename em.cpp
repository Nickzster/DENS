//Function Definitions for Euler's and Euler's improved method.
//Written by Nick Zimmermann

#include <iostream>
#include <vector>
#include <ostream>
#include <ostream>
#include <istream>
#include <fstream>
#include "fx.h"
#include "em.h"
using namespace std;
namespace DENS
{
	//Euler's Method
	//Constructors

	em::em(float xIn, float yIn, float h, int xTerminal, int p)
	{
		this->xIn = xIn;
		this->yIn = yIn;
		this->xTerminal = xTerminal;
		this->h = h;
		this->p = p;
		this->methodName = "EM.xls";
	/*	cout << this->xIn << endl;
		cout << this->yIn << endl;
		cout << this->xTerminal << endl;
		cout << this->h << endl;
		cout << this->p << endl;
		cout << "==================" << endl; */ //NEED TO WORK ON DEBUGGING THIS. *********************
	}
	em::em(float xIn, float yIn, float h, int xTerminal)
	{
		em(xIn, yIn, h, xTerminal, 0);
	}
	em::em(float xIn, float yIn, float h)
	{
		em(xIn, yIn, h, 5.0);
	}
	em::em()
	{
		em(1,1,0.5);
	}
	//Functions
	//Destructors
	em::~em()
	{
		//cout << "destroying em object" << endl;
	}
	float em::emFunction()
	{
		if (this->improved == true)
		{
			//Y-star is used for Euler's improved method. 
			float yStar = this->yIn + (this->h * Eval(this->xIn, this->yIn));
			return this->yIn + (this->h *(Eval(this->xIn, this->yIn) + Eval(this->xIn + this->h, yStar))) / 2;
		}
		else
		{
			return this->yIn + (this->h * Eval(this->xIn, this->yIn));
		}
	}
	//Equals
	void em::equals(float xIn, float yIn)
	{
		this->xIn = xIn;
		this->yIn = yIn;
	}
	void em::method()
	{
		try
		{
			int count;
			if(this->h == 0)
			{
				NumberException ne("Divide by zero error detected in em::method(), where h = 0");
				throw ne;
			}
			else
			{
				count = (this->xTerminal - this->xIn) / this->h;
			}
			cout << count << " iterations" << endl;
			for (int i = 0; i < count; i++)
			{
				this->xvalues.push_back(this->xIn);
				this->yvalues.push_back(this->yIn);
				this->yIn = emFunction();
				addH();
			}
		}
		catch (NumberException ne)
		{
			cout << ne.getMessage() << endl;
		}
		catch (...)
		{
			cout << "Something went horribly wrong if you see this message. (caught by em)" << endl;
		}
	}
	void em::improve()
	{
		this->methodName = "EIM.xls";
		this->improved = true;
	}
}