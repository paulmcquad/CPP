// Example 3-9: Using the sizeof operator.
#include <iostream>
#include <ostream>
using namespace std;

class base {};
class derived : public base {};

int main(int argc, char *argv[]){
	
  // The values actually printed depend on the
  // implementation, but many common implementations
  // print the values shown.
  using namespace std;
  cout << sizeof(base)  << '\n';      // prints 1
  cout << sizeof(derived)  << '\n';   // prints 1
  base b[3];
  cout << sizeof(b) << '\n';          // prints 3
  derived d[5];
  cout << sizeof(d) << '\n';          // prints 5
}
