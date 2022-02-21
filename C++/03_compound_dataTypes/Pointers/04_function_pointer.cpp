#include <iostream>

using namespace std;


int add(int x, int y)
{
    return (x+y);
}
int sub(int x, int y)
{
    return(y-x);
}

int mul(int x, int y)
{
    return(x*y);
}

int operation(int x, int y, int (*functocall)(int, int))
{
    int f;
    f = (*functocall)(x, y);
    return (f);
}

double function_A(double x, double y)
{
    return (x+y)*3;
}


int main()
{
    int m, n;
    int (*minus)(int,int) = sub;   // Declares the function pointer
    double (*functocall)(double, double) = function_A; // Declares the function pointer

    m = operation(2,4,add);
    n = operation(m,10,minus);
    cout << m << endl;
    cout << n << endl;


    cout << functocall(11.346,0.5) << endl;

    return 0;
}