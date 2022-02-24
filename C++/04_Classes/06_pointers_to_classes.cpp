#include <iostream>
using namespace std;



/*

expression	    can be read as

*x	            pointed to by x
&x	            address of x
x.y	            member y of object x
x->y	        member y of object pointed to by x
(*x).y	        member y of object pointed to by x (equivalent to the previous one)

*/

class rectangle
{
    int width, height;
    public:
        rectangle(int x, int y): width(x), height(y) {}
        int perimeter();
        int area();

};


int rectangle::perimeter()
{
    return (2*width+2*height);
}

int rectangle::area()
{
    return (width*height);
}

int main()
{
    rectangle var(2,3);
    rectangle *pointA, *pointB, *pointC;
    
    
    pointA = &var;
    pointB = new rectangle(4,7);
    pointC = new rectangle[2] {{10,3},{3,7}};


    cout << "Obj's area: " << var.area() << endl;
    cout << "PointA's area: " << pointA->area() << endl;
    cout << "PointB's area: " << pointB->area() << endl;
    cout << "PointC[0]' area: " << pointC[0].area() << endl;
    cout << "PointC[1]' area: " << pointC[1].area() << endl;

    cout << "*********************\n*********************" << endl;


    cout << "Obj's perimeter: " << var.perimeter() << endl;
    cout << "PointA's perimeter: " << pointA->perimeter() << endl;
    cout << "PointB's perimeter: " << pointB->perimeter() << endl;
    cout << "PointC[0]' perimeter: " << pointC[0].perimeter() << endl;
    cout << "PointC[1]' perimeter: " << pointC[1].perimeter() << endl;


    delete pointB;
    delete[] pointC;

    return 0;
}