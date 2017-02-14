// Example 13-32: Implementing new and delete with malloc and free.
#include <cstdlib>
#include <new>
using namespace std;

void* operator new(size_t size) throw(bad_alloc)
{
  void* ptr = malloc(size);
  if (ptr == 0)
    throw bad_alloc();
  return ptr;
}

void* operator new(size_t size, const nothrow_t&)
throw()
{
  return malloc(size);
}

void* operator new[](size_t size) throw(bad_alloc)
{
  return operator new(size);
}

void* operator new[](size_t size, const nothrow_t&)
throw()
{
  return operator new(size, nothrow);
}

void operator delete(void* ptr) throw()
{
  free(ptr);
}

void operator delete(void* ptr, const nothrow_t&)
throw()
{
  free(ptr);
}

void operator delete[](void* ptr) throw()
{
  operator delete(ptr);
}

void operator delete[](void* ptr, const nothrow_t&)
throw()
{
  operator delete(ptr);
}
