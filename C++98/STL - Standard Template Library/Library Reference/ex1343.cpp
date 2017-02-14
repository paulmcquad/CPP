// Example 13-43: Using gslice_array.
#include <iostream>
#include <ostream>
#include <valarray>
#include "valarrayutil.h"

// See Example 13-41 for the va function.
int main(int argc, char *argv[]){
	
  using namespace std;
  const int data[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
  valarray<int> a(data, sizeof(data)/sizeof(data[0]));
  cout << a << '\n';
// prints { 1 2 3 4 5 6 7 8 }

  cout << a[gslice(1, va(2, 2), va(4, 2))] << '\n'
       << a[gslice(0, va(2, 2), va(4, 2))] << '\n';
// prints:
//  { 2 4 6 8 }
//  { 1 3 5 7 }

  // operator+ is not defined for gslice_array, so cast
  // to valarray to perform addition.
  cout <<
    static_cast<valarray<int> >(a[gslice(1, va(2,2), va(4,2))]) +
    static_cast<valarray<int> >(a[gslice(0, va(2,2), va(4,2))])
       << '\n';
// prints: { 3 7 11 15 }

  // Simple assignment does not require casting.
  a[gslice(0, va(2, 2), va(4, 2))] = 0;
  cout << a << '\n';
// prints: { 0 2 0 4 0 6 0 8 }

  // Computational assignment does not require casting.
  valarray<int> ten(10, 4);
  a[gslice(1, va(2, 2), va(4, 2))] *= ten;
  cout << a << '\n';
// prints: { 0 20 0 40 0 60 0 80 }
}
