// Example 3-4: Using dynamic_cast<>.
#include <iostream>
#include <ostream>
using namespace std;

class base {
public:
  virtual ~base() {}
};

class derived : public base {};
class most_derived : public derived {};
class other : public base {};

int main(int argc, char *argv[]){
	
  base* b = new derived;
  dynamic_cast<most_derived*>(b); // null pointer
  dynamic_cast<derived&>(*b);     // OK
  dynamic_cast<other*>(b);        // null pointer

  derived* d = new most_derived;
  b = d;
  b = dynamic_cast<base*>(d);    // OK. but dynamic_cast<>
                                 // is unnecessary
}
