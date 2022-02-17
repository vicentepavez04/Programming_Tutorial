#include <iostream>
using namespace std;

/*

delaring a pointer:
    int * a;

Note that the asterisk (*) used when declaring a pointer only means that it is a pointer (it is part of its type compound specifier), 
and should not be confused with the dereference operator seen a bit earlier, but which is also written with an asterisk (*). 
They are simply two different things represented with the same sign.

*/


int main()
{

    int value_A, value_B;
    int *pointer_A, *pointer_B;
    

    value_A = 30;
    value_B = 45;
    cout << value_A << endl;

    pointer_A = &value_A; // Pointer A points to the address of value_A
    *pointer_A = value_B;   
    cout << value_A << endl;

    pointer_B = pointer_A; // Pointer A and B, point to the same address (where is the var value_A)
    *pointer_B = 250;
    cout << value_A << endl;


    /*
    Pointers can be initialized to point to specific locations at the very moment they are defined
    */

    /* 
    
    the simbol "*" in the intialization is only used to define the pointer.

        int *var = &var_a;    -----> equal to -----> var = &var_a
        
        is not equal to;
            int * var
            *var = &var_a

    */


    double var_c=2.5, *pointer_C = &var_c;

    *pointer_C = 4.54;
    cout << var_c << endl;

    ++*pointer_C;
    cout << var_c << endl;

    pointer_C++;
    cout << &pointer_C << endl;
    pointer_C++;
    cout << &pointer_C << endl;



    return 0;
}