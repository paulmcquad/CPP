// Example 13-19: A simple implementation of distance.
#include <iterator>
using namespace std;

namespace not_really_std {
  template<typename InputIter>
  typename iterator_traits<InputIter>::difference_type
  specialize_distance(InputIter first, InputIter last, ...)
  {
    typename iterator_traits<InputIter>::difference_type n;
    for (n = 0; first != last; ++first)
      ++n;
    return n;
  }

  template<typename InputIter>
  typename iterator_traits<InputIter>::difference_type
  specialize_distance(InputIter first, InputIter last,
                      random_access_iterator_tag)
  {
    return last - first;
  }

  template<typename InputIter>
  typename iterator_traits<InputIter>::difference_type
  distance(InputIter first, InputIter last)
  {
    return specialize_distance(first, last,
      iterator_traits<InputIter>::iterator_category());
  }
}
