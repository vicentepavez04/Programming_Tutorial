

/*
Classes are an expanded concept of data structures: like data structures, they can contain data members, but they can also contain functions as members.
In terms of variables, a class would be the type, and an object would be the variable.


Syntax:

        class class_name {
        access_specifier_1:
            member1;
        access_specifier_2:
            member2;
        ...
        } object_names;


*/

/*
Where class_name is a valid identifier for the class, object_names is an optional list of names for objects of this class.
The body of the declaration can contain members, which can either be data or function declarations, and optionally access specifiers.

 An access specifier is one of the following three keywords: private, public or protected:
        public - members are accessible from outside the class
        private - members cannot be accessed (or viewed) from outside the class
        protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes. You will learn more about Inheritance later.

*/



#include <iostream>
using namespace std;

class myclass
{
    public:
        int varA, varB;
        string varC;

};



int main()
{
    myclass classA;
    myclass classB;



    classA.varA=12;
    classA.varB = 13;
    classA.varC = "Some Text" ; 

    cout << classA.varA << endl;
    cout << classA.varB << endl;
    cout << classA.varC << endl;


    
    classB.varA=200;
    classB.varB = 324;
    classB.varC = "Some Text, version 2" ; 

    cout << classB.varA << endl;
    cout << classB.varB << endl;
    cout << classB.varC << endl;


    return 0;
}