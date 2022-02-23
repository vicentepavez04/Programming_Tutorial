


/*
Where class_name is a valid identifier for the class, object_names is an optional list of names for objects of this class.
The body of the declaration can contain members, which can either be data or function declarations, and optionally access specifiers.

 An access specifier is one of the following three keywords: private, public or protected:
        public - members are accessible from outside the class
        private - members cannot be accessed (or viewed) from outside the class
        protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes. You will learn more about Inheritance later.

*/

#include <iostream>
using namespace std;

class user
{
    private:
        string password;
    public:
        string username;
        user(string a, string b);
};

user::user(string a, string b)
{
    username = a;
    password = b;
}



int main()
{
    string x,y;
    cout << "Register now\n";
    cout << "Enter your username: ";
    getline(cin, x);
    cin.clear();
    cout << "Enter your password: ";
    getline(cin, y);

    user personA(x,y);

    cout << "Welcome " << personA.username << endl;
    
 

    return 0;
}