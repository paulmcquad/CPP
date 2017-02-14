// Example 13-21: Copying files using streambuf iterators.
#include <fstream>
#include <iterator>
using namespace std;

void copyfile(const char* from, const char* to)
{
  ifstream in(from);
  ofstream out(to);

  copy(istreambuf_iterator<char>(in),
            istreambuf_iterator<char>(),
            ostreambuf_iterator<char>(out));
}
