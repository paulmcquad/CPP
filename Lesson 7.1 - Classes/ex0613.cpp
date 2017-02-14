// Example 6-13: Exception-safe constructor
#include <cstddef>
#include <cstring>
#include <memory>
#include <cwchar>
using namespace std;

struct silly {
  silly(size_t n)
  : size_(n), str_(new char[n+1]), wstr_(new wchar_t[n+1])
  {}
  silly(const silly& that)
  : size_(that.size_), str_(new char[size_+1]), wstr_(new wchar_t[size_+1])
  {
     using namespace std;
     memcpy(str_.get(), that.str_.get(), size_+1);
     wmemcpy(wstr_.get(), that.wstr_.get(), size_+1);
  }
  silly& operator=(silly that)
  {
     using namespace std;
     size_ = that.size_;
     str_.reset(new char[size_+1]);
     memcpy(str_.get(), that.str_.get(), size_+1);
     wstr_.reset(new wchar_t[size_+1]);
     wmemcpy(wstr_.get(), that.wstr_.get(), size_+1);
     return *this;
  }
private:
  size_t size_;
  auto_ptr<char> str_;
  auto_ptr<wchar_t> wstr_;
};
