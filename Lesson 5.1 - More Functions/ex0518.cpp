// Example 5-18: Calling an overloaded constructor.
class point {
public:
  point() : x_(0), y_(0) {}
  point(int x) : x_(x), y_(0) {}
  point(int x, int y): x_(x), y_(y) {}
private:
  int x_, y_;
};

point p1(42);
point p2(4, 2);
point p3(p1);
