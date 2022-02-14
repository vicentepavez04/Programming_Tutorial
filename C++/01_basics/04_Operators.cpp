#include <iostream>

using namespace std;
const int varA = 40;


int main()
{
    /*
        Arithmetic operators 
        +	addition
        -	subtraction
        *	multiplication
        /	division
        %	modulo
    */
    int varB = 10, varC;
    varC = varA % varB;
    cout << "varC: " << varC << "\t (40 % 10)" << endl;

    /*
        Increment and decrement
        
        y += x; ----->	y = y + x;
        x -= 5; ----->	x = x - 5;
        x /= y;	----->  x = x / y;
        x *= y + 1;	-----> x = x * (y+1)

    */
    int x=3, y=0, z=1;
    cout << "x:" <<x << endl;
    ++x;                            // equal to x+=1
    cout << "++x= " <<x << endl;
    --x;                            // equal to x-=1
    cout << "--x= " <<x << endl;



    /*
        Relational and comparison operators 
        ==	Equal to
        !=	Not equal to
        <	Less than
        >	Greater than
        <=	Less than or equal to
        >=	Greater than or equal to


        Logical operators ( 
        !   NOT
        &&  AND
        ||  OR

    
    */
    int equalA=4, equalB=4;
    bool result;
    result = (equalA == equalB);
    cout <<"Result is\b"<<result << "\b becouse 4 == 4 is True"<<endl;

    bool resultLogical = ( (5 == 5) && (3 > 6) );
    cout <<"The logical result is\b"<< resultLogical << "\b becouse (5 == 5) && (3 > 6) is False"<<endl;

    /*
        Conditional operator

        This operator  evaluates an expression, returning one value if that expression evaluates to true, 
        and a different one if the expression evaluates as false.

        Syntax:

        condition ? result1 : result2

                      True      False
    
    */
    int a,b,c;

    a=8;
    b=7;
    c = (a>b) ? a : b; // if a>b the result a else b
    cout <<"Conditional Operator (8>7) ? 8 : b \t"<< c << endl;
    

    /*
    Comma operator
        ( , )
    */
    int a1, b1;
    a1 = (b1=3, b1+2);
    cout <<"The comma operator (a = (b1=3, b1+2))\t "<< a1 << endl;

    return 0;
}