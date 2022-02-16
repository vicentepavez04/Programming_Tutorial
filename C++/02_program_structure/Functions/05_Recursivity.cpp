/* Recursivity is the property that functions have to be called by themselves. 
It is useful for some tasks, such as sorting elements, or calculating the factorial of numbers. */

#include <iostream>
#include <string>
using namespace std;



double function_A(double x, double i);


int main()
{
    double i, x=0;
    cout << "Enter a Number: ";
    cin >> i;
    x = function_A(i, 0);

    cout << "The result is " << x << endl; 

    return 0;
}   

double function_A(double x, double i)
{   
    x = x*2;
    if(i==0)
    {
        // Recursivity is the property that functions have to be called by themselves.
        x = function_A(x, i=1);
    }

    // x = 4*x
    return x;
}
