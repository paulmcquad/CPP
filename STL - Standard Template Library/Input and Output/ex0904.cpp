// Example 9-4: Copying streams with explicit buffers.
#include <istream>
#include <memory>
#include <ostream>

template<typename charT, typename traits>
void copy(std::basic_ostream<charT, traits>& out,
          std::basic_istream<charT, traits>& in)
{
  const unsigned BUFFER_SIZE = 8192;
  std::auto_ptr<charT> buffer(new charT[BUFFER_SIZE]);
  while (in) {
    in.read(buffer.get(), BUFFER_SIZE);
    out.write(buffer.get(), in.gcount());
  }
}
