// Example 13-40: Printing a valarray or subset array.
#ifndef VALARRAYUTIL_H
#define VALARRAYUTIL_H

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <valarray>

// Print a valarray on one line, enclosed by curly braces,
// e.g., "{ 1 2 3 }".
template<typename T>
void print_valarray(std::ostream& out,
                    const std::valarray<T>& a)
{
  out << '{';
  for (std::size_t i = 0; i < a.size(); ++i)
    out << ' ' << a[i];
  out << " }";
}

// Print a slice_array, gslice_array, etc., by converting
// to a valarray. Converting a valarray to a valarray is
// wasteful, but harmless for these simple examples.
template<template<typename> class U, typename T>
std::ostream& operator<<(std::ostream& out, const U<T>& x)
{
  print_valarray(out, static_cast<const std::valarray<T> >(x));
  return out;
}

// Different libraries implement valarray differently. There is
// no simple way to write operator<< so it works for any
// implementation of slice_array, etc. For example, some implementations
// take two template parameters, not one.
template<template<typename, typename> class U, typename T, typename V>
std::ostream& operator<<(std::ostream& out, const U<V,T>& x)
{
  print_valarray(out, static_cast<const std::valarray<T> >(x));
  return out;
}


// Construct valarray objects from a few integers.
std::valarray<std::size_t> va(std::size_t a0)
{
  std::valarray<std::size_t> result(1);
  result[0] = a0;
  return result;
}

std::valarray<std::size_t> va(std::size_t a0, std::size_t a1)
{
  std::valarray<std::size_t> result(2);
  result[0] = a0;
  result[1] = a1;
  return result;
}

#endif
