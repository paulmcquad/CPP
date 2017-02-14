// Example 13-41: Generalized slicing of a valarray.
#include <cstddef>
#include <iostream>
#include <ostream>
#include <valarray>
#include "valarrayutil.h"

int main(int argc, char *argv[]){
	
  using namespace std;
  valarray<int> a(24);
  for (size_t i = 0; i < a.size(); ++i)
    a[i] = i;
  cout << a << '\n';
// prints { 0 1 2 3 4 5 6 7 8 9 10 11 ... 20 21 22 23 }

  cout << a[slice(1, 4, 3)] << '\n';
// prints { 1 4 7 10 }
  cout << a[gslice(1, va(4), va(3))] << '\n';
// prints { 1 4 7 10 }

  const valarray<int> const_a(a);
  cout << const_a[gslice(2, va(4, 3), va(2, 3))] << '\n';
// prints { 2 5 8 4 7 10 6 9 12 8 11 14 }
}
