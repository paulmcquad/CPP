// Example 5-3: Accumulating default arguments.
void func(int x, int y);
void func(int x, int y = 10);
void func(int x = 20, int y);
void other()
{
  func(); // same as func(20, 10)
}
