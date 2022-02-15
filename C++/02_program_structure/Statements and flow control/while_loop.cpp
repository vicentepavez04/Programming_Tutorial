#include <iostream>
#include <string>

using namespace std;

int main()
{   
    int x=0;

    while(x<10)
    {
        cout << "Enter a number: ";
        cin >> x;
        if(x >= 10)
        {
            cout << x << " >= 10, Goodbye" << endl;

        }else{
            cout << x << " < 10, the loop continues" << endl;

        }

    }

    string var;
    do
    {
        cout << "Type \"bye\" to exit \n" << "Enter Text: ";
        getline(cin, var);
        if (var=="bye")
        {
            cout << "Have a good day!" << endl;

        }
    }while(var!="bye");
    


}