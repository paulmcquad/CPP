// Example 2-1: Disambiguating declarations.
#include <iostream>
#include <ostream>
using namespace std;

class T
{
public:
  T()    { cout << "T()\n"; }
  T(int) { cout << "T(int)\n"; }
};

int a, x;

int main(int argc, char *argv[]){
	
  T(a);          // Variable named a of type T, not an
                 // invocation of the T(int) constructor.
  T b();         // Function named b of no arguments,
                 // not a variable named b of type T.
  T c(T(x));     // Declaration of a function named c,
                 // with one argument of type T.
}
