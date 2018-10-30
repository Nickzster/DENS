#include <iostream>
#include <vector>
#include <ostream>
#include <istream>
#include <fstream>
#include <string>
#include "exprtk.hpp"
#include "fx.h"
using namespace std;
using namespace exprtk;

namespace DENS
{
	//Constructors
	Function::Function()
	{
		//cout << "creating fx object" << endl;
	}
	Function::~Function()
	{
		//cout << "destroying fx object" << endl;
	}
	//Overloaded function takes in X-value, so one may set their function in terms of X.
/*	Function::Function(float xIn)
	{
		Function(xIn, 0);
	}
	Function::Function(float xIn, float yIn)
	{
		this->xIn = xIn;
		this->yIn = yIn;
	} */
	//Functions
	/* Scroll down to the bottom of this file to see
	a list of functions to try out. */
	///Problems: Evalutes the functions with the class values.
	float Function::Problems(float xIn, float yIn)
	{
		typedef float T;
		typedef symbol_table<T> symbol_table_t; //custom symbols.
		typedef expression<T> expression_t; //compiled expression.
		typedef parser<T> parser_t; //parser for the expression.

		T x = T(xIn);
		T y = T(yIn);
		symbol_table_t symbol_table;
		symbol_table.add_variable("x",x);
		symbol_table.add_variable("y",y);
		
		expression_t expression;
		expression.register_symbol_table(symbol_table);

		parser_t parser;
		parser.compile(this->function, expression);

		return expression.value();
		
		// return ((2 * xIn) - (3 * yIn)) + 1; // <-Insert function here
	}
	void Function::setFunction(string fxn) //Sets the function to be evaluated.
	{
		this->function = fxn;
	}
	float Function::Eval(float xIn, float yIn)
	{
		return Problems(xIn, yIn);
	}
	///getX and getY: gets the output for X and y.
	float Function::getY()
	{
		return this->yIn;
	}
	//the following functions are used to initalize the differential equation formulas.
	//Adds h for next values.
	void Function::addH()
	{
		this->xIn = this->xIn + this->h;
	}
	//Sets up the method.
	void Function::initalize()
	{
		/*		cout << "Enter the problem (0-10)" << endl;
		cin >> this->p; */
		cout << "Enter the following: X(0), Y(0), step-size(h)" << endl;
		cin >> this->xIn;
		cin >> this->yIn;
		cin >> this->h;
		cout << "Enter terminal value" << endl;
		cin >> this->xTerminal;

	/*	cout << this->xIn << endl;
		cout << this->yIn << endl;
		cout << this->xTerminal << endl;
		cout << this->h << endl;
		cout << this->p << endl;
		cout << "==================" << endl; */ //NEED TO WORK ON DEBUGGING THIS. *********************
	}
	void Function::printValues()
	{
		char method[100];
		cout << "enter a name for the output file (including extension - recommend .xls)" << endl;
		cin >> method; 
		ofstream outValues(method);
		outValues << "X-Values" << "\t" << "Y-values" << "\t" << endl;
		for (int i = 0; i < this->xvalues.size(); i++)
		{
			outValues << this->xvalues.at(i) << "\t" << this->yvalues.at(i) << "\n";
		}
		cout << "------------------------------------------------------" << endl;
		cout << "File saved as " << method << endl;
		cout << "------------------------------------------------------" << endl;
	}
}




///Keeping everything below in case I ever need it again





///Old Function implementation
/*		switch (this->p)
{
case 0:

Custom problem must be in f(x,y) form. Use the values being passed in
As the numbers being evaluated. Delete the throw statement below
to stop it from throwing an exception.

throw NumberException("Custom Problem is not set up!");
break;
case 1:
return ((2 * xIn) - (3 * yIn)) + 1;
break;
case 2:
return (4 * xIn) - (3 * yIn);
break;
case 3:
return 1 + pow(yIn, 2);
break;
case 4:
return pow(xIn, 2) + pow(yIn, 2);
break;
case 5:
return pow(e, -(yIn));
break;
case 6:
return xIn + pow(yIn, 2);
break;
case 7:
return pow(xIn - yIn, 2);
break;
case 8:
if (this->yIn <= 0)
{
throw NumberException("Cannot be a negative number.");

}
return this->xIn * this->yIn + sqrt(this->yIn);
break;
case 9:
if (this->xIn == 0)
{
throw NumberException("Cannot be equal to Zero.");
}
else
{
return this->xIn * pow(this->yIn, 2) - this->yIn / this->xIn;
}
break;
case 10:
return this->yIn - pow(this->yIn, 2);
break;
default:
cout << "Not a valid function. If this gets called, something screwed up somewhere." << endl;
return 1;
break;
}
//sets y-out values based on function f(x)
*/
///End old function implementation

/*
Here is a list of functions to try:
1 - ((2 * xIn) - (3 * yIn)) + 1
2 - (4 * xIn) - (3 * yIn)
3 - 1 + pow(yIn, 2)
4 - pow(xIn, 2) + pow(yIn, 2)
5 - pow(e, -(yIn))
6 - xIn + pow(yIn, 2)
7 - pow(xIn - yIn, 2)
8 - this->xIn * this->yIn + sqrt(this->yIn) ---WARNING: Throw exception if it is less than zero.
9 - this->xIn * pow(this->yIn, 2) - this->yIn / this->xIn ---WARNING: Throw exception if it is equal to zero.
10 - this->yIn - pow(this->yIn, 2)
*/