// Example 4-7: Using break in the find_if algorithm.
// One way to implement the find_if standard algorithm.
template<typename InIter, typename Predicate>
InIter find_if(InIter first, InIter last, Predicate pred)
{
  for ( ; first != last; ++first)
    if (pred(*first))
      break;

  return first;
}
