// Example 5-17: Calling overloaded operators
class demo
{
public:
  demo(int v) : value_(v) {}

  demo add(const demo& d) const;
  demo sub(const demo& d) const;
  demo mul(const demo& d) const;
  demo operator+(const demo& d) const;
  demo operator-(const demo& d) const;
  demo operator*(const demo& d) const;
  operator int() const { return value_; }
private:
  int value_;
};

// Silly examples, but illustrative.
demo add(const demo& a) { return a; }
demo mul(const demo& a) { return a; }
demo div(const demo& a) { return a; }

demo operator+(const demo& a, const demo& b)
{
  return a.operator+(b); // force use of member function
}

demo operator*(const demo& a, const demo& b)
{
  return a.operator*(b);
}

demo demo::add(const demo& d)
const
{
  return *this + d; // Error: calls ::operator+() or
                    //   demo::operator+()?
}

demo demo::sub(const demo& d) const
{
  return this->operator-(d); // member operator
}

demo demo::mul(const demo& d) const
{
   return ::operator*(*this, d); // global operator
}

demo demo::operator+(const demo& d) const
{
  return demo(int(*this) + int(d));
}

demo demo::operator-(const demo& d) const
{
  return sub(d); // calls demo::sub (recurses infinitely)
}

demo demo::operator*(const demo& d) const
{
  return ::mul(d); // scope operator to call global mul()
}
