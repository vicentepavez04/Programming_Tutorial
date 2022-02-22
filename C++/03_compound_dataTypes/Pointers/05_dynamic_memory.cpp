#include <iostream>
#include <stdlib.h> // system()
using namespace std;


/*
Dynamic memory is allocated using operator new. new is followed by a data type specifier and, if a sequence of more than one element is required,
 the number of these within brackets []. It returns a pointer to the beginning of the new block of memory allocated. Its syntax is:

pointerA = new type
pointerB = new type [number_of_elements]

*pointerA = value;
pointerB[i] = value;

delete pointerA;
delete[] pointerB;

*/


int main()
{
    
    int n;
    cout << "Enter the length: ";
    cin >> n;
    int *p = new int[n];

    for(int i=0; i<n ; i++)
    {
        cin >> p[i];

    }
    cout << "**************************" << endl;
        for(int i=0; i<n ; i++)
    {
        cout << p[i] << endl;

    }

    /*
    In most cases, memory allocated dynamically is only needed during specific periods of time within a program;
    once it is no longer needed, it can be freed so that the memory becomes available again for other requests of dynamic memory.

    delete pointerA;
    delete[] pointerB;

    */


    delete[] p;
   
    system("pause");
    return 0;
}