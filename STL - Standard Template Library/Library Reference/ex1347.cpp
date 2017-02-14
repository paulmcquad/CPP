// Example 13-47: Slicing a valarray.

#include <iostream>
#include <ostream>
#include <valarray>
#include "valarrayutil.h"

int main(int argc, char *argv[]){
	
  using namespace std;
  const int data[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
  valarray<int> v(data, sizeof(data)/sizeof(data[0]));
  const int newdata[] = { 30, 70, 110 };
  valarray<int> rpl(newdata, 3);
  v[slice(2, 3, 4)] = rpl;
  cout << v << '\n';
// prints: { 1 2 30 4 5 6 70 8 9 10 110 12 13}
  v[slice(3, 4, 2)] = -1;
  cout << v << '\n';
// prints: { 1 2 30 -1 5 -1 70 -1 9 -1 110 12 13}
  valarray<int> mult(3, 2);
  v[slice(8, 2, 3)] *= mult;
  cout << v << '\n';
// prints: { 1 2 30 -1 5 -1 70 -1 27 -1 110 36 13}
  cout << static_cast<valarray<int> >(v[slice(1, 5, 2)])
       << '\n';
// prints: { 2 -1 -1 -1 -1}
  cout << static_cast<valarray<int> >(v[slice(4, 3, 2)]) +
          static_cast<valarray<int> >(v[slice(2, 3, 2)])
       << '\n';
// prints: { 35 75 97}
}
