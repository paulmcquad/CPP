// Example 4-10: Throwing and catching exceptions.
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <numeric>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

class bad_data : public out_of_range {
public:
  bad_data(int value, int min, int max)
  : out_of_range(make_what(value, min, max))
  {}
private:
  string make_what(int value, int min, int max);
};

string bad_data::make_what(int value, int min, int max)
{
  ostringstream out;
  out << "Invalid datum, " << value << ", must be in [" <<
          min << ", " << max << "]";
  return out.str();
}

// Read a set of numbers from an input stream.
// Verify that all data are within the defined boundaries.
// Throw bad_data if any datum is invalid. If an exception
// is thrown, tmp's destructor is automatically called
// (if it has a destructor).
template<typename T, typename charT, typename traits>
void getdata(basic_istream<charT,traits>& in,
             vector<T>& data, T min, T max)
{
  T tmp;
  while (in >> tmp)
  {
    if (tmp < min)
      throw bad_data(tmp, min, max);
    else if (tmp > max)
      throw bad_data(tmp, min, max);
    else
      data.push_back(tmp);
  }
}

// arbitrary precision integer (not really)
class bigint {
public:
  bigint() {}
  bigint(int v) : value_(v) {}
  ~bigint() {}
  operator int() const { return value_; }
private:
  int value_;
};

template<typename charT, typename traits>
basic_istream<charT,traits>&
operator>>(basic_istream<charT,traits>& in, bigint& x)
{
  int tmp;
  in >> tmp;
  x = tmp;
  return in;
}

int main(int argc, char *argv[]){
	
  using namespace std;
  if (argc < 2) {
    cerr << "usage: " << argv[0] << " FILE\n";
    return EXIT_FAILURE;
  }

  vector<bigint> data;
  ifstream in(argv[1]);
  if (! in) {
    perror(argv[1]);
    return EXIT_FAILURE;
  }
  try {
    getdata(in, data, bigint(0), bigint(100));
  } catch (const bad_data& ex) {
    cerr << argv[1] << ": " << ex.what() << '\n';
    return EXIT_FAILURE;
  } catch(...) {
    cerr << "fatal error: unknown exception\n";
    return EXIT_FAILURE;
  }

  if (data.size() == 0)
    cout << "no data\n";
  else {
    bigint sum(accumulate(data.begin(),data.end(),bigint()));
    cout << "avg=" << sum / data.size() << '\n';
  }
}
