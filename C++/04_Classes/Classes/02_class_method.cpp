#include <iostream>
using namespace std;




// inside example
class A
{
    public:
        void methodA(string x)
        {
            cout << "A: Hello " << x <<", nice to meet you :)" << endl;
        }

};


// outside
class B
{
    public:
        void methodB(string x);

};

void B::methodB(string x)
{
    cout << "B: Hello " << x <<", nice to meet you :)" << endl;
}



int main()
{
    A person1;
    B person2;

    person1.methodA("Vincent") ;
    person2.methodB("Xavier") ;


    return 0;
}