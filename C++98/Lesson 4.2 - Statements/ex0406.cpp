// Example 4-6: Multiple uses of for loops.
// One way to implement the for_each standard algorithm.
template<typename InIter, typename Function>
Function for_each(InIter first, InIter last, Function f)
{
  for ( ; first != last; ++first)
    f(*first);
  return f;
}

// One way to implement the generate_n standard algorithm.
template<typename OutIter, typename Size, typename Generator>
void generate_n(OutIter first, Size n, Generator gen)
{
  for (Size i = 0; i < n; ++i, ++first)
    *first = gen;
}
