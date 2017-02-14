// Example 13-1: Using for_each to test whether a list is sorted
#include <iostream>
#include <algorithm>
#include <list>
#include <ostream>

template<typename T>
class is_sorted
{
public:
  is_sorted() : first_time(true), sorted(true) {}
  void operator()(const T& item) {
    // for_each calls operator() for each item
    if (first_time)
      first_time = false;
    else if (item < prev_item)
      sorted = false;
    prev_item = item;
  }
  operator bool() { return sorted; }
private:
  bool first_time;
  bool sorted;
  T prev_item;
};

int main(int argc, char *argv[]){

  list<int> l;
  l.push_back(10);
  l.push_back(20);
  l.push_back(30);
  l.push_back(40);
  if (for_each(l.begin(), l.end(), is_sorted<int>()))
    cout << "list is sorted" << '\n';
}
