// Listing 14.2
// Overloading the increment operator
#include <iostream>
using namespace std;
 
class Counter
{

 public:
     Counter();
     ~Counter(){}
     int GetItsVal()const { return itsVal; }
     void SetItsVal(int x) {itsVal = x; }
     void Increment() { ++itsVal; }
     const Counter& operator++ ();
 
 private:
     int itsVal;

};

Counter::Counter():
itsVal(0)
{}

const Counter& Counter::operator++(){

     ++itsVal;
     return *this;
}

int main(int argc, char *argv[]){

     Counter i;

     cout << "The value of i is " << i.GetItsVal() 

         << endl;

     i.Increment();

     cout << "The value of i is " << i.GetItsVal() 

         << endl;

     ++i;

     cout << "The value of i is " << i.GetItsVal() 

         << endl;

     Counter a = ++i;

     cout << "The value of a: " << a.GetItsVal();
     cout << " and i: " << i.GetItsVal() << endl;

     return 0;
}

