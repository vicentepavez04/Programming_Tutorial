#include <iostream>
#include <string>

using namespace std;

int function_A(int x)
{
    return x*2;
}
double function_A(double x)
{
    return x*10;
}

int main()
{
    int i=10;
    double n= 10.53;

    cout << "Interger Input: " << i << endl;
    cout << "Double Input: " << n << endl;
    i = function_A(i);
    n = function_A(n);

    cout << "Interger Result: " << i << "\tx*2" << endl;
    cout << "Double Result: " << n << "\tx*10" << endl;

    return 0;
}
