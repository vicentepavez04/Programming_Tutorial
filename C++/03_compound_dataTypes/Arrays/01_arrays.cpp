#include <iostream>

using namespace std;


int main()
{
    int array_A[] = {10, 20, 110, 21 ,13 , 15, 664};
    char array_B[]="hello wordl !";
  
    cout << array_B << endl;
    cout << "The memory direction where start the number array: "<< array_A << endl;
    for(int i=0; i<7 ; i++)
    {
        cout << "array_A[" << i << "]: "<< array_A[i] << endl;
    }

    return 0;
}