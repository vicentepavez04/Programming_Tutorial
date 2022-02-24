#include <iostream>
using namespace std;

class OhmsLaw
{
    float R,I,V,P;
public:
    void setValues(float voltage, float resistance)
    {
        V = voltage;
        R = resistance;
        I = V/R;
        P = V*I;
    }

    friend class printer;

};

class printer
{
public:
    void variables(OhmsLaw W)
    {
        cout << "Resistance: " << W.R << endl;
        cout << "Voltage: " << W.V << endl;
        
    }
    void results(OhmsLaw W)
    {
        cout << "Current: " << W.I << endl;
        cout << "Power: " << W.P << endl;
    }

};


int main()
{
    float v=10;
    float r=20;

    OhmsLaw C;
    printer P;

    C.setValues(v,r);
    P.variables(C);
    P.results(C);
    
    return 0;
}