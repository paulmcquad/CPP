// Example 11-1: Defining type traits with a macro.
#include <iostream>
#include <ostream>
#include "isinteger.h"

int main(int argc, char *argv[]){
	
   using cout;
   cout << is_integer<int>::value   << '\n';
   cout << is_integer<float>::value << '\n';
   cout << is_integer<bool>::value  << '\n';
   cout << is_integer<int*>::value  << '\n';
}
