#include <iostream>
using namespace std;



class circle
{
    double r;
    public:
        
        circle(int radius): r(radius){}
        double area(){return r*r*3.14;}
        double perimeter();

};

double circle::perimeter()
{
    return (2*3.14*r);
}



int  main()
{
    double x;
    cout << "Enter the radius: ";
    cin >> x;

    circle circle_A(x);

    cout << "Area: " << circle_A.area() << endl;
    cout << "Perimeter: " << circle_A.perimeter() << endl;


    return 0;
}