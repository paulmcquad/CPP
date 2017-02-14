// Example 2-5: Using the scope resolution operator.
#include <iostream>
#include <ostream>
using namespace std;

namespace n {
  struct counter {
    static int n;
  };
  double n = 2.71828;
}

int n::counter::n = 42; // define static data member

int main()
{
  int counter = 0;    // unrelated to n::counter
  int n = 10;         // hides namespace n
  ::n::counter x;     // refer to namespace n

  cout << n::counter::n; // prints 42
  cout << n::n;          // prints 2.71828
  cout << x.n;           // prints 42
  cout << n;             // prints 10
  cout << counter;       // prints 0
}
