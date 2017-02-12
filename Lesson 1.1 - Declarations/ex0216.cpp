// Example 2-16: Using unnamed namespaces.
#include <iostream>
#include <ostream>
using namespace std;

namespace {
  int i = 10;
}

namespace {
  int j;          // same unnamed namespace
  namespace X {
    int i = 20;   // hides i in outer, unnamed namespace
  }
  namespace Y = X;
  int f() { return i; }
}

namespace X {
  int i = 30;
  // X::unnamed is different namespace from ::unnamed
  namespace {
    int i = 40;  // hides ::X::i, but is inaccessible
                 // outside the unnamed namespace
    int f() { return i; }
  }
}

int main(int argc, char *argv[]){
	
  int i = X::i;  // Error: unnamed::X or ::X?
  cout << ::X::f() << '\n'; // prints 40
  cout << Y::i << '\n';     // prints 20
  cout << f() << '\n';      // prints 10
}
