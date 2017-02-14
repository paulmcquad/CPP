// Example 6-3: Using an anonymous union.
#include <string>

struct node {
  enum kind { integer, real, string } kind;
  union {
    int intval;
    double realval;
    char strval[8];
  };
};

node* makeint(int i)
{
  node* rtn = new node;
  rtn->kind = node::integer;
  rtn->intval = i;
  return rtn;
}
