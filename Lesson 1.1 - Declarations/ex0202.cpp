// Example 2-2: Names in inner scopes can hide names in outer scopes.
#include <iostream>
#include <ostream>
using namespace std;

int main(int argc, char *argv[]){
	
  for (int i = 0; i < 100; ++i)
  {
    int x = 42;
    if (x < i)
    {
      double x = 3.14;
      cout << x; // prints 3.14
    }
    cout << x;   // prints 42
  }
  cout << x;     // Error: no x declared in this scope
}
