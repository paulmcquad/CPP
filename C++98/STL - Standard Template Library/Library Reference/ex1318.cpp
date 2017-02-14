// Example 13-18: Using back_inserter to add numbers to a vector.
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main(int argc, char *argv[]){
	
  ifstream in("experiment.dat");
  vector<int> data;
  copy(istream_iterator<int>(in),
            istream_iterator<int>(),
            back_inserter(data));
  copy(data.begin(), data.end(),
            ostream_iterator<int>(cout, "\n"));
}

