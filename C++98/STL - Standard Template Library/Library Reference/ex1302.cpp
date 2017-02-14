// Example 13-2: Using generate to fill a vector with integers
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

// Generate a series of objects, starting with "start".
template <typename T>
class series {
public:
  series(const T& start) : next(start) {}
  T operator()() { return next++; }
private:
  T next;
};

int main(int argc, char *argv[]){

  vector<int> v;
  v.resize(10);
  // Generate integers from 1 to 10.
  generate(v.begin(), v.end(), series<int>(1));
  // Print the integers, one per line.
  copy(v.begin(), v.end(),
            ostream_iterator<int>(cout, "\n"));
}
