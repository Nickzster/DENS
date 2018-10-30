/* Differential Equations Numerical Solver - DENS - Nick Zimmermann
Header file for the Euler's Method, Euler's Improved Method, The RK4 method, and Abam Bashforth-Moultin method.

*/

#ifndef FX
#define FX
#include <iostream>
#include <vector>

/* Constant definitions = = = = = = = = = = = = = = = = = = = = = = = */
const float e = 2.71828182845904523536028747135266249775724709369995;
/* Function Class = = = = = = = = = = = = = = = = = = = = = = = = = = */

using std::string;
using std::vector;
namespace DENS
{
	class Function
	{
	protected:
		//Values. Used for ALL algorithims.
		//Inital Values//
		float xIn;
		float yIn;

		float h; //Step Size
		float xTerminal; //Terminal value
		int p; //P is used to select from a set of equations that you can define.

		string methodName; //gives the class the name of the file to be outputted.
		string function; //Function to be evaluated.
		
		//vectors holding the values
		vector <float> xvalues;
		vector <float> yvalues;

	public:
			//Constructors
		Function();
		//Destructors
		~Function();
			//Overloaded function takes in X-value, so one may set their function in terms of X.
/*		Function(float xIn);

		Function(float xIn, float yIn); */
		//Functions
		void setFunction(string); //Sets the function to be evaluated.
		float Eval(float xIn, float yIn); //Evauluates a specific problem that the user wants to solve.
		float Eval(float xIn, float yIn, int p); //Uses a switch-case to evaluate any of the problems in a list that the user defines.
		///Problems: Stores the functions to be evaluated.
		float Problems(float xIn, float yIn); //Stores 1 problem
		float Problems(float xIn, float yIn, int p); //Stores a switch-case list of problems.
	

		//getX and getY: gets the output for X and y.
		float getY();
		//Print values
		void printValues();
			//the following functions are used to initalize the differential equation formulas.
		void addH();
		void initalize();
		virtual void method() = 0;
	};
}
/* Exception Handeling Classes= = = = = = = = = = = = = = = = = = = = = = = */

#include <string>
using std::string;
class NumberException //In case any invalid numeric operations are used. EX: Divide by zero, negative square roots.
{
private:
	int errorCode;
	string errorMessage;
public:
	//Constructors
	NumberException() { this->errorCode = -1, this->errorMessage = "Unknown"; }
	NumberException(string errorMessage) { this->errorCode = -1, this->errorMessage = errorMessage; }
	NumberException(string errorMessage, int errorCode) { this->errorCode = errorCode, this->errorMessage = errorMessage; }
	//Functions
	string getMessage() { return this->errorMessage; }
	int getCode() { return this->errorCode; }
};



#endif