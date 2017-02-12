// Example 2-19: Creating synonym declarations with using declarations.
#include <iostream>
#include <ostream>
using namespace std;

namespace numeric {
  struct fraction {
     int numerator() const;
     int denominator() const;
  };
  fraction operator+(int, const fraction&);
  fraction operator+(const fraction&, int);
  fraction operator+(const fraction&, const fraction&);
}

namespace eqn {
  using numeric::fraction;
  // Big, ugly declaration for ostream << fraction
  template<typename charT, typename traits>
  basic_ostream<charT,traits>& operator<<(
    basic_ostream<charT,traits>& out, const fraction& f)
  {
    out << f.numerator() << '/' << f.denominator();
    return out;
  }
}

int main(int argc, char *argv[]){
	
  eqn::fraction qf;
  numeric::fraction nf;
  nf + qf;         // OK because the types are the same
  cout << qf; // Error: numeric namespace is searched
                   // for operator<<, but not eqn namespace
}
