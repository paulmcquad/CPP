// Example 7-3: Deducing template arguments.
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <list>
#include <ostream>
#include <set>
using namespace std;

// Simple function template. Easy to deduce T.
template<typename T>
T min(T a, T b)
{
  return a < b ? a : b;
}

template<typename T, size_t Size>
struct array
{
  T value[Size];
};

// Deduce the row size of a 2D array.
template<typename T, size_t Size>
size_t dim2(T [][Size])
{
  return Size;
}

// Overload the function size() to return the number of
// elements in an array<> or in a standard container.
template<typename T, size_t Size>
size_t size(const array<T,Size>&)
{
  return Size;
}

template<template<typename T, typename A> class container,
         typename T, typename A>
typename container<T,A>::size_type size(container<T,A>& c)
{
  return c.size();
}

template<template<typename T, typename C, typename A>
           class container,
         typename T, typename C, typename A>
typename container<T,C,A>::size_type
size(container<T,C,A>& c)
{
  return c.size();
}

// More complicated function template. Easy to deduce Src,
// but impossible to deduce Dst.
template<typename Dst, typename Src>
Dst cast(Src s)
{
  return s;
}

int main(int argc, char *argv[]){
	
  min(10, 100);      // min<int>
  min(10, 1000L);    // Error: T cannot be int and long

  array<int,100> data1;
  // deduce T=int and SIZE=100 from type of data1
  cout << size(data1) << '\n';

  int y[10][20];
  cout << dim2(y) << '\n'; // prints 20

  list<int> lst;
  lst.push_back(10);
  lst.push_back(20);
  lst.push_back(10);
  cout << size(lst) << '\n';  // prints 3

  set<char> s;
  const char text[] = "hello";              
  copy(text, text+5, inserter(s, s.begin()));
  cout << size(s) << '\n';  // prints 4

  // Can deduce Src=int, but not return type, so
  // explicitly set Dst=char.
  char c = cast<char>(42);
}
