// Example 6-20: Using multiple inheritance.
struct base1 {
  int n;
};
struct base2 {
  enum color { black, red };
  int n;
};
struct base3 : base2 {
  int n; // hides base2::n
};
struct derived : base1, base2, base3 {
  color get_color(); // OK: unambiguous use of base2::color
  int get_n()  { return n; } // Error: ambiguous
  int get_n1() { return base2::n; } // Error: which base2?
  int get_n2() { return base3::n; } // OK
  int get_n3() {        // OK: another way to get to
    base3& b3 = *this;  // a specific member n
    base2& b2 = b3;
    return b2.n;
  }
};
