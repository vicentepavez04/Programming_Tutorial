#include <iostream>
#include <array>

using namespace std;

int main()
{
    char question_A[] = "Where do you live?";
    char answer_A[80]; //Max lenght 80

    cout << question_A << endl;
    cin >> answer_A ;
    cout << answer_A << ", It's a beautifull place" << endl;



    /*
    In the standard library, both representations for strings (C-strings and library strings) coexist,
    and most functions requiring strings are overloaded to support both.
    
    like: 

    char myntcs[] = "some text";
    string mystring = myntcs;  // convert c-string to string
    cout << mystring;          // printed as a library string  
    cout << mystring.c_str();  // printed as a c-string 

    */

    string question_B = "What is your name?";
    string answer_B ;

    cout << question_B << endl;
    cin >> answer_B;
    cout << answer_B << ", what a beautifull name" << endl;

    cout << "Thank you so much, " << answer_B << " from " << answer_A << endl;



    return 0;
}