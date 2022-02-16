#include <iostream>
#include <string>

using namespace std;


/*

    void means that the function does not have a return value.

    Syntax:
        type name ( argument1, argument2 ...) { statements }

*/
void function_A()
{   
    string text;
    cout << "Enter your name; " ;
    cin.ignore();
    getline(cin, text);
    cout << "Thank you "<< text <<" for calling the funcion A" << endl;
}

void function_B()
{
    string text;
    cout << "Enter your name; " ;
    cin.ignore();
    getline(cin, text);
    cout << "Thank you "<< text <<"for calling the funcion B" << endl;

}


int main()
{   
    string var;
    while (true)
    {
        cout << "Please, enter the letter A or B: " ;
        cin >> var;

        if(var == "A")
        {   
            function_A();
            cout << "Excelent!"<< endl;
            break;
        }
        else if(var == "B")
        { 
            function_B();
            cout << "Excellent!"<< endl;
            break;
        }
        else
        {
            cout << "A or B, please!" << endl;
        }


    }
    
    return 0;
}