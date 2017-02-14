// Example 13-35: Converting a value to a string.
#include <ostream>
#include <sstream>
#include <string>
using namespace std;

template<typename T>
string tostring(const T& x)
{
  ostringstream out;
  out << x;
  return out.str();
}
