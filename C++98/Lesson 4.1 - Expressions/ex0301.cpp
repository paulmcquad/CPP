// Example 3-1: Lvalues and rvalues.
class number {
public:
  number(int i = 0) : value(i) {}
  operator int() const { return value; }
  number& operator=(const number& n) {
    value = static_cast<int>(n);
    return *this;
  }
private:
  int value;
};

number operator+(const number& x, const number& y)
{
  return number(static_cast<int>(x) + static_cast<int>(y));
}

int main(int argc, char *argv[]){
	
  number a[10], b(42);
  number* p;
  a;           // lvalue
  a[0];        // lvalue
  &a[0];       // rvalue
  *a;          // lvalue
  p;           // lvalue
  *p;          // lvalue
  10;          // rvalue
  number(10);  // rvalue
  a[0] + b;    // rvalue
  b = a[0];    // lvalue
}
