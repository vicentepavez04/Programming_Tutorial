#include <iostream>
using namespace std;


/*
Multidimensional arrays can be described as "arrays of arrays"
*/
int main()
{   
    
    int array_A[3][3];
    char array_B[3][3][3];

    for(int i=0; i<3; i++)
    {
        for(int n=0; n<3; n++)
        {    
            array_A[i][n] = i+n;
            cout << array_A[i][n] ;

        }
        cout << "\n";
    }

    for(int i=0; i<3; i++)
    {
        for(int n=0; n<3; n++)
        {    
            
            for(int k=0; k<3; k++)
            {           
                //array_A[i][n] = i+n;
                cout << array_B[i][n][k] ;
            }
        }
        cout << "\n";

    }
    return 0;
}