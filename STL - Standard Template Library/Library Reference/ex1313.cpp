// Example 13-13: Wrapping the pow function in a function object.
#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>
using namespace std;

double power(double x, double y)
{
  return pow(x, y);
}

int main(int argc, char *argv[]){
	
  vector<long double> a, b, c;

  a.push_back(2.0);
  a.push_back(3.0);
  b.push_back(4.0);
  b.push_back(2.0);
  c.resize(2);
  transform(a.begin(), a.end(), b.begin(), c.begin(),
                 ptr_fun(power));
  copy(c.begin(), c.end(),
            ostream_iterator<long double>(cout, "\n"));
}

