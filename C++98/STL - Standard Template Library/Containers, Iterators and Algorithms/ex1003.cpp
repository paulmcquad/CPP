// Example 10-3: Determining whether a container contains an item.
#include <algorithm>
#include <deque>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <list>
#include <map>
#include <ostream>
#include <set>
#include <vector>
using namespace std;

// Need a type trait to tell us which containers are
// associative and which are not. (See Chapter 8.)
struct associative_container_tag {};
struct sequence_container_tag {};

template<typename C>
struct is_associative
{};

template<typename T, typename A>
struct is_associative<deque<T,A> >
{
  typedef sequence_container_tag tag;
};
template<typename T, typename A>
struct is_associative<list<T,A> >
{
  typedef sequence_container_tag tag;
};
template<typename T, typename A>
struct is_associative<vector<T,A> >
{
  typedef sequence_container_tag tag;
};

template<typename T, typename C, typename A>
struct is_associative<set<T,C,A> >
{
  typedef associative_container_tag tag;
};
template<typename T, typename C, typename A>
struct is_associative<multiset<T,C,A> >
{
  typedef associative_container_tag tag;
};
template<typename T, typename C, typename A>
struct is_associative<map<T,C,A> >
{
  typedef associative_container_tag tag;
};
template<typename T, typename C, typename A>
struct is_associative<multimap<T,C,A> >
{
  typedef associative_container_tag tag;
};

template<typename C, typename T>
inline bool do_contains(const C& c, const T& item,
                        associative_container_tag)
{
  return c.end() != c.find(item);
}

template<typename C, typename T>
inline bool do_contains(const C& c, const T& item,
                        sequence_container_tag)
{
  return c.end() != find(c.begin(), c.end(), item);
}

// Here is the actual contains function. It dispatches
// to do_contains, picking the appropriate overloaded
// function depending on the type of the container c.
template<typename C, typename T>
bool contains(const C& c, const T& item)
{
  return do_contains(c, item, is_associative<C>::tag());
}

int main(int argc, char *argv[]){
	
   set<int> data;
   int n;
   while (cin >> n && n != 0)
      data.insert(n);

   cout << boolalpha;
   while (cin >> n)
     cout << contains(data, n) << '\n';
}
