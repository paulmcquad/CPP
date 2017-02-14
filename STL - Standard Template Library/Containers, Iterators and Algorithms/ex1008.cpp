// Example 10-8: Computing statistics with a functor.
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <ostream>

template<typename T>
class Statistics {
public:
  typedef T value_type;
  Statistics() : n_(0), sum_(0), sumsq_(0) {}
  void operator()(double x) {
    ++n_;
    sum_ += x;
    sumsq_ += x * x;
  }
  std::size_t count() const { return n_; }
  T sum()             const { return sum_; }
  T sumsq()           const { return sumsq_; }
  T mean()            const { return sum_ / n_; }
  T variance()        const
      { return (sumsq_ - sum_*sum_ / n_) / (n_ - 1); }
private:
  std::size_t n_;
  T sum_;
  T sumsq_; // sum of squares
};

int main(int argc, char *argv[]){
	
  using namespace std;

  Statistics<double> stat = for_each(
    istream_iterator<double>(cin),
    istream_iterator<double>(),
    Statistics<double>());

  cout << "count=" << stat.count() << '\n';
  cout << "mean =" << stat.mean() << '\n';
  cout << "var  =" << stat.variance() << '\n';
  cout << "stdev=" << sqrt(stat.variance()) << '\n';
  cout << "sum  =" << stat.sum() << '\n';
  cout << "sumsq=" << stat.sumsq() << '\n';
}

