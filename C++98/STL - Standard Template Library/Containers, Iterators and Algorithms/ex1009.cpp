// Example 10-9: One way to implement the copy_if function.
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

template<typename InIter, typename OutIter, typename Pred>
OutIter copy_if(InIter first, InIter last, OutIter result,
                Pred pred)
{
  for (; first != last; ++first)
    if (pred(*first)) {
      *result = *first;
      ++result;
    }
  return result;
}

int main(int argc, char *argv[]){
	
  std::vector<int> v;
  v.push_back(10);
  v.push_back(-10);
  v.push_back(42);
  v.push_back(-2);
  std::vector<int> v2;
  copy_if(v.begin(), v.end(),
    std::ostream_iterator<int>(std::cout, "\n"),
    std::bind2nd(std::greater<int>(), 0));
}
