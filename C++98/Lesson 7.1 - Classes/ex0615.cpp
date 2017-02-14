// Example 6-15: Implicit member functions.
// These classes show explicitly what the implicit
// member functions would be.
class base {
public:
  base() {}
  base(const base& that) : m1_(that.m1_), m2_(that.m2_) {}
  base& operator=(const base& that) {
    this->m1_ = that.m1_;
    this->m2_ = that.m2_;
   return *this;
  }
  ~base() {}
private:
  int m1_;
  char* m2_;
};

class demo {
public:
  demo() {}           // default constructs 3 base objects
  demo(demo& d) {}    // copies 3 base objects in ary_[]
  demo& operator=(const demo& that) {
    this->ary_[0] = that.ary_[0];
    this->ary_[1] = that.ary_[1];
    this->ary_[2] = that.ary_[2];
    return *this;
  }
  ~demo() {}          // default destructs 3 base objects
private:
  base ary_[3];
};

class derived : public base {
public:
  derived() : base() {}                  // constructs m3_[]
  derived(derived& that) : base(that) {} // copies m3_[]
  derived& operator=(const derived& that) {
    static_cast<base&>(*this) =
      static_cast<const base&>(that);
    this->m3_[0] = that.m3_[0];
    this->m3_[1] = that.m3_[1];
    this->m3_[2] = that.m3_[2];
    return *this;
  }
  ~derived() {} // calls ~base(), destructs 3 demo objects
private:
  demo m3_[3];
};
