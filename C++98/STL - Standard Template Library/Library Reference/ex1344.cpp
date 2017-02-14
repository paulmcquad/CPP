// Example 13-44: Using indirect_array:
#include <cstddef>
#include <iostream>
#include <ostream>
#include <valarray>
#include "valarrayutil.h"

int main(int argc, char *argv[]){
	
  using namespace std;
  const int data[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
  valarray<int> a(data, sizeof(data)/sizeof(data[0]));
  cout << a << '\n';
// prints: { 1 2 3 4 5 6 7 8 }

  // Specify the indices into a.
  const size_t p[] = { 2, 3, 5, 7 };
  valarray<size_t> indices(p, sizeof(p)/sizeof(p[0]));
  cout << a[indices] << '\n';
// prints: { 3 4 6 8 }

  // Add 10 to the elements at the desired indices.
  valarray<int> ten(10, 4);
  a[indices] += ten;
  cout << a << '\n';
// prints: { 1 2 13 14 5 16 7 18 }

  // Must cast to perform ordinary arithmetic.
  cout << static_cast<valarray<int> >(a[indices])
          * ten << '\n';
// prints: { 130 140 160 180 }
}
