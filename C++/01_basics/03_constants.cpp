#include <iostream>

using namespace std;

// constant expressions

const double pi =3.1415926;
const char newLine = '\n';
const char tab = '\t';


int main()
{
    // Constant call
    cout << "Constant call" << tab << pi << newLine; 



    /*
        Characters Literlas

    \n	newline
    \r	carriage return
    \t	tab
    \v	vertical tab
    \b	backspace
    \f	form feed (page feed)
    \a	alert (beep)
    \'	single quote (')
    \"	double quote (")
    \?	question mark (?)
    \\	backslash (\)

    */

    cout << " \" Hello Word \"\n ";
    cout << "Hello\t\tWorld\n\n";


   return 0;
}