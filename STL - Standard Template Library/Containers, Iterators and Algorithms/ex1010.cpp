// Example 10-10: Finding the median of a range.
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>

template<typename FwdIter, typename Compare>
FwdIter median(FwdIter first, FwdIter last, Compare compare)
{
  typedef typename std::iterator_traits<FwdIter>::value_type value_type;
  std::vector<value_type> tmp(first, last);
  typename std::vector<value_type>::size_type median_pos = tmp.size() / 2;
  std::nth_element(tmp.begin(), tmp.begin() + median_pos,
                   tmp.end(), compare);
  return std::find(first, last, tmp[median_pos]);
}

int main(int argc, char *argv[]){
	
  std::vector<int> v;
  v.push_back(10);
  v.push_back(100);
  v.push_back(42);
  v.push_back(-10);
  v.push_back(33);
  v.push_back(72);
  v.push_back(50);
  
  return *median(v.begin(), v.end(), std::less<int>());
}
