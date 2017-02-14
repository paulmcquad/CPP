// Example 6-8: Defining member functions.
#include <cmath>
#include <iostream>
#include <istream>
#include <ostream>
using namespace std;

class point {
public:
  typedef double value_type;
  // constructors are special member functions
  explicit point(value_type x = 0.0, value_type y = 0.0);
  value_type x()       const { return x_; }
  value_type y()       const { return y_; }
  void x(value_type x)       { x_ = x; }
  void y(value_type y)       { y_ = y; }

  value_type distance() const;
  bool operator==(const point& pt) const;

  inline static point origin();
private:
  value_type x_, y_;
};

point::point(value_type x, value_type y)
: x_(x), y_(y)
{}

point::value_type point::distance()
const
{
  return sqrt(x() * x() + y() * y());
}

bool point::operator==(const point& pt)
const
{
  return x() == pt.x() && y() == pt.y();
}

inline point point::origin()
{
  return point();
}

int main(int argc, char *argv[]){
	
  point p1;
  point::value_type n;
  cin >> n;
  p1.x(n);
  cin >> n;
  p1.y(n);
  if (p1 == point::origin())
    cout << "Origin\n";
  else
    cout << p1.distance() << '\n';
}
