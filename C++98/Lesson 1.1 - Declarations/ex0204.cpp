// Example 2-4: Using the global scope operator.
#include <iostream>
#include <ostream>
using namespace std;

int x = 42;

int main(int argc, char *argv[]){
	
  double x = 3.1415;         // hides the global x
  cout << x << '\n';    // prints 3.1415
  cout << ::x << '\n';  // prints 42
}
