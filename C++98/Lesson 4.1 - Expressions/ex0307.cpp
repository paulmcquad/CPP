// Example 3-7: Using typeid.
#include <iostream>
#include <ostream>
#include <typeinfo>
using namespace std;

class base {
public:
  virtual ~base() {}
};

class derived : public base {};
enum color   { red, black };

// The actual output is implementation-defined, but should
// reflect the types shown in the comments.
int main(int argc, char *argv[]){
	
  base* b = new derived;
  cout << typeid(*b).name() << '\n';      // derived
  cout << typeid(base).name() << '\n';    // base
  derived* d = new derived;
  cout << typeid(*d).name() << '\n';      // derived
  cout << typeid(derived).name() << '\n'; // derived
  cout << typeid(red).name() << '\n';     // color
  cout << typeid(color).name() << '\n';   // color
}
