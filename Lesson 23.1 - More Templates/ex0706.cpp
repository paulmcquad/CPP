// Example 7-6: Declaring friend templates and friends of templates.
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <ostream>
using namespace std;

template<typename T, size_t Size>
class array {
public:
  typedef T value_type;

  class iterator_base :
    iterator<random_access_iterator_tag, T> {
  public:
    typedef T value_type;
    typedef size_t size_type;
    typedef ptrdiff_t distance_type;

    friend inline bool operator==(const iterator_base& x,
                                  const iterator_base& y)
    {
      return x.ptr_ == y.ptr_;
    }
    friend inline bool operator!=(const iterator_base& x,
                                  const iterator_base& y)
    {
      return ! (x == y);
    }
    friend inline ptrdiff_t operator-(const iterator_base& x,
                                           const iterator_base& y)
    {
      return x.ptr_ - y.ptr_;
    }

  protected:
    iterator_base(const iterator_base& that) 
      : ptr_(that.ptr_) {}
    iterator_base(T* ptr) : ptr_(ptr) {}
    iterator_base(const array& a, size_t i)
      : ptr_(a.data_ + i) {}

    T* ptr_;
  };

  friend class iterator_base;

  class iterator : public iterator_base {
  public:
    iterator(const iterator& that) : iterator_base(that) {}
    T& operator*()         const { return *this->ptr_; }
    iterator& operator++() { ++this->ptr_; return *this; }
    T* operator->()        const { return this->ptr_; }

  private:
    friend class array;
    iterator(const array& a, size_t i = 0)
      : iterator_base(a, i) {}
    iterator(T* ptr) : iterator_base(ptr) {}

    friend inline iterator operator+(iterator iter, int off)
    {
      return iterator(iter.ptr_ + off);
    }
  };

  class const_iterator : public iterator_base {
  public:
    const_iterator(const const_iterator& that) : iterator_base(that) {}
    T operator*()          const { return *this->ptr_; }
    const_iterator& operator++() { ++this->ptr_; return *this; }
    const T* operator->()  const { return this->ptr_; }

  private:
    friend class array;
    const_iterator(const array& a, size_t i = 0)
      : iterator_base(a, i) {}
    const_iterator(T* ptr) : iterator_base(ptr) {}

    friend inline const_iterator operator+(const_iterator iter, int off)
    {
      return const_iterator(iter.ptr_ + off);
    }
  };

  array() : data_(new T[Size]) {}
  array(const array& that);
  ~array()                     { delete[] data_; }
  iterator begin()             { return iterator(*this); }
  const_iterator begin() const { return iterator(*this); }
  iterator end();
  const_iterator end()   const;
  T& operator[](size_t i);
  T operator[](size_t i) const;

  template<typename U, size_t USize>
  friend void swap(array<U,USize>& a, array<U,USize>& b);

private:
  T* data_;
};

template<typename T, size_t Size>
void swap(array<T,Size>& a, array<T,Size>& b)
{
  T* tmp = a.data_;
  a.data_ = b.data_;
  b.data_ = tmp;
}
