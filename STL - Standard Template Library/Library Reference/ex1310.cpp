// Example 13-10: Functional to round off a floating point number.
#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>
using namespace std;

// Functional for a binary function that rounds off
// a floating point number (of type FltT) to some number
// of decimal places (supplied as an unsigned).
template<typename FltT>
struct roundoff : binary_function<FltT,unsigned,FltT> {
  FltT operator()(FltT x, unsigned digits) const {
    FltT y = pow(10.0, static_cast<FltT>(digits));
    FltT z = x * y;
    return (z < 0 ? ceil(z - 0.5) : floor(z + 0.5)) / y;
  }
};

int main(int argc, char *argv[]){
	
  vector<double> seq(3), seq2(3);
  seq[0] = 3.14159;
  seq[1] = 2.71828;
  seq[2] = -3.5;

  // Copy seq to seq2, rounding off to 2 decimal places.
  transform(seq.begin(), seq.end(), seq2.begin(),
    bind2nd(roundoff<double>(), 2));
    
  copy(seq2.begin(), seq2.end(),
            ostream_iterator<double>(cout, "\n"));
}