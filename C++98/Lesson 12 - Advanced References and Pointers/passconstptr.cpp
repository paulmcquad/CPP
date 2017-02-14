//Listing 12.2
// Passing pointers to objects
#include <iostream>
using namespace std;
 
class SimpleCat
{

 public:
     SimpleCat();
     SimpleCat(SimpleCat&);
     ~SimpleCat();
     int GetAge() const { return itsAge; }
     void SetAge(int age) { itsAge = age; }

 private:
     int itsAge;

};

SimpleCat::SimpleCat()
{
     cout << "Simple Cat Constructor...\n";
     itsAge = 1;
}

SimpleCat::SimpleCat(SimpleCat&)
{
    cout << "Simple Cat Copy Constructor...\n";
}

SimpleCat::~SimpleCat()
{
     cout << "Simple Cat Destructor...\n";
}

const SimpleCat * const 
FunctionTwo (const SimpleCat * const theCat);

int main(int argc, char *argv[]){

     cout << "Making a cat...\n";

     SimpleCat Frisky;

     cout << "Frisky is ";
     cout << Frisky.GetAge() << " years old\n";

     int age = 5;

     Frisky.SetAge(age);

     cout << "Frisky is ";
     cout << Frisky.GetAge() << " years old\n";
     cout << "Calling FunctionTwo...\n";

     FunctionTwo(&Frisky);

     cout << "Frisky is ";
     cout << Frisky.GetAge() << " years old\n";

     return 0;

}

// functionTwo, passes a const pointer
const SimpleCat * const 

FunctionTwo (const SimpleCat * const theCat){
     cout << "Function Two. Returning...\n";
     cout << "Frisky is now " << theCat->GetAge();
     cout << " years old \n";
     // theCat->SetAge(8);   const!

     return theCat;
}