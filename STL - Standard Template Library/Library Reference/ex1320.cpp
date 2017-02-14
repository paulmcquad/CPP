// Example 13-20: Using a front_inserter to add numbers to a list.
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
using namespace std;

int main(int argc, char *argv[]){
	
  ifstream in("experiment.dat");
  list<int> data;
  copy(istream_iterator<int>(in),
            istream_iterator<int>(),
            front_inserter(data));
  copy(data.begin(), data.end(),
            ostream_iterator<int>(cout, "\n"));
}

