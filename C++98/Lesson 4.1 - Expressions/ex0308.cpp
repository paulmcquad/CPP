// Example 3-8: Using the & operator.
class demo
{
public:
  int x;
  static int y;
  int get_x() { return x; }
};

int demo::y = 10;

int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }

int main(int argc, char *argv[]){
	
  demo d;
  int demo::*p;
  int (demo::*func)();
  int *i;
  int local = 42;
  int *ptr = &local;

  p = &demo::x;
  i = &demo::y;
  func = &demo::get_x;
  d.*p = *ptr;
  *i = (d.*func)();

  int (*adder)(int, int);
  adder = &add;
  d.*p = adder(42, *i);

  return d.y;
}
