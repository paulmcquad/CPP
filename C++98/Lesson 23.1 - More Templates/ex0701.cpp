// Example 7-1: Declaring and using templates.
#include <cmath>
#include <complex>
#include <iostream>
#include <ostream>
using namespace std;

// Template declaration of point.
template<typename T>
class point {
public:
  typedef T value_type;
  point(const T& x, const T& y) : x_(x), y_(y) {}
  point() : x_(T()), y_(T()) {}
  T x()            const { return x_; }
  T& x()                 { return x_; }
  void x(const T& new_x) { x_ = new_x; }
  T y()            const { return y_; }
  T& y()                 { return y_; }
  void y(const T& new_y) { y_ = new_y; }
private:
  T x_, y_;
};

// instantiate point<>
typedef point<complex<double> > strange;
strange s(complex<double>(1, 2),
          complex<double>(3, 4));

// Specialize point<int> to use call-by-value instead
// of const references.
template<>
class point<int> {
public:
  typedef int value_type;
  point(int x, int y) : x_(x), y_(y) {}
  point() : x_(0), y_(0) {}
  int x()     const { return x_; }
  int& x()          { return x_; }
  void x(int new_x) { x_ = new_x; }
  int y()     const { return y_; }
  int& y()          { return y_; }
  void y(int new_y) { y_ = new_y; }
private:
  int x_, y_;
};

// Instance of the specialized point<int>.
point<int> p1(42, 0);
// Instance of the general point<>, using long as
// the template argument.
point<long> p2(42, 0);

// function template
template<typename T>
T abs(T x)
{
  return x < 0 ? -x : x;
}

namespace {
  // Explicit instantiation.
  const int abs_char_min1 = abs<int>(CHAR_MIN);
  // Implicit instantiation.
  const int abs_char_min2 = abs(CHAR_MIN);
}

// Overload abs() with another function template.
template<typename floatT, typename T>
floatT abs(const point<T>& p)
{
  return sqrt(static_cast<floatT>(p.x()*p.x() +
                                       p.y()*p.y()));
}

int main(int argc, char *argv[]){

  point<double> p;
  // Call instance of function template. Compiler deduces
  // second template argument (double) from the type of p.
  double x = abs<long double>(p);
  cout << x << '\n'; // prints 0
  cout << abs_char_min1 << '\n';
}
