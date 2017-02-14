// Example 5-1: Declaring functions.
#include <iostream>
#include <ostream>
#include <string>
using namespace std;

// Function named "add", which returns type int, and
// takes two parameters, each of type int. The names a and b
// are optional.
int add(int a, int b);

// Function named "print", which takes a const string
// reference, and does not return anything. The function is
// expanded inline.
inline void print(const string& str)
{
  cout << str;
}

// Function named "test", which takes two floating point
// arguments and return an enumeration. This function
// does not throw any exceptions.
enum fptest { less=-1, equal, greater };
fptest test(double, double) throw();

class demo {
public:
  // Member function named "value", returning type int,
  // taking no arguments, and is const, which means it
  // can be called for a const object.
  int value() const;
  // Function named "~demo", that is, a destructor,
  // that is virtual. Constructors and destructors do not
  // have return types. Destructors do not take arguments.
  virtual ~demo();
  // Inline, overloaded, const type conversion operator.
  operator bool() const { return value() != 0; }
};
