// Example 6-11: Using static member functions.
class point {
public:
  point(int x, int y);

  static point origin() { return point(0, 0); }

  // Error: calls non-static function, x()
  static bool is_zero() { return x() == 0; }

  int x() const;
  int y() const;
private:
  int x_, y_;
};
