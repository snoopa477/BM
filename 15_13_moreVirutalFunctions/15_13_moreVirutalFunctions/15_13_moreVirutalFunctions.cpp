//Program to illustrate use of a virtual function
//to defeat the slicing problem.
#include <string>
#include <iostream>
using namespace std;

class Pet
{
public:
    virtual void print();
    string name;
};

class Dog : public Pet
{
public:
    virtual void print(); //Keyword virtual not needed, but put
                          //here for clarity. (It is also good style!)
    string breed;
};


class PetNoVirtual
{
public:
    void print();
    string name;
};

class DogNoVirtual : public PetNoVirtual
{
public:
    void print();
                          
    string breed;
};



int main()
{
    Dog vdog;
    Pet vpet;

    vdog.name = "Tiny";
    vdog.breed = "Great Dane";
    vpet = vdog;

    //vpet.breed; is illegal since class Pet has no member named breed

    Dog* pdog;
    pdog = new Dog;
    pdog->name = "Tiny";
    pdog->breed = "Great Dane";

    Pet* ppet;
    ppet = pdog;
    ppet->print(); // These two print the same output:
    pdog->print(); // name: Tiny breed: Great Dane

    //The following, which accesses member variables directly
    //rather than via virtual functions, would produce an error:

    //cout << "name: " << ppet->name << "  breed: " << ppet->breed << endl;
  
       //generates an error message: ��class Pet�� has no member
       //named ��breed�� .
       //See Pitfall section "Not Using Virtual Member Functions"
       //for more discussion on this.

    {
        cout << endl<< "no virtual experiements 1" << endl;
        DogNoVirtual* pdogNoVirtual;
        pdogNoVirtual = new DogNoVirtual;
        pdogNoVirtual->name = "Tiny";
        pdogNoVirtual->breed = "Great Dane";

        PetNoVirtual* ppetNoVirtual;
        ppetNoVirtual = pdogNoVirtual;
        ppetNoVirtual->print(); // These two print the same output:
        pdogNoVirtual->print(); // name: Tiny breed: Great Dane
    }


    {
        cout << endl << "Slicing" << endl;
        Dog vdog;
        Pet vpet;

        vdog.name = "Tiny";
        vdog.breed = "Great Dane";
        vpet = vdog;

        //C++ no suitable user-defined conversion from to exists
        //Dog vdog2 = (Dog)vpet;

        vdog.name = "Large";

        cout << vpet.name << endl;

    }


    return 0;
}

void DogNoVirtual::print()
{
    cout << "name: " << name << endl;
    cout << "breed: " << breed << endl;
}

void PetNoVirtual::print()
{
    cout << "name: " << endl;//Note no breed mentioned
}


void Dog::print()
{
    cout << "name: " << name << endl;
    cout << "breed: " << breed << endl;
}

void Pet::print()
{
    cout << "name: " << endl;//Note no breed mentioned
}