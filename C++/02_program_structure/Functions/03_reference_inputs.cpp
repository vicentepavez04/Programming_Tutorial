#include <iostream>

using namespace std;

void multiplication(int& a, int& b)
{
    a *= b;
}

/*
    To gain access to its arguments, the function declares its parameters as references. In C++,
    references are indicated with an ampersand (&) following the parameter type.


    When a variable is passed by reference, what is passed is no longer a copy, but the variable itself, the variable identified by the function parameter, 
    becomes somehow associated with the argument passed to the function, and any modification on their corresponding local variables within the function are 
    reflected in the variables passed as arguments in the call.

*/


int main()
{
    int x, y ;

    cout << "Enter a number: " ;
    cin >> x ;
    cout << "Enter the multiplicator: ";
    cin >> y;

    cout << "(" << x << "*" << y << ")" << " = "; // the value of the inputs before de modification

    multiplication(x,y);
    
    cout << x << endl;

    return 0;
}