// Example 13-3: Using generate_n to print a series of integers
#include <algorithm>
#include <iostream>
#include <iterator>

// Use the same series template from Example 13-2.
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

  // Print integers from 1 to 10.
  generate_n(ostream_iterator<int>(cout,"\n"),
                  10, series<int>(1));
}
