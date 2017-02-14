// Example 2-13: Encapsulating reference traits.
#include <memory>
#include <vector>
using namespace std;

// Ref type trait encapsulates reference type,
// and mapping to and from the type for use in a container.
template<typename T>
struct Ref {
  typedef T value_type;
  typedef T& reference;
  typedef const T& const_reference;
  typedef T* pointer;
  typedef const T* const_pointer;
  typedef T container_type;
  static reference from_container(reference x) { return x; }
  static const_reference from_container(const_reference x)
                                               { return x; }
  static reference to_container(reference x)   { return x; }
};

template<typename T>
struct Ref<T&> {
  typedef T value_type;
  typedef T& reference;
  typedef const T& const_reference;
  typedef T* pointer;
  typedef const T* const_pointer;
  typedef T* container_type;
  static reference from_container(pointer x) { return *x; }
  static const_reference from_container(const_pointer x)
                                             { return *x; }
  static pointer to_container(reference x)   { return &x; }
};

// rvector<> is similar to vector<>, but allows references
// by storing references as pointers.
template<typename T, typename A=allocator<T> >
class rvector {
  typedef typename Ref<T>::container_type container_type;
  typedef typename vector<container_type> vector_type;
public:
  typedef typename Ref<T>::value_type value_type;
  typedef typename Ref<T>::reference reference;
  typedef typename Ref<T>::const_reference const_reference;
  typedef typename vector_type::size_type size_type;
  // other typedefs are similar
  ...

  class iterator; // wraps a vector<>::iterator
  class const_iterator;

  // constructors pass arguments to v
  iterator begin()            { return iterator(v.begin()); }
  iterator end()              { return iterator(v.end()); }
  void push_back(typename Ref<T>::reference x) {
     v.push_back(Ref<T>::to_container(x));
  }
  reference at(size_type n)   {
     return Ref<T>::from_container(v.at(n));
  }
  reference front()           {
    return Ref<T>::from_container(v.front());
  }
  const_reference front() const  {
    return Ref<T>::from_container(v.front());
  }

  // other members are similar
  ...
  
private:
  vector_type v;
};
