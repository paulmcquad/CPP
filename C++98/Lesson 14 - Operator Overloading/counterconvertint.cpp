// Listing 14.9
// conversion operator
#include <iostream>
using namespace std;

class Counter
{

 public:
     Counter();
     Counter(int val);
     ~Counter(){}
     int GetItsVal()const { return itsVal; }
     void SetItsVal(int x) {itsVal = x; }
     operator unsigned short();

 private:
     int itsVal;

};

Counter::Counter():
itsVal(0)
{}

Counter::Counter(int val):
itsVal(val)
{}

Counter::operator unsigned short (){

     return ( int (itsVal) );
}

int main(int argc, char *argv[]){
	
     Counter ctr(5);

     int theShort = ctr;

     cout << "theShort: " << theShort << endl;

     return 0;

}