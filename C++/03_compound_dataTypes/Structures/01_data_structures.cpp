#include <iostream>
using namespace std;



/*
A data structure is a group of data elements grouped together under one name. 
These data elements, known as members, can have different types and different lengths.
Data structures can be declared in C++ using the following syntax:

struct type_name {
member_type1 member_name1;
member_type2 member_name2;
member_type3 member_name3;

*/

struct dogs
{
    string name;
    int age;
    string breed;
    int weight;
} ;


int main()
{
    dogs number_1;
    cout << " Enter the dog's name, please: ";
    getline(cin, number_1.name);
    cout << " Enter dog's age: ";
    cin >> number_1.age;
    cout << " Enter dog's breed: ";
    cin.ignore();
    getline(cin, number_1.breed);
    cout << " Enter dog's weigth: ";
    cin >> number_1.weight;

    cout << number_1.name << " is " << number_1.age << " years old, He's a beautifull " << number_1.breed << " and weight " << number_1.weight << " Kg." ;
    

    return 0;
}