// Example 2-12: Returning results in function arguments.
#include <cstdlib>
#include <iostream>
#include <ostream>
using namespace std;

void divide(long num, long den, long& quo, long& rem)
{
  const ldiv_t& result = ldiv(num, den);
  quo = result.quot;
  rem = result.rem;
}

int main(int argc, char *argv[]){
	
  long q, r;
  divide(42, 5, q, r);
  cout << q << " remainder " << r << '\n';
}
