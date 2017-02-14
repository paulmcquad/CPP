// Example 6-22: Constructing and destructing an object.
#include <iostream>
#include <ostream>
using namespace std;

struct base {
  base()  { whoami(); }
  ~base() { whoami(); }
  virtual void whoami() { cout << "I am base\n"; }
};

struct derived : base {
  derived()  { whoami(); }
  ~derived() { whoami(); }
  virtual void whoami() { cout << "I am derived\n"; }
};

struct most_derived : virtual derived {
  most_derived()  { whoami(); }
  ~most_derived() { whoami(); }
  virtual void whoami()
  {
    cout << "I am most_derived\n";
  }
};

int main(int argc, char *argv[]){
	
  most_derived md;
  // prints:
  // I am base
  // I am derived
  // I am most_derived
  // I am most_derived
  // I am derived
  // I am base
}
