// Example 2-17: Using namespace aliases.
namespace original {
  int f();
}

namespace ns = original;     // alias

int ns::f() { return 42; }   // OK
using ns::f;                 // OK

int g() { return f(); }

namespace ns { // Error: cannot use alias here
  int h();
}
