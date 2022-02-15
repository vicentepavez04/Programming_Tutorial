#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    /*
        switch (expression)
        {
        case constant1:
            group-of-statements-1;
            break;
        case constant2:
            group-of-statements-2;
            break;
        .
        .
        .
        default:
            default-group-of-statements
        }
    
    */

   
    int x;
    cout << "Enter a Number: " ;
    cin >> x;
    switch(x)
    {
    case 1:
        cout << "The number is 1, thank you" << endl;
        break;
    case 2:
        cout << "The number is 2, bye" << endl;
        break;
    default:
        cout << "The Number isn't 1 or 2" << endl;

   }



}