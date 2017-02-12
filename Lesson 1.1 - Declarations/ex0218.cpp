// Example 2-18: Using the using declaration.
namespace numeric {
  struct fraction { };
  fraction operator+(int, const fraction&);
  fraction operator+(const fraction&, int);
  fraction operator+(const fraction&, const fraction&);
  bool operator>(const fraction&, int);
}

namespace eqn {
  struct fraction { };
  fraction operator+(int, const fraction&);
  fraction operator+(const fraction&, int);
  fraction operator+(const fraction&, const fraction&);
}

int main(int argc, char *argv[]){
	
  numeric::fraction nf;
  eqn::fraction qf;

  nf = nf + 1;           // OK: calls numeric::operator+
  qf = 1 + qf;           // OK: calls eqn::operator+
  nf = nf + qf;          // Error: no operator+

  using numeric::fraction;
  fraction f;            // f is numeric::fraction
  f = nf + 2;            // OK
  f = qf;                // Error: type mismatch
  using eqn::fraction;   // Error: like trying to declare
                         // fraction twice in the same scope
  if (f > 0) {
    using eqn::fraction; // OK: hides outer fraction
    fraction f;          // OK: hides outer f
    f = qf;              // OK: same types
    f = nf;              // Error: type mismatch
  }
  int fraction;          // Error: name fraction in use
}
