#include <iostream>

using namespace std;


/*
Namespaces allow us to group named entities that otherwise would have global scope into narrower scopes, giving them namespace scope.
This allows organizing the elements of programs into different logical scopes referred to by names.

*/


//namespace identifier
namespace entities_A
{
  //named_entities
  int a = 3;
  double b= 2.2256;
  const int c=200;
}
namespace entities_B
{
  //named_entities
  int a = 45;
  double b= 0.256;
  const double c=200.365;

  int function_A(int x)
  {
      return x+4;
  }
}


int main()
{
    //identifier::entitie
    cout <<"entities_A::a = " << entities_A::a << endl;
    cout <<"entities_A::b = " << entities_A::b << endl;
    cout << "entities_A::c = " << entities_A::c << endl;


    using namespace entities_A;
    cout <<"using namespace a = " << a << endl;
    cout <<"using namespace b = " << b << endl;
    cout << "using namespace c = " <<c << endl;
    cout <<"entities_B::a = " << entities_B::a << endl;
    cout <<"entities_B::b = " << entities_B::b << endl;
    cout <<"entities_B::c = " <<entities_B::c << endl;
    cout <<"entities_B::function_A(10) = " <<entities_B::function_A(10) << endl;
}