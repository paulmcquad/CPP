// Example 7-14: Computing at compile-time
#include <cmath>
using namespace std;

template<int x, unsigned y>
struct ipower {
  enum { value = x * ipower<x, y-1>::value };
};
template<int x>
struct ipower<x, 0> {
  enum { value = 1 };
};
template<unsigned y>
struct ipower<0, y> {
  enum { value = 0 };
};
template<> struct ipower<0, 0> {};

// Round off a floating point value to a fixed number
// of digits.
template<unsigned N, typename T>
T round(T x)
{
  if (x < 0.0)
    return floor(x * ipower<10,N>::value - 0.5) /
           ipower<10,N>::value;
  else
    return floor(x * ipower<10,N>::value + 0.5) /
           ipower<10,N>::value;
}
