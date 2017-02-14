// Example 13-25: Using locales for input and output.
#include <fstream>
#include <iostream>
#include <iterator>
#include <locale>
#include <ostream>
using namespace std;

// Open a file and read floating point numbers from it,
// computing the mean. Return the mean or 0 if the file
// contains no data. The data are in the classic format,
// that is, the same format used by C++.
double mean(const char* filename)
{
  ifstream in(filename);
  // Force the data file to be interpreted in the classic
  // locale, so the same data file can be used everywhere.
  in.imbue(locale::classic());
  double sum = 0;
  unsigned long count = 0;
  istream_iterator<double> iter(in), end;
  for ( ; iter != end; ++iter) {
    ++count;
    sum += *iter;
  }
  return count == 0 ? 0.0 : sum / count;
}

int main(int argc, char *argv[]){
	
  // Print results in the user?s native locale.
  cout.imbue(locale(""));
  cout << mean("data.txt") << '\n';
}
