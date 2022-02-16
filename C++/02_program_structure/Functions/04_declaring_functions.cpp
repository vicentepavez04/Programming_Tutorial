#include <iostream>
#include <string>
using namespace std;


void function_A(int& x);
void function_B(int& x);



int main()
{
    int i;
    char n;
    cout << "Enter a number: ";
    cin >> i;
    cout << "Function A = +5 or Function B = +200 \n select a funcion (A or B): ";

    while(n != 'q')
    {
        cin >> n;
        if(n == 'A')
        {
            function_A(i);
            cout << "Result: " << i << endl;
            cout << "Enter A or B, q to exit:  ";
        }
        else if(n == 'B')
        {
            function_B(i);
            cout << "Result: " << i << endl;
            cout << "Enter A or B, q to exit:  ";
        }
        else
        {
            cout << "Enter A or B, q to exit:  ";
        }
    }

    return 0;
}


void function_A(int& x)
{
    x += 5;
}

void function_B(int& x)
{
    x += 200;
}