// Example 13-34: One way to modify a key in a set
#include <set>
using namespace std;

template <typename T, typename C, typename A>
void change_key(set<T, C, A>& s,
  const T& oldkey, const T& newkey)
{
  using ::set;
  typedef typename set<T, C, A>::iterator set_iterator;
  set_iterator i = s.find(oldkey);
  if (i != s.end()) {
    s.erase(i);
    s.insert(newkey);
  }
  // Exercise for reader: What if newkey is already in s?
}
