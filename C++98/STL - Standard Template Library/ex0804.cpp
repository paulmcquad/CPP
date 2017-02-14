// Example 8-4: Wrapping a dynamic object.
#include <memory>

template<typename T, typename Alloc=std::allocator<T> >
class wrapper {
public:
  typedef T value_type;
  typedef typename Alloc::pointer pointer;
  typedef typename Alloc::reference reference;

  // Allocate and save a copy of obj.
  wrapper(const T& obj = T(), const Alloc& a = Alloc())
  : alloc_(a), ptr_(0)
  {
    T* p = a.allocate(sizeof(T));
    try {
      alloc_.construct(p, obj);
    } catch(...) {
      // If the construction fails, free the memory without
      // trying to finalize the (uninitialized) object.
      alloc_.deallocate(p);
      throw;
    }
    // Everything succeeded, so save the pointer.
    ptr_ = p;
  }
  ~wrapper()
  {
    alloc_.destroy(ptr_);
    alloc_.deallocate(ptr_);
  }
  typename Alloc::reference operator*() { return *ptr_; }
  value_type operator*() const          { return *ptr_; }
private:
  Alloc alloc_;
  typename Alloc::pointer ptr_;
};
