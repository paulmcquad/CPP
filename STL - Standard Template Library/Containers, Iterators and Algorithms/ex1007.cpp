// Example 10-7: Using a reverse iterator.
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
using namespace std;

template<typename T>
void print(const list<T>& lst)
{
  copy(lst.begin(), lst.end(),
            ostream_iterator<T>(cout, "\n"));
}

int main(int argc, char *argv[]){
	
  list<int> l;
  l.push_back(10); l.push_back(42); l.push_back(99);
  print(l);
  list<int>::reverse_iterator ri;
  ri = find(l.rbegin(), l.rend(), 42);
  l.insert(ri.base(), 33);
  // Okay: 33 inserted before 42, from the point of view
  // of a reverse iterator, that is, 33 inserted after 42.

  ri = find(l.rbegin(), l.rend(), 42);
  l.erase(ri.base());
  // Oops! Item 33 is deleted, not item 42.

  ri = find(l.rbegin(), l.rend(), 42);
  l.erase((++ri).base());
  // That's right! In order to delete the item ri points to,
  // you must advance ri first, then delete the item.
}
