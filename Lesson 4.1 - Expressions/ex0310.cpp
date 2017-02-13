// Example 3-10: Comparing pointers
#include <ios>
#include <iostream>
#include <ostream>
using namespace std;

struct Demo {
  int x;
  int y;
};

union U {
  int a;
  double b;
  char c[5];
  Demo d;
};

int main(int argc, char *argv[]){
	
  Demo demo[10];
  cout << boolalpha;
  // Everything prints "true"
  cout << (&demo[0]   < &demo[2])   << '\n';
  cout << (&demo[0]   == demo)      << '\n';
  cout << (&demo[10]  > &demo[9])   << '\n';
  cout << (&demo[0].x < &demo[0].y) << '\n';

  U u;
  cout << (&u.d == static_cast<void*>(u.c)) << '\n';
  cout << (&u.a == static_cast<void*>(&u.b)) << '\n';
}
