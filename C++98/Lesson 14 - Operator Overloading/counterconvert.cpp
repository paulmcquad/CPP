// Listing 14.7
// This code won't compile!
#include <iostream>
using namespace std; 

class Counter
{
 public:
     Counter();
     ~Counter(){}
     int GetItsVal()const { return itsVal; }
     void SetItsVal(int x) {itsVal = x; }

 private:
     int itsVal;

};

Counter::Counter():
itsVal(0)
{}

int main(int argc, char *argv[]){

     int theShort = 5;

     Counter theCtr = theShort;
     cout << "theCtr: " << theCtr.GetItsVal() 
         << endl;

     return 0;
}

