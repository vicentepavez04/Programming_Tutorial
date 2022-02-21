#include <iostream>
using namespace std;

struct person
{
    string name;
    int age;
};

void printer(person x)
{
    cout << "Name: " << x.name << endl;
    cout << "Age: " << x.age << endl;
}


int main()
{
    person A;
    cout << "Enter your name: ";
    getline(cin, A.name);
    cin.ignore();
    cout << "How old are you? ";
    cin >> A.age;

    printer(A);
    return 0;
}