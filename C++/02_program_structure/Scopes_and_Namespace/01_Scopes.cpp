#include <iostream>

using namespace std;

// Global scope
int i = 1;

int main()
{
    int i = 7;
    {
        // local scope
        int i = 3;

        cout <<"Inner block: " << i << endl;

        cout <<"Global variable: " << ::i << endl; // print the global variable whit "::"

     
    }
    cout <<"Outer block: "<< i << endl;
}


// when initialize a variable in a scope "{ }" just exist in that scope before the last bracket "}"

