
/*
Exception handling in C++ consist of three keywords: try, throw and catch:

    The try statement allows you to define a block of code to be tested for errors while it is being executed.

    The throw keyword throws an exception when a problem is detected, which lets us create a custom error.

    The catch statement allows you to define a block of code to be executed, if an error occurs in the try block.

                            (The try and catch keywords come in pairs)




*/


#include <iostream>
using namespace std;

int main()
{

    try
    {
        int dadsAge = 10;
        int sonsAge = 67;
        if(sonsAge > dadsAge)
        {
            throw 99;
        }
    }
    catch(int x)
    {
        // x is 99
        cout << "Son can not be older than Dad, ERROR NUMBER: " << x << endl;
    }


    try
    {
        int x,y;

        cout << "\n\nEnter first number x: " ;
        cin >> x;
        cout << "Enter second number y: " ;
        cin >> y;
        if(y==0)
        {
            throw 0;
        }
        cout << "Result of x/y: " << x/y << endl;

    }
    // if the throw is a number ---> catch(int) , if isn't a integer ---> catch(...)   (catch everything) 
    catch(int e)
    {
        cout << "You can't divide by zero, ERROR NUMBER: " << e << endl;
    }
    // defaul handler comes always last (catch(...))
    catch(...)
    {
        cout << "Unknow ERROR " << endl;
    }

    return 0;
}