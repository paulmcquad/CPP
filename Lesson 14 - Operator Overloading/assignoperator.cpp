// Listing 14.6
// Copy constructors
#include <iostream>
using namespace std;
 
class CAT
{
 public:
     CAT(); // default constructor
     // copy constructor and destructor elided!
     int GetAge() const { return *itsAge; }
     int GetWeight() const { return *itsWeight; }
     void SetAge(int age) { *itsAge = age; }
     CAT operator=(const CAT &);

 private:
     int *itsAge;
     int *itsWeight;
};

 
CAT::CAT(){

     itsAge	 = new int;
     itsWeight = new int;

     *itsAge = 5;
     *itsWeight = 9;
}

CAT CAT::operator=(const CAT & rhs){

     if (this == &rhs)

         return *this;

     delete itsAge;
     delete itsWeight;

     itsAge = new int;
     itsWeight = new int;

     *itsAge = rhs.GetAge();
     *itsWeight = rhs.GetWeight();

     return *this;
}

int main(int argc, char *argv[]){
	
     CAT frisky;

     cout << "frisky's age: " << frisky.GetAge() 
         << endl;

     cout << "Setting frisky to 6...\n";

     frisky.SetAge(6);

     CAT whiskers;

     cout << "whiskers' age: " << whiskers.GetAge() 
         << endl;

     cout << "copying frisky to whiskers...\n";

     whiskers = frisky;

     cout << "whiskers' age: " << whiskers.GetAge() 
         << endl;

     return 0;
}