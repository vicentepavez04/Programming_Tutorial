#include <iostream>
using namespace std;


int main()
{
    /* Character types */
    char firstCharacter;
    firstCharacter = 'b';
    cout << "Character: " << firstCharacter << endl;

    /* Integer types */
    int firstNumber;
    long int secondNumber;
    firstNumber = 23;
    secondNumber = 445;
    secondNumber = secondNumber + firstNumber;
    cout << "Integer: " << secondNumber << endl;
    
    /* Floating-point types */
    float number;
    double doublePrecisionNumber;
    number = 4.16544;
    doublePrecisionNumber = 0.225;
    doublePrecisionNumber = doublePrecisionNumber/number;
    cout << "Floating-point: "<< doublePrecisionNumber << endl;

    /* Boolean type */
    bool var;
    var = false;
    cout << "False: " << var << endl; 
    var = true;
    cout << "True: " << var << endl; 

    /* Initialization of variables */

    int a=5;               // initial value: 5
    int b(3);              // initial value: 3
    int c{2};              // initial value: 2
    int result;            // initial value undetermined
    float d,h,g,k;      
    result = a + b + c;
    cout << "Initialization of variables: " << result << endl;

    /* Introduction to strings */
    string firstString;
    string secondString = "Second String";
    string thirdString ("Third String");
    firstString = "First String";
    cout << firstString << endl;
    cout << secondString << endl;
    cout << thirdString << endl;


    string bye= "GoodBye :)";
    cout << bye << endl;

}