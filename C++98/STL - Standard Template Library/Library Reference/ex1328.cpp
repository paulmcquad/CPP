// Example 13-28: One way to modify a key in a map
#include <map>
using namespace std;

template <typename Key, typename T, typename C, typename A>
void change_key(map<Key, T, C, A>& m,
  const Key& oldkey, const Key& newkey)
{
  using map;
  typedef typename map<Key, T, C, A>::iterator map_iterator;
  map_iterator i = m.find(oldkey);
  if (i != m.end()) {
    // Save a copy of i->second because erase invalidates i.
    T tmp = i->second;
    m.erase(i);
    m[newkey] = tmp;
  }
  // Exercise for reader: What if newkey is already in m?
}
