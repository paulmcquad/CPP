// Example 13-8: Finding the maximum value of any number of arguments.
#include <cassert>
#include <cstdarg>

// Use a trivial wrapper class to ensure va_end is called.
class varargs {
public:
  ~varargs() { va_end(ap); }
  va_list ap;
};

template <typename T>
T max(unsigned count, ...)
{
  assert(count > 0);
  varargs va;
  va_start(va.ap, count);
  T result = va_arg(va.ap, T);  // get first argument
  while (--count > 0) {
    T arg = va_arg(va.ap, T);   // get successive arguments
    if (arg > result)
      result = arg;             // remember the largest
  }
  return result;
}

int main(int argc, char *argv[]){
	
  int a, b, c, d;
  
  a = -42;
  b = 12;
  c = 10;
  d = 24;
  
  int x = max<int>(4, a, b, c, d);
  int y = max<int>(2, x, 42);
  return y;
}
