// Example 13-38: Storing type information.
#include <algorithm>
#include <functional>
#include <iostream>
#include <ostream>
#include <set>
#include <typeinfo>
using namespace std;

typedef bool (*type_info_compare)
  (const type_info*, const type_info*);

typedef set<const type_info*, type_info_compare>
  typeset;

// Return true if *a comes before *b. (Comparison function
// to store type_info pointers in an associative container.)
bool type_info_less(const type_info* a,
                    const type_info* b)
{
  return a->before(*b);
}

// Print a type_info name on a line.
void print(const type_info* x)
{
  cout << x->name() << '\n';
}

void demo()
{
  // Construct and initialize the set.
  typeset types(&type_info_less);

  types.insert(&typeid(int));
  types.insert(&typeid(char));
  types.insert(&typeid(type_info));
  types.insert(&typeid(bad_alloc));
  types.insert(&typeid(exception));

  // Print the types in the set.
  for_each(types.begin(), types.end(), print);
}
