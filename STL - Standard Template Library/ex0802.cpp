// Example 8-2: Implementing the distance function template.
#include <iterator>

// Helper function, overloaded for random access iterators.
template<typename InputIter>
typename std::iterator_traits<InputIter>::difference_type
compute_dist(InputIter first, InputIter last,
             std::random_access_iterator_tag)
{
  return last - first;
}

// Helper function, overloaded for all other input
// iterators.
template<typename InputIter>
typename std::iterator_traits<InputIter>::difference_type
compute_dist(InputIter first, InputIter last,
             std::input_iterator_tag)
{
  typename std::iterator_traits<InputIter>::difference_type
    count = 0;
  while (first != last) {
    ++first;
    ++count;
  }
  return count;
}

// Main distance function, which calls the helper function,
// using the iterator tag to differentiate the overloaded
// functions.
template<typename InputIter>
typename std::iterator_traits<InputIter>::difference_type
distance(InputIter first, InputIter last)
{
  return compute_dist(first, last,
    std::iterator_traits<InputIter>::iterator_category());
}
