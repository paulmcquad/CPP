// Example 9-9: Writing a manipulator that takes an argument.
#include <iostream>
#include <istream>
#include <ostream>
#include <string>

template<typename charT>
class skipper
{
public:
  typedef charT char_type;
  skipper(char_type delim) : delim_(delim) {}
  template<typename traits>
  void operator()(std::basic_istream<charT,traits>&) const;
private:
  char_type delim_;
};

// Skip the rest of the line. The compiler deduces the
// traits type from the stream argument.
template<typename charT>
template<typename traits>
void skipper<charT>::operator()(
  std::basic_istream<charT,traits>& stream)
const
{
  char_type c;
  while (stream.get(c) && c != delim_)
    ;
}

// Invoke the skipper manipulator.
template<typename charT, typename traits>
std::basic_istream<charT,traits>& operator>>(std::basic_istream<charT,traits>& stream,
           const skipper<charT>& f)
{
  f(stream);
  return stream;
}

// Let the compiler deduce the character type.
template<typename charT>
skipper<charT> skip(charT c)
{
  return skipper<charT>(c);
}

int main(int argc, char *argv[]){
	
  int x;
  std::string next;
  std::cout << "Enter a number, followed by anything, a newline, then a string.\n";
  std::cin >> x >> skip('\n') >> next;
  std::cout << next << '\n';
}

