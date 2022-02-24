#include <iostream>
using namespace std;


class EquilateralTriangle
{
    float a;
    float area;
    float circumference;
public:
    void set(float length)
    {
        a = length;
        circumference = a*3;
        area = (1.73*a*a)/4;
    }
    friend void printer(EquilateralTriangle);

};

void printer(EquilateralTriangle e)
{
    cout << "Circumfenrence: " << e.circumference << endl;
    cout << "Area: " << e.area << endl;
}


/*

The "printer" function is a friend of class "EquilateralTriangle".
Therefore, function duplicate is able to access the members "a" , "area" and "circumference" (which are private) of different objects of type "EquilateralTriangle".

*/


int main()
{
    EquilateralTriangle x;
    x.set(4);
    printer(x);


    return 0;
}