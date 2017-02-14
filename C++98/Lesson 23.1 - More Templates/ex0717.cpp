// Example 7-17: Using type lists.
#include <iostream>
#include <ostream>
#include "typelist.h"


typedef list<bool, char, unsigned char, signed char,
             int, short, long, unsigned,
             unsigned long, unsigned short>::type int_types;
typedef list<float, double, long double>::type real_types;

int main(int argc, char *argv[]){
	
  using namespace std;
  cout << is_same_type<int,int>::value << '\n';
  cout << is_same_type<int, signed int>::value << '\n';
  cout << is_same_type<int, unsigned int>::value << '\n';
  cout << is_member<int, int_types>::value << '\n';
  cout << is_member<float, int_types>::value << '\n';
  cout << is_member<ostream, int_types>::value << '\n';
}
