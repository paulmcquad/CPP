// Example 5-8: Equivalent pointer types.
int first(int const array[10]); // size is ignored
int first(int const array[]);   // equivalent declaration
int first(int const *array);    // equivalent declaration
int first(int const *array)     // definition
{
  return array[0];
}

int apply(int func(int), int arg);
int apply(int func(int const), int);         // equivalent
int apply(int (*func)(int), int arg);        // equivalent
int apply(int (*func)(int const), int arg)   // definition
{
  return func(arg);
}
