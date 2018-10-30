#include <iostream>
#include <string>

#include "fx.h"
#include "em.h"
#include "rk4.h"
#include "abm.h"

using namespace DENS;

using namespace std;

int main(int argc, char* argv[])
{   
    //DENS <MethodName> <xInital> <yInital> <stepSize> <xTerminal> <functionToEvaluate>
    if(argc != 6)
    {
        if(string(argv[1]) == "--help")
        {
            cout << "Options:" << endl;
            cout << "--about" << endl;
            cout << "./DENS <MethodName> <xInital> <yInital> <stepSize> <xTerminal>" << endl;
            cout << "DENS will then prompt for f(x,y) to evaluate." << endl;
            cout << "Must be first order in order to successfully evaluate." << endl;
        }
        else if(string(argv[1]) == "--about")
        {
            cout << "Differential Equations Numerical Solver: By Nick Zimmermann" << endl;
        }
        else
        {
            cout << "Invalid argument count" << endl;
        }
        return 0;
    }
    string function;
    cout << "Enter a mathematical function to evaluate: ";
    cin >> function;

    string argument(argv[1]);
    float xInital = stof(string(argv[2]), nullptr);
    float yInital = stof(string(argv[3]), nullptr);
    float stepSize = stof(string(argv[4]), nullptr);
    float xTerminal = stof(string(argv[5]), nullptr);

    if(argument == "em")
    {
        em e(xInital, yInital, stepSize, xTerminal, false);
        e.setFunction(function);
        e.method();
        e.printValues();
    }
    else if(argument == "eim")
    {
        em emi(xInital, yInital, stepSize, xTerminal, true);
        emi.setFunction(function);
        emi.method();
        emi.printValues();
    }
    else if(argument == "rk4")
    {
        rk4 r(xInital, yInital, stepSize, xTerminal);
        r.setFunction(function);
        r.method();
        r.printValues();
    }
    else if(argument == "abm")
    {
        abm a(xInital, yInital, stepSize, xTerminal);
        a.setFunction(function);
        a.method();
        a.printValues();
    }
    else
    {
        cout << "Invalid argument was passed." << endl;
    }
    return 0;
}