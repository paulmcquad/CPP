// Example 3-5: Using reinterpret_cast<>.
#include <cassert>
#include <iomanip>
#include <iostream>
#include <ostream>

int foo()
{
  return 0;
}

int main(int argc, char *argv[]){
	
  using namespace std;
  float pi = 3.1415926535897;
  int   ipi;

  // Print numbers in pretty hexadecimal.
  cout << setfill('0') << showbase << hex << internal;

  // Show the representation of a floating point number.
  assert(sizeof(int) == sizeof(float));
  ipi = reinterpret_cast<int&>(pi);
  cout << "pi bits=" << setw(10) << ipi << '\n';

  // Show the address of foo().
  cout << "&foo=" << setw(10) <<
    reinterpret_cast<int>(&foo) << '\n';
}
