// Example 5-14: Avoiding ambiguous base class overloads.
struct base1 {
  void func(int);
};
struct base2 {
  void func(double);
};
struct derived : base1, base2 {
  // Error: call to overloaded func is ambiguous.
  void demo1(long x) { func(x); }
  // Qualify the name to resolve ambiguity
  void demo2(long x) { base2::func(x); }
};
