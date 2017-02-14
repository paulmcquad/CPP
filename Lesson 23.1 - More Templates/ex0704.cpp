// Example 7-4: Overloading functions and function templates.
#include <cctype>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>
void print(const T& x)
{
  cout << x;
}

void print(char c)
{
  if (isprint(c))
    cout << c;
  else
    cout << hex << setfill('0')
              << "'\\x" << setw(2) << int(c) << '\''
              << dec;
}

template<>
void print(const long& x)
{
  cout << x << 'L';
}

int main(int argc, char *argv[]){
	
  print(42L);    // calls print<long> specialization
  print('x');    // calls print(char) overload
  print('\0');   // calls print(char) overload
  print(42);     // calls print<int>
  print(string("y")); // calls print<string>
  print();                   // Error: argument required
  print(vector<int>()); // Error
}
