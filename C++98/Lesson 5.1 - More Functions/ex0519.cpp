// Example 5-19: Resolving assignment-like initialization.
class point {
public:
  point() : x_(0), y_(0) {}
  point(int x) : x_(x), y_(0) {}
  point(int x, int y) : x_(x), y_(y) {}
  int x() const { return x_; }
  int y() const { return y_; }
private:
  int x_, y_;
};

class dot {
public:
  dot(int x, int y) : center_(point(x, y)) {}
  dot(const point& center) : center_(center) {}
  operator point() const { return center_; }
private:
  point center_;
};

point p1 = 3;    // invokes point(int) constructor
point p2 = 4.2;  // converts 4.2 to 4, and invokes point(int)
dot   d1 = p1;   // invokes dot(const point&) constructor
point p3 = d1;   // invokes dot::operator point() and
                 // implicit point(const point&) 
                 // copy constructor
