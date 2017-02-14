// Example 13-30: Sample allocator implementation.
#include <cstddef>
#include <limits>
#include <list>
using namespace std;

template<typename T>
class myallocator {
public:
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef T* pointer;
  typedef const T* const_pointer;
  typedef T& reference;
  typedef const T& const_reference;
  typedef T value_type;
  template <class U> struct rebind {
    typedef myallocator<U> other;
  };
  myallocator() throw()                          {}
  myallocator(const myallocator&) throw()        {}
  template <class U>
  myallocator(const myallocator<U>&) throw()     {}
  ~myallocator() throw()                         {}
  pointer address(reference x) const             {return &x;}
  const_pointer address(const_reference x) const {return &x;}
  pointer allocate(size_type n, void* hint = 0) {
    return static_cast<T*>(::operator new (n * sizeof(T)) );
  }
  void deallocate(pointer p, size_type n) {
    ::operator delete(static_cast<void*>(p));
  }
  size_type max_size() const throw() {
    return numeric_limits<size_type>::max() / sizeof(T);
  }
  void construct(pointer p, const T& val) {
    new(static_cast<void*>(p)) T(val);
  }
  void destroy(pointer p) {
    p->~T();
  }
};

template<typename T>
bool operator==(const myallocator<T>&, const myallocator<T>&)
{
  return true;
}

template<typename T>
bool operator!=(const myallocator<T>&, const myallocator<T>&)
{
   return false;
}

template<>
class myallocator<void> {
public:
  typedef void* pointer;
  typedef const void* const_pointer;
  typedef void value_type;
  template <class U> struct rebind {
    typedef myallocator<U> other;
  };
};

int main(int argc, char *argv[]){
	
  list<int, myallocator<int> > data;
  data.push_back(10);
  data.push_back(20);
  return data.size();
}
