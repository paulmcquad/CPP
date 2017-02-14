// Example 13-39: Making pairs of objects.
#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <ostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

// Functor, suitable for passing to for_each to find
// minimum and maximum values in a range.
template<typename T>
class minmax
{
public:
  minmax() : min_(numeric_limits<T>::max()),
             max_(numeric_limits<T>::min())
             {}
  void operator()(const T& x) {
    if (x < min_) min_ = x;
    if (max_ < x) max_ = x;
  }
  operator pair<T,T>() const {
    return make_pair(min_, max_);
  }
private:
  T min_;
  T max_;
};

int main(int argc, char *argv[]){
	
  map<string, int> wordcounts;
  wordcounts.insert(make_pair("hello", 1));

  vector<int> v;
  // fill v with data
  pair<int,int> mm =
    for_each(v.begin(), v.end(), minmax<int>());
  // do something with mm
}
