// Example 5-9: Using typedef in equivalent parameter types.
#include <iostream>
#include <ostream>
using namespace std;

typedef int INT;
typedef int const CINT;
void func(int);
void func(INT);          // equivalent
void func(INT const);    // equivalent
void func(CINT);         // equivalent
void func(signed int i)  // definition
{
  cout << i;
}

int main(int argc, char *argv[]){

  func(42);
}
