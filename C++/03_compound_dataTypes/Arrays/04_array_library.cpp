#include <iostream>
#include <array>

using namespace std;

int main()
{

    // template < class T, size_t N > class array;

    array<int, 5> array_A;
    array<int, 5> array_B = {1, 2, 3, 4, 5};

    for(int i =0; i<5; i++)
    {
        array_A.at(i)=i+1;
        cout << array_A.at(i) << endl;
    }


    cout << "Front: "<< array_A.front() << endl;
    cout << "Back: "<< array_A.back() << endl;

    // the memory location where the array start and ends
    cout << "begin: "<< array_A.cbegin() << endl;
    cout << "end: "<< array_A.cend() << endl;
    for(auto it=array_A.cbegin(); it!=array_A.cend(); ++it)
    {
        cout << *it << endl;
    }

    cout << "Array size: " << array_A.size() << endl;
  

}