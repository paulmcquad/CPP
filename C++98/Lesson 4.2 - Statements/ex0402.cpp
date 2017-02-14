// Example 4-2: Declarations that seem like expressions.
#include <iostream>
#include <ostream>
using namespace std;

class cls {
public:
  cls() { cout << "cls::cls()\n"; }
  cls(int x) { cout << "cls::cls(" << x << ")\n"; }
};

int x;
int* y = &x;

int main(int argc, char *argv[]){
	
  // The following are unambiguously expressions:
  // constructing instances of cls.
  cls(int(x));
  cls(*static_cast<int*>(y));

  // Without the redundant casts, though, they would look
  // like declarations, not expressions.
  cls(x);   // declares a variable x
  cls(*y);  // declares a pointer y
}
