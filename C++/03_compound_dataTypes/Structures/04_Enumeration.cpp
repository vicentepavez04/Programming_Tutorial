
#include <iostream>
using namespace std;

/*

An enumeration is a user-defined data type that consists of integral constants. 
An enum variable takes only one value out of many possible values.

its a way to name values, its just a integer, by default increment by 1.

*/

enum color 
{
    red, blue, yellow, white
};

int main()
{

    int n;
    color C;

    C = blue;
pointblue:
    cout << "type: 1, to set blue: ";
    cin >> n;

    if(C==n && C==blue)
    {
        cout << "C is blue" << endl;
    
    }
    else
    {
        cout << "It's not blue" << endl;
    }

    
    if(n!=1) goto pointblue;


    cout << "*********************"<<endl;
    cout << "Red: " << color::red << endl;
    cout << "Blue: "  << color::blue << endl;
    cout << "Yellow: "  << color::yellow << endl;
    cout << "White: "  << color::white << endl;

    cout << "*********************"<<endl;
    
    int sum_colors = red | yellow | white;
    cout << "Sum: "<< sum_colors;


    return 0;
}