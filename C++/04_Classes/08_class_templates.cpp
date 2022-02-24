#include <iostream>
using namespace std;


/*

***SYNTAX***

** Class:

template <class T>
class Myclass{};


**Function of class "Myclass":

template <class T>
T Myclass<T>::functionB(){}

template <class T>
T Myclass<T>::functionA (){}


*/



template <class T>
class rectangle
{
    T length, height;
    public:
    rectangle(T x, T y): length(x), height(y) {}
    T perimeter();
    T area();
};


template <class T>
T rectangle<T>::perimeter()
{
    return (2*length+2*height);
}
template <class T>
T rectangle<T>::area()
{
    return (length*height);
}

int main()  
{
    rectangle <int> varA(4,10);
    rectangle <double> varB(2.345,4.523);      

    cout << "Area (int): " << varA.area() << endl;
    cout << "Area (double): " << varB.area() << endl;

    cout << "Perimeter (int): " << varA.perimeter() << endl;
    cout << "Perimeter (double): " << varB.perimeter() << endl;

    return 0;
}