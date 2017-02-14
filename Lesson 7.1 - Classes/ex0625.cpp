// Example 6-25: Accessing a protected member.
class base {
protected:
  int m;
};

struct derived : base {
  void reset() {
    this->m = 0;  // OK
  }
  void set(base* b) {
    b->m = 0;     // Error: cannot refer to m through base
  }
  bool operator==(const derived& d) {
    return this->m == d.m; // OK
  }
};
