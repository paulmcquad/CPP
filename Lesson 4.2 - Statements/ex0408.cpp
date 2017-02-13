// Example 4-8: Using continue in a loop.
#include <cmath>
#include <iostream>
#include <istream>
#include <limits>
#include <ostream>
using namespace std;

int main(int argc, char *argv[]){
	
  while(true) {
    cout << "Enter a number: ";
    double x;
    cin >> x;
    if (cin.eof() || cin.bad())
      // Input error: exit.
      break;
    else if (cin.fail()) {
      // Invalid input: skip the rest of the line.
      cin.clear();
      cin.ignore(numeric_limits<int>::max(), '\n');
      continue;
    }
    cout << "sqrt(" << x << ")=" << sqrt(x) << endl;
  }
}
