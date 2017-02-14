// Example 5-12: Overloading functions.
class point {
public:
  point(int x = 0);        // overloaded constructors
  point(int x, int y);
  point(const point& pt);
  // x and y are overloaded
  int x()    const { return x_; }
  void x(int newx) { x_ = newx; }
  int y()    const { return y_; }
  void y(int newy) { y_ = newy; }
private:
  int x_, y_;
};

// add is overloaded
int    add(int, int);
int    add(int);
double add(double, double);
double add(double);
long   add(long, long);
long   add(long);

// The following declarations are not overloaded, but
// are redeclarations of the add functions
int  add(int a = 0, int b = 0);
long add(signed long, long signed);

long add(int, int); // Error: cannot overload on return type
