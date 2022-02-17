#include <iostream>

using namespace std;

void increment(void* x, int p_size)
{
    if(p_size == sizeof(int))
    {
        int* pint; 
        pint=(int*)x;
        *pint+=10;
    }
    else if(p_size == sizeof(double))
    {
        double* pdouble; 
        pdouble=(double*)x;
        *pdouble+=100;
    }


}

void decrement(void* x, char type)
{
    switch(type)
    {
        case 'i':
            int *pint;
            pint = (int*)x;
            *pint-=10;
    
        
            break;
        case 'd':
            double *pdouble;
            pdouble=(double*)x;
            *pdouble-=100;

            break;

    }


}



int main()
{
    int x1= 10;
    double y = 10.5;
    
    increment(&x1, sizeof(x1));
    increment(&y, sizeof(y));

    cout << "Integer pointer: " << x1 << endl;
    cout << "Double pointer: " << y << endl;


    decrement(&x1, 'i');
    decrement(&y, 'd');

    cout << "Integer pointer: " << x1 << endl;
    cout << "Double pointer: " << y << endl;



    return 0;
}