// Example 13-4: Generating permutations
#include <algorithm>
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <vector>
using namespace std;

void print(const vector<int>& v)
{
  copy(v.begin(), v.end(),
            ostream_iterator<int>(cout, " "));
  cout << '\n';
}

int main(int argc, char *argv[]){

  cout << "Enter a few integers, followed by EOF:";
  istream_iterator<int> start(cin);
  istream_iterator<int> end;
  vector<int> v(start, end);

  // Start with the first permutation (ascending order).
  sort(v.begin(), v.end());
  print(v);

  // Print all the subsequent permutations.
  while (next_permutation(v.begin(), v.end()))
    print(v);
}
