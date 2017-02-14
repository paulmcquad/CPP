// Example 10-4: Copying streams with streambuf iterators.
#include <algorithm>
#include <istream>
#include <iterator>
#include <ostream>

template<typename charT, typename traits>
void copy(std::basic_ostream<charT,traits>& out,
          std::basic_istream<charT,traits>& in)
{
  std::copy(std::istreambuf_iterator<charT>(in),
            std::istreambuf_iterator<charT>(),
            std::ostreambuf_iterator<charT>(out));
}
