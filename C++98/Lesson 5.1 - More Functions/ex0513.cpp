// Example 5-13: Overloading inherited functions.
#include <iostream>
#include <ostream>
using namespace std;

class base {
public:
  void f(int) { cout << "f(int)\n"; }
  void g(int) { cout << "g(int)\n"; }

};

class derived : public base {
public:
  void f(double) { cout << "f(double)\n"; }
  void g(double) { cout << "g(double)\n"; }
  using base::g; // g(int) and g(double) are visible
};

int main(int argc, char *argv[]){

  derived d;

  d.f(3);   // calls derived::f(double)
  d.g(42);  // calls base::g(int)
}
