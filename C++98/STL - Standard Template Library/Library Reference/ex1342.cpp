// Example 13-42: Using gslice for multidimensional arrays.
#include <cstddef>
#include <iostream>
#include <ostream>
#include <valarray>
#include "valarrayutil.h"

// See Example 13-41 for the va function.
int main(int argc, char *argv[]){
	
  using namespace std;
  valarray<int> a(24);
  for (size_t i = 0; i < a.size(); ++i)
    a[i] = i;
  cout << a[gslice(1, va(2, 3), va(12, 4))] << '\n';
// prints: { 1 5 9 13 17 21 }
}
