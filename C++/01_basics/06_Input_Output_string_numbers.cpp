#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main ()
{
  string var;
  cout << "Enter a string, please" << endl;
  getline (cin, var);
  // cin >> var; Just one string without spaces
  cout << "The string is: " << var << endl;


  float numberA;
  int numberB;

  cout << "Enter a float Number: " << endl ;
  getline (cin,var);
  stringstream(var) >> numberA;
  cout << "Enter a int Number: " << endl ;
  getline (cin,var);
  stringstream(var) >> numberB;
  cout << "The multiplication is : " << numberB*numberA << endl;

  return 0;
}