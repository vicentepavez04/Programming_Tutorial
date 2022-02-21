#include <iostream>
using namespace std;


struct metric
{
    double accuracy;
    double error;
};




int main()
{
    metric A , *B;
    B = &A;

    cout << " Enter the accuracy: ";
    cin >> B -> accuracy; // B -> accuracy (==) (*B).accuracy

    cout << " Enter the error: ";
    cin >> (*B).error;


    cout << A.accuracy << '\t' << A.error;


    return 0;
}