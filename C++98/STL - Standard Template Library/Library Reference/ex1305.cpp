// Example 13-5: Computing a logarithm to any base.
#include <cerrno>
#include <cmath>

// Return the logarithm of x to the base n.
template<typename T>
T logn(T x, T n)
{
  errno = 0;
  T logx = log(x);
  if (errno == ERANGE)
    return logx;    // should be HUGE_VAL
  else if (errno != 0)
    return logx;    // implementation defined
  T logn = log(n);
  if (errno == ERANGE)
    return logn;    // should be HUGE_VAL
  else if (errno != 0)
    return logn;    // implementation defined
  if (logn == 0) {
    errno = EDOM;
    return 0;
  }
  return logx / logn;
}
