// Example 2-7: Declaring friend member functions.
class test {
public:
  typedef int T1;
  typedef float T2;
  void f(T1);
  void f(T2);
};
class other {
  typedef char T2;
  friend void test::f(T1); // look up f and T1 in test
  friend void test::f(T2); // look up f and T2 in test before
                           // looking it up in other
};
