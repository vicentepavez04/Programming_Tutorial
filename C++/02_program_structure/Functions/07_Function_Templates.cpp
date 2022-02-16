#include <iostream>
#include <string>

using namespace std;




/*
C++ has the ability to define functions with generic types,
known as function templates. Defining a function template follows the same syntax as a regular function, 
except that it is preceded by the template keyword and a series of template parameters enclosed in angle-brackets <>:

template <template-parameters> function-declaration

*/


template <class X, class U>
X product(X i, U n)
{
    X result;
    result = i * n;
    return result;
}


int main()
{
    int a = 200, b=10;
    double c=10.25, d=0.005;


    

    cout << "Result: " << product(a,b) << endl;
    /*
        int product(int i, int n)
    */
    cout << "Result: " << product(c,d) << endl;
    /*
        double product(double i, double n)
    */
    cout << "Result: " << product(a,d) << endl;
    /*
        int product(int i, double n)
    */
    cout << "Result: " << product(c,b) << endl;
    /*
        double product(double i, int n)
    */

    return 0;
}