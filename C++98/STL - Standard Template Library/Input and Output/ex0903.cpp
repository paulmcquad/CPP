// Example 9-3: Copying streams one character at a time.
#include <istream>
#include <ostream>

template<typename charT, typename traits>
void copy(std::basic_ostream<charT, traits>& out,
          std::basic_istream<charT, traits>& in)
{
  charT c;
  while (in.get(c))
    out.put(c);
}
