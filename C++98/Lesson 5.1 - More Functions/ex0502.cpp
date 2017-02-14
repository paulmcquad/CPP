// Example 5-2: Declaring and using default arguments
#include <iostream>
#include <ostream>
using namespace std;

namespace demo {
  int f()
  {
    return 20;
  }
}

int f()
{
  return 10;
}

// The default argument for y is always the global f(),
// even if a different f() is visible where func()
// is called.
int func(int x, int y = f())
{
  return x + y;
}

int main(int argc, char *argv[]){

  using demo::f;
  cout << f() << '\n';       // prints 20
  cout << func(32) << '\n';  // prints 42
}
