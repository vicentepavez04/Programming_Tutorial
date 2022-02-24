#include <iostream>
using namespace std;


class store
{
    string Name;
    string Street;
    int Sales;
    int Costumers; 
public:
    store(string name, string street)
    {
        Name = name;
        Street = street;
        Sales = 0;
        Costumers = 0;
    }

    void newSale()
    {
        Costumers++;
    }
    void newCostumer()
    {
        Sales++;
    }
    void printer(){
        cout << "\n\nName: " << Name << endl;
        cout << "Street: " << Street << endl;
        cout << "Sales: " << Sales << endl;
        cout << "Costumers: " << Costumers << endl;
    }
};

class PetStore:public store
{
    int products;
public:
    // call the constructor of the base class and add a initialize a private variable from this class.
    PetStore(string name, string street):store(name, street){
        products=0;
    }
    void newproduct(){
        products++;
    }
    void howManyProducts(){
        cout << "Products: " << products << endl;
    }


};


int main()
{

    PetStore Pet("Doggi's store", "Michigan street");

    // FROM THE BASE CLASS (parent) (store)
    Pet.newCostumer();
    Pet.newSale();
    Pet.printer();


    // FROM THE DERIVED CLASS (child) (petstore)
    Pet.newproduct(); 
    Pet.howManyProducts();


    store clothesStore("Zara", "Elm street");
    // FROM THE BASE CLASS (parent) (store)
    Pet.newCostumer();
    Pet.newSale();
    Pet.newSale();
    Pet.newSale();
    Pet.printer();


    return 0;
}