// Example 5-15: Finding candidate member functions.
#include <iostream>
#include <ostream>
using namespace std;

void proc(int x)
{
  cout << "proc(int:" << x << ")\n";
}

class base {
public:
  void f(int) { cout << "f(int)\n"; }
  void g(int) { cout << "g(int)\n"; }
  void proc(double) { cout << "base::proc(double)\n"; }
};

class derived : public base {
public:
  void f(double) { cout << "f(double)\n"; }
  void g(double x) {
    cout << "g(double)\n";
    proc(42); // calls base::proc(double), not ::proc(int)
  }
  using base::g;
};

// Declared after derived, so call to proc() inside g()
// never sees this proc().
void proc(double x)
{
  cout << "proc(double:" << x << ")\n";
}

int main(int argc, char *argv[]){

  derived d;
  d.g(3.14159); // calls g(double)
}
