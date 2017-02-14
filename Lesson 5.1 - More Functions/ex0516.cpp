// Example 5-16: Calling a class-type object as a function.
#include <iostream>
#include <ostream>
using namespace std;

typedef void (*strproc)(const char*);

void print(const char* str)
{
  cout << "const char*:" << str << '\n';
}

void print(int x)
{
  cout << "int:" << x << '\n';
}

void print(double x)
{
  cout << "double:" << x << '\n';
}

struct simple
{
  void operator()(int x)    { print(x); } // print(int)
  void operator()(double x) { print(x); } // print(double)
};

typedef void (*intfunc)(int);
typedef void (*dblfunc)(double);

struct indirect
{
  operator intfunc() { return print; } // print(int)
  operator dblfunc() { return print; } // print(double)
  operator strproc() { return print; } // print(const char*)
};

int main(int argc, char *argv[]){

  simple sim;
  indirect ind;

  sim(42);                    // prints "int:42"
  sim.operator()(42);         // prints "int:42"
  sim(42.0);                  // prints "double:42"
  ind(42);                    // prints "int:42"
  ind.operator intfunc()(42); // prints "int:42"
  ind(42.0);                  // prints "double:42"
  ind("forty-two");        // prints "const char*:forty-two"
}
