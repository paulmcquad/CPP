// Example 7-12: Resolving dependent names.
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ostream>
#include <stdexcept>
using namespace std;

template<unsigned Size, typename T>
class array {
  
  class iterator_base {
  public:
    iterator_base& operator++() {
      ++ptr;
      return *this;
    }
    T operator*() const { check(); return *ptr; }
    
    bool operator==(const iterator_base& that) {
      return this->ptr == that.ptr && this->start == that.start;
    }
    bool operator!=(const iterator_base& that) {
      return ! (*this == that);
    }
    bool operator<(const iterator_base& that) {
        return this->ptr == that.ptr && this->start < that.start;
    }
    bool operator>(const iterator_base& that) {
        return that < *this;
    }
    bool operator<=(const iterator_base& that) {
        return !(*this > that);
    }
    bool operator>=(const iterator_base& that) {
        return !(*this < that);
    }
    ptrdiff_t operator-(const iterator_base& that) {
        return this->start - that.start;
    }

  protected:
    iterator_base(T* s, T* p) : start(s), ptr(p) {}
    void check() const {
      if (ptr >= start + Size)
        throw out_of_range("iterator out of range");
    }
    T* ptr;
    T* start;
  };
public:
  array(): data(new T[Size]) {}
  class const_iterator : public iterator_base,
    public iterator<random_access_iterator_tag,T>
  {
  public:
    const_iterator(T* s, T* p) : iterator_base(s, p) {}
    T operator*() {
      iterator_base::check();
      return *this->ptr;
    }
  };

  class iterator : public iterator_base,
    public iterator<random_access_iterator_tag,T>
  {
  public:
    iterator(T* s, T* p) : iterator_base(s, p) {}
    operator const_iterator() const {
      return const_iterator(this->start, this->ptr);
    }
    T& operator*() {
      iterator_base::check();
      return *this->ptr;
    }
  };

  friend class iterator;
  friend class const_iterator;
  
  iterator begin() { return iterator(data, data); }
  iterator end()   { return iterator(data, data + Size); }
  const_iterator begin() const { return const_iterator(data, data); }
  const_iterator end()   const { return const_iterator(data, data + Size); }
  template<typename charT, typename traits>
  void print(basic_ostream<charT,traits>& out)
  const
  {
    copy(begin(), end(), ostream_iterator<T>(out));
  }
private:
  T* data;
};

namespace big {
  class integer {
  public:
    integer(int x = 0) : x_(x) {}
    operator int() const { return x_; }
  private:
    int x_; // Actual big integer implementation is left
            // as an exercise for the reader.
  };

  template<typename charT, typename traits>
  basic_ostream<charT,traits>&
    operator<<(basic_ostream<charT,traits>& out,
               const integer& i)
  {
    out << int(i);
    return out;
  }
}

int main(int argc, char *argv[]){
	
  const array<10, big::integer> a;
  a.print(cout);
}
