#include <iostream>
using namespace std;


/*

A constructor in C++ is a special method that is automatically called when an object of a class is created.

*/

class person
{
    public:
        int age,weigth;
        string name;
        person(int x, int y , string z);

};

person::person(int x, int y , string z)
{
    age = x;
    weigth = y;
    name = z;

    cout << "Thank you :)" << endl;
}

int main()
{
    int a,b;
    string c;

    cout << "Enter your name: " ;
    getline(cin, c);
    cout << "Enter your age: ";
    cin >> a;
    cout << "enter your weigth: ";
    cin >> b;

    person personA(a,b,c);

    cout << "Name: " << personA.name << "\nAge: " << personA.age << "\nWeigth: " << personA.weigth << endl;


    return 0;
}