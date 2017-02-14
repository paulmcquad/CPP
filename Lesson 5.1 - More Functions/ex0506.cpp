// Example 5-6: Declaring exception specifications.
#include <string>
#include <typeinfo>
using namespace std;

class base {
public:
  virtual void f() throw();
  virtual void g(); // can throw anything
  virtual void h() throw(string);
};

class derived : public base {
public:
  virtual void f() throw();    // OK: same as base
  virtual void g() throw(int); // OK: subset of base
  virtual void h() throw(int); // Error: int not in base
};

class more : public derived {
public:
  virtual void f();            // Error: can throw anything
  virtual void g() throw();    // OK
};

void dostuff(int);

// Function does not throw any exceptions.
int noproblem(int x, int y) throw()
try
{
  dostuff(x);
  dostuff(y);
  return 1;
}
catch(...)
{
  return 0;
}

derived* downcast(base* b) throw(bad_cast)
{
  return dynamic_cast<derived*>(b);
}
