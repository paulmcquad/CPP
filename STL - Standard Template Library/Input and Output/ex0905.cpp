// Example 9-5: Copying streams via stream buffers.
#include <istream>
#include <ostream>

template<typename charT, typename traits>
void copy(std::basic_ostream<charT, traits>& out,
          std::basic_istream<charT, traits>& in)
{
  out << in.rdbuf();
}
