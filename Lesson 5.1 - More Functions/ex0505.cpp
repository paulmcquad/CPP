// Example 5-5: Using qualifiers with member functions.
#include <cmath>
using namespace std;

class point
{
public:
  point(int x, int y) : x_(x), y_(y) {}
  int x()      const   { return x_; }
  int y()      const   { return y_; }
  double abs() const   { return sqrt(static_cast<double>(x()*x() + y()*y())); }
  void offset(const point& p) {
    // Cannot be const because offset() modifies x_ and y_.
    x_ += p.x();
    y_ += p.y();
  }
private:
  int x_, y_;
};
