#include <iostream>

using namespace std;

double product(double x, double y)
{
    return x*y;
}

int sum_25(int x)
{
    return x+25;
}

int main()
{

    // Calling the double function "product"
    double i, n, z;
    cout << "Enter a number: " ;
    cin >> i;
    cout << "Enter a number: " ;
    cin >> n;

    double prod = product(i,n);
    z = product(i,n) + 10;

    cout << "the product is: " << prod << endl;
    cout << "the product + 10 is: " << z << endl;


    // Calling the int function "sum_25"
    int h;
    cout << "Enter a integer: ";
    cin >> h;
    cout << "The value plus 25 is: " << sum_25(h) << endl;

    return 0;
}