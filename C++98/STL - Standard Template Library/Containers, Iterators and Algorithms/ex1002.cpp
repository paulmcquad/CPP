// Example 10-2: Removing matching items from a sequence container.
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <ostream>
using namespace std;

// Erase all items from container c that are equal to item.
template<typename C>
void erase(C& c, const typename C::value_type& item)
{
  c.erase(remove(c.begin(), c.end(), item), c.end());
}

template<typename C, typename Pred>
void erase_if(C& c, Pred pred)
{
  c.erase(remove_if(c.begin(), c.end(), pred), c.end());
}

int main(int argc, char *argv[]){
	
  list<int> lst;
  
  lst.push_back(10);
  lst.push_back(20);
  lst.push_back(30);
  lst.push_back(20);
  lst.push_back(40);
  lst.push_back(10);

  // Erase all items == 20.
  erase(lst, 20);
  copy(lst.begin(), lst.end(),
    ostream_iterator<int>(cout, " "));
  cout << endl;

  // Erase all items < 20.
  erase_if(lst, bind2nd(less<int>(), 20));
  copy(lst.begin(), lst.end(),
    ostream_iterator<int>(cout, " "));
  cout << endl;
}
