// Example 3-2: Demonstrating order of evaluation.
#include <iostream>
#include <ostream>
using namespace std;

int x = 1;

int f()
{
  x = 2;
  return x;
}

int g()
{
  return x;
}

int main(int argc, char *argv[]){
	
  cout << f() / g() << '\n';
}
