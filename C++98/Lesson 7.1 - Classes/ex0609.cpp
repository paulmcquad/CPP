// Example 6-9: Using a pointer-to-member.
#include <iostream>
#include <ostream>
using namespace std;

class base {
public:
  base(int i) : x_(i) {}
  virtual ~base() {}
  virtual void func() { cout << "base::func()\n"; }
private:
  int x_;
};

class derived : public base {
public:
  derived(int i) : base(i) {}
  virtual void func() { cout << "derived::func()\n"; }
};

int main(int argc, char *argv[]){
	
  base *b = new derived(42);
  void (base::*fp)() = &base::func;
  (b->*fp)();                      // prints derived::func()
}
