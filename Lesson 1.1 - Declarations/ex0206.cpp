// Example 2-6: Looking up names in a friend function.
class foo {
public:
  friend void bar1(foo& f) {
    ++y;     // OK: refers to foo::y
  }
  friend void bar2(foo& f);
private:
  static int y;
  int x;
};

void bar2(foo& f) {
  ++y;       // Error: y not in scope
}
