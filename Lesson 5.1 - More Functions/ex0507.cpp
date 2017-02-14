// Example 5-7: Declaring and defining functions.
// Three declarations of the same function type
int add(const int a, const int b);
int add(int x, volatile int);
int add(signed int, int signed);

// Definition of the function. The parameter qualifiers
// in the declarations are irrelevant. Only those in the
// definition matter.
int add(int x, int y)
{
  return x + y;
}
