// Example 9-2: Reading a number from a fixed-width field.
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>

template<typename T, typename charT, typename traits>
std::basic_istream<charT, traits>&
  fixedread(std::basic_istream<charT, traits>& in, T& x)
{
  if (in.width() == 0)
    // Not fixed size, so read normally.
    in >> x;
  else {
    std::string field;
    in >> field;
    std::basic_istringstream<charT, traits> stream(field);
    if (! (stream >> x))
      in.setstate(std::ios_base::failbit);
  }
  return in;
}

int main(int argc, char *argv[]){
	
   // Read integers in three-digit chunks.
   do {
      int i;
      std::cin.width(3);
      if (fixedread(std::cin, i))
         std::cout << i << '\n';
   } while(std::cin);
}
