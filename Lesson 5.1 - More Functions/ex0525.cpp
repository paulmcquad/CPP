// Example 5-25: Overloading new and delete.
#include <cstddef>
#include <iostream>
#include <memory>
#include <new>
#include <ostream>
using namespace std;

class demo
{
public:
  static void* operator new(size_t size)
  throw (bad_alloc)
  {
    cout << "demo::new\n";
    if (instance == 0)
      instance = ::new demo;
    ++count;
    return instance;
  }
  static void operator delete(void* p) {
    cout << "demo::delete\n";
    if (--count == 0) {
      ::delete instance;
      instance = 0;
    }
  }

  static demo* make() { return new demo(); }

private:
  demo() {}
  demo(const demo&);
  static demo* instance;
  static size_t count;
};

demo* demo::instance;
size_t demo::count;

int main(int argc, char *argv[]){

  auto_ptr<demo> s1(demo::make());
  auto_ptr<demo> s2(demo::make());
  return s1.get() == s2.get();
}
