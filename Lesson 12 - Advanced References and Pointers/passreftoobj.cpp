//Listing 12.3
// Passing references to objects
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

 

 SimpleCat::SimpleCat(){

     cout << "Simple Cat Constructor...\n";
     itsAge = 1;
}

SimpleCat::SimpleCat(SimpleCat&){

     cout << "Simple Cat Copy Constructor...\n";

}

SimpleCat::~SimpleCat(){

     cout << "Simple Cat Destructor...\n";

}

const SimpleCat & FunctionTwo (const SimpleCat & theCat);

int main(int argc, char *argv[]){
	
     cout << "Making a cat...\n";

     SimpleCat Frisky;

     cout << "Frisky is " << Frisky.GetAge() 
               << " years old\n";

     int age = 5;
     Frisky.SetAge(age);

     cout << "Frisky is " << Frisky.GetAge() 
               << " years old\n";

     cout << "Calling FunctionTwo...\n";

     FunctionTwo(Frisky);

     cout << "Frisky is " << Frisky.GetAge() 
               << " years old\n";

     return 0;

 }

 

 // functionTwo passes a ref to a const object

const SimpleCat & FunctionTwo (const SimpleCat & theCat){
     cout << "Function Two. Returning...\n";
     cout << "Frisky is now " << theCat.GetAge()
               << " years old \n";

     // theCat.SetAge(8);   const!

     return theCat;
}