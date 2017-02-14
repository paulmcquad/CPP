// Example 10-5: Inserting numbers in a vector.
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

int main(int argc, char *argv[]){
	
  using namespace std;

  list<double> data;
  copy(istream_iterator<double>(cin),
       istream_iterator<double>(),
       front_inserter(data));
  // use the data...
  // Write the data, one number per line.
  copy(data.begin(), data.end(),
       ostream_iterator<double>(cout, "\n"));
}

