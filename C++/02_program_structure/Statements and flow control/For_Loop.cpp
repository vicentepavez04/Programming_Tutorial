#include <iostream>
#include <string.h>
using namespace std;

int main()
{

    // for (initialization; condition; increase) statement;
    
    for(int i = 0; i <= 10; i++)
    {

        cout << "i: " << i << endl;

    }

    
    for( int x=0, n=20; n!=x; x++, n--)
    {
        cout << "x: " << x << " n: "<< n << endl;
    }


    /*    
        Range-based for loop
        for ( declaration : range ) statement;

        Ranges are sequences of elements, including arrays, containers, and any other type supporting the functions begin and 
    */
    string var;
    cout << "Enter a text: " ;
    getline(cin, var);

    for(auto c: var)
    {
      cout << c << endl;  

    }


    return 0;
}