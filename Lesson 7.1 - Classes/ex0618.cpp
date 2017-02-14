// Example 6-18: Pure virtual functions.
#include <cstddef>
#include <iostream>
#include <ostream>
using namespace std;

enum color { black, red, green, yellow, blue,
             magenta, cyan, white };

class graphics;

class shape {
public:
  virtual ~shape();
  virtual void draw(graphics* context)       = 0;
  virtual size_t num_sides()           const = 0;
  virtual shape* clone()               const = 0;
  virtual void debug(ostream& out)     const = 0;
};

class circle : public shape {
public:
  circle(double r) : radius_(r) {}  virtual void draw(graphics* context);
  virtual size_t num_sides()    const { return 0; }
  virtual circle* clone()       const { return new circle(radius()); }
  virtual void debug(ostream& out) const {
    shape::debug(out);
    out << "radius=" << radius_ << '\n';
  }
  double radius() const { return radius_; }
private:
  double radius_;
};

class filled_circle : public circle {
public:
  filled_circle(double r, ::color c) : circle(r), color_(c) {}
  virtual filled_circle* clone()  const {
    return new filled_circle(radius(), color());
  }
  virtual void draw(graphics* context);
  virtual void debug(ostream& out) const {
    circle::debug(out);
    out << "color=" << color_ << '\n';
  }
  ::color color() const { return color_; }
private:
  ::color color_;
};

void shape::debug(ostream& out)
const
{}
