// Example 7-10: Instantiating templates.
#include <iomanip>
#include <iostream>
#include <ostream>
using namespace std;

const double pi = 3.141592653589792;

// Function template
template<typename T> T sqr(T x)
{
  return x * x;
}

// Class template
template<typename T>
class circle
{
public:
  circle(T r) : radius_(r) {}
  // sqr<> is instantiated when circle<> is instantiated.
  T area() const { return pi * sqr(radius_); }
  T radius() const { return radius_; }
private:
  T radius_;
};

// Function template
template<typename T>
void print(T obj)
{
  cout << obj << '\n';
}

// Overload the function template with another template.
template<typename T>
void print(const circle<T>& c)
{
  cout << "circle(" << c.radius() << ")\n";
}

template int sqr<int>(int); // explicit instantiation

// Explicit instantiation of circle<double>, and
// implicit instantiation of sqr<double>
template class circle<double>;

// Error: after instantiation of sqr<double>,
// illegal to specialize it.
template<> double sqr(double x)
{
  return x * x;
}

int main(int argc, char *argv[]){
	

  // No circle<> instance needed yet, even to resolve
  // overloaded print function.
  print(42);
  for (int i = 0; i < 10; ++i)
    // implicit instantiation of sqr<int>
    cout << setw(2) << i << setw(4) << sqr(i) << '\n';
  // instantiation of circle<float> and therefore sqr<float>
  circle<float> unit(1.0f);
  // implicit instantiation of print<circle<float> >
  print(unit);
}
