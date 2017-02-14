// Example 2-20: Using declarations in classes.
#include <cstddef>
#include <vector>

template<typename T>
class array: private vector<T>
{
public:
  typedef T value_type;
  using vector<T>::size_type;
  using vector<T>::difference_type;
  using vector<T>::iterator;
  using vector<T>::const_iterator;
  using vector<T>::reverse_iterator;
  using vector<T>::const_reverse_iterator;

  array(size_t n, const T& x = T()) : vector<T>(n, x) {}
  using vector<T>::at;
  using vector<T>::back;
  using vector<T>::begin;
  using vector<T>::empty;
  using vector<T>::end;
  using vector<T>::front;
  using vector<T>::operator[];
  using vector<T>::rbegin;
  using vector<T>::rend;
  using vector<T>::size;
};
