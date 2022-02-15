#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    // The break statement
    cout << " The break statement " << endl;
    for(int i = 0; i<10 ;i++)
    {
        cout << "i: "<< i << endl;
        if(i == 6)
        {
            cout << "The value is 6, goodbye" << endl;
            break;
        }
    
    }

    // The continue statement
    cout << " The continue statement " << endl;
    for(int n = 10; n>0; n--)
    {
        
        if(n == 4) continue;
        cout << "n: " << n << endl;


    }


    // The goto statement

    int h = 0;
    cout << " The goto statement " << endl;
pointA:

    cout << "h: "<< h << endl;
    h++;
    if (h<5) goto pointA;


}