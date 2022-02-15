#include <iostream>

using namespace std;

int main()
{
    int x;
    cout << "Enter a number:";
    cin >> x ;
    if (x == 25)
    {
        cout << "Equal to 25" << endl;

    }else if (x < 25){

        cout << "Less than 25";

    }else if(x > 25){

        cout << "More than 25" << endl;

    }else{

        cout << "else" << endl;
    }



    return 0;
}