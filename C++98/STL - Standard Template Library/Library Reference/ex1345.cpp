// Example 13-45: Using mask_array:
#include <iostream>
#include <ostream>
#include <valarray>
#include "valarrayutil.h"

// Simple average.
template<typename T>
T avg(const valarray<T>& a)
{
  return a.sum() / a.size();
}

int main(int argc, char *argv[]){
	
  using namespace std;
  const int data[] = { 1, -3, 10, 42, -12, 13, -7, 69 };
  valarray<int> a(data, sizeof(data)/sizeof(data[0]));
  cout << a << '\n';
// prints: { 1 -3 10 42 -12 13 -7 69 }

  // Print the values that are above average.
  cout << "avg=" << avg(a) << '\n';
  cout << a[a > avg(a)] << '\n';
// prints: { 42 69 }

  // Force all negative values to be zero. Notice how
  // no cast is needed for the simple assignment.
  a[a < 0] = 0;
  cout << a << '\n';
// prints: { 1 0 10 42 0 13 0 69 }

  // Other operations, such as multiplication by a scalar
  // is defined only for valarray, so a cast is needed.
  cout << static_cast<valarray<int> >(a[a > 0]) * -1 << '\n';
// prints: { -1 -10 -42 -13 -69 }
}
