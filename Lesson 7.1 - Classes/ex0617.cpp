// Example 6-17: Using covariant return types.
struct point { double x, y; };

struct shape {
  virtual shape* clone() = 0;
};
struct circle : shape {
  virtual circle* clone() {
    return new circle(*this);
  }
  double radius() const { return radius_; }
  void radius(double r) { radius_ = r; }
private:
  double radius_;
  point center_;
};
struct square : shape {
  virtual square* clone() {
    return new square(*this);
  }
private:
  double size_;
  point corners_[4];
};

circle unit_circle;

circle* big_circle(double r)
{
  circle* result = unit_circle.clone();
  result->radius(r);
  return result;
}

int main(int argc, char *argv[]){
	
  shape* s = big_circle(42.0);
  shape* t = s->clone();
  delete t;
  delete s;
}
