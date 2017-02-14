// Example 6-14: Declaring a destructor.
#include <algorithm>
#include <cstddef>
using namespace std;

class string {
public:
  string(size_t n, char c = '\0')
  : str_(new char[n+1]), size_(n) {
    fill(str_, str_+size_+1, c);
  }
  string() : str_(new char[1]), size_(0) {
    str_[0] = '\0';
  }
  ~string() { delete[] str_; }
  const char* c_str() const { return str_; }
  size_t size()  const { return size_; }
private:
  size_t size_;
  char*  str_;
};
