

/*
                        Overloadable operators
        +    -    *    /    =    <    >    +=   -=   *=   /=   <<   >>
        <<=  >>=  ==   !=   <=   >=   ++   --   %    &    ^    !    |
        ~    &=   ^=   |=   &&   ||   %=   []   ()   ,    ->*  ->   new 
        delete    new[]     delete[]

*/

/*
        Syntax:

class A
{
    public:
        int x,y;
        A(){};
        A(int a, int b): x(a), y(b) {}
        A operator + (const A&)
};

A A::operator+ (const &A param)
{
    A res;
    res.x = x + param.x;
    res.y = y + param.y
}


*/


#include <iostream>
using namespace std;

class Myclass
{
    
    public:
        int x,y;
        Myclass(){};
        Myclass(int a, int b): x(a),y(b) {}
        Myclass operator+ (const Myclass&);
        Myclass operator- (const Myclass&);
        Myclass operator++ ();
};

Myclass Myclass:: operator+ (const Myclass& var)
{
    Myclass res;
    res.x = x + var.x;
    res.y = y + var.y;
    return res;
}

Myclass Myclass:: operator- (const Myclass& var)
{
    Myclass res;
    res.x = x - var.x;
    res.y = x - var.y;
    return res;
}

Myclass Myclass:: operator++ ()
{    
    x += 1;
    y += 1;
}



int main()
{
    int m,n;
    Myclass classA(5,9);
    Myclass classB(3,12);
    Myclass resultA, resultB;
    resultA = classA + classB;
    resultB = classA - classB;

    

    cout << "The result A is ("<<resultA.x << "," << resultA.y <<")\n";
    cout << "The result B is ("<<resultB.x << "," << resultB.y <<")\n";

    cout << "var: " << classB.x << "," << classB.y << endl;
    ++classB;
    cout << "var++: " << classB.x << "," << classB.y << endl;


    return 0;
}