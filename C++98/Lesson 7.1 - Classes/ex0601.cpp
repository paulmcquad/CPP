// Example 6-1: Defining classes.
#include <string>
using namespace std;

struct point {
  double x, y;
};

class shape {
public:
  shape();
  virtual ~shape();
  virtual void draw();
};

class circle : public shape {
public:
  circle(const point& center, double radius);
  point center() const;
  double radius() const;
  void move_to(const point& new_center);
  void resize(double new_radius);
  virtual void draw();
private:
  point center_;
  double radius_;
};

class integer {
public:
  typedef int value_type;
  int value() const;
  void set_value(int value);
  string to_string() const;
private:
  int value_;
};

class real {
public:
  typedef double value_type;
  double value() const;
  void set_value(double value);
  string to_string() const;
private:
  double value_;
};

union number {
  number(int value);
  number(double value);
  integer i;
  real    r;
};
