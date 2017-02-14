// Example 7-7: Specializing a function template.
#include <cmath>
using namespace std;
// primary template declaration
template<typename T> T root(T x, T y)
{
  return pow(x, 1.0/y);
}

// specialization where T is deduced to be long
template<> long root(long x, long y)
{
  if (y == 2)
    return sqrt((long double)x);
  else
    return pow((long double)x, 1.0l/y);
}

// specialization for explicit T=int
template<> int root<int>(int x, int y)
{
  if (y == 2)
    return sqrt(double(x));
  else
    return pow(double(x), 1.0/y);
}

// Overload with a different function template, such
// as valarray<T>.
template<template<typename> class C, typename T>
C<T> root(const C<T>& x, const C<T>& y)
{
  return pow(x, C<T>(1.0)/y);
}

int main(int argc, char *argv[]){
  root(10, 2);
  root(10L, 2L);
  root(10.0, 2.0);
}
