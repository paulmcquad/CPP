// Example 2-3: Name lookup trumps overload resolution.
#include <ios>
#include <iostream>
#include <ostream>
using namespace std;

void func(int i)
{
  cout << "int: " << i << '\n';
}

namespace N {
  void func(double d)
  {
    cout << "double: " << showpoint << d << '\n';
  }

  void call_func()
  {
    // Even though func(int) is a better match, the compiler
    // finds N::func(double) first.
    func(3);
  }
}

int main(int argc, char *argv[]){
	
  N::call_func();       // prints "double: 3.000000"
  using N::func;
  using ::func;
  // Now all overloaded func()s are at the same scope level
  func(4);              // prints "int: 4"
}
