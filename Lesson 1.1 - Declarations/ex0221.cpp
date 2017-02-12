// Example 2-21: Using the using directive.
#include <iostream>
#include <ostream>

namespace A {
  int x = 10;
}
namespace B {
  int y = 20;
}
namespace C {
  int z = 30;
  using namespace B;
}
namespace D {
  int z = 40;
  using namespace B;       // harmless but pointless because
  int y = 50;              // D::y hides B::y
}

int main(int argc, char *argv[]){
	
  int x = 60;
  using namespace A;       // does not introduce names,
                           // so there is no conflict with x
  using namespace C;

  using namespace std;     // to save typing cout
                           // repeatedly

  cout << x << '\n';       // prints 60 (local x)
  cout << y << '\n';       // prints 20 
  cout << C::y << '\n';    // prints 20
  cout << D::y << '\n';    // prints 50

  using namespace D;
  cout << y << '\n'; // Error: y is ambiguous: it can be
                     // found in D::y and C's use of B::y.
}
//How to Use Namespaces