// Listing 14.3 
// Returning the dereferenced this pointer 
#include <iostream>
using namespace std;

class Counter 
{
public:
     Counter();
     ~Counter(){}
     int GetItsVal()const { return itsVal; }
     void SetItsVal(int x) {itsVal = x; }
     const Counter& operator++ ();      // prefix
     const Counter operator++ (int); // postfix
private:
     int itsVal; 
};

Counter::Counter():
itsVal(0) 
{}

const Counter& Counter::operator++()   // prefix 
{
     ++itsVal;
     return *this; 
}

const Counter Counter::operator++(int)   // postfix 
{
     Counter temp(*this);
     ++itsVal;
     return temp; 
}

int main(int argc, char *argv[]){
	
     Counter i;
     cout << "The value of i is " << i.GetItsVal()
          << endl;
     i++;
     cout << "The value of i is " << i.GetItsVal()
          << endl;
     ++i;
     cout << "The value of i is " << i.GetItsVal()
          << endl;
     Counter a = ++i;
     cout << "The value of a: " << a.GetItsVal();
     cout << " and i: " << i.GetItsVal() << endl;
     a = i++;
     cout << "The value of a: " << a.GetItsVal();
     cout << " and i: " << i.GetItsVal() << endl;
     return 0; 
}