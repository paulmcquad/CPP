// Example 3-6: Using static_cast<>.
#include <iostream>
#include <ostream>
using namespace std;

class base {};
class derived : public base {};
class other : public base {};

enum color   { red, black };
enum logical { no, yes, maybe };

int main(int argc, char *argv[]){
	
  base* b = new derived;
  static_cast<derived&>(*b); // OK
  static_cast<other*>(b);    // undefined behavior

  derived* d = new derived;
  b = d;
  b = static_cast<base*>(d); // OK, but unnecessary

  color c = static_cast<color>(yes);

  int i = 65;
  cout << static_cast<char>(i);
}
