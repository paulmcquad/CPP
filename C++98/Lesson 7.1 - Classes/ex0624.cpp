// Example 6-24: Adjusting accessibility with using declarations.
struct base { // struct is public by default
  int x;
protected:
  int y;
};
// private inheritance makes x and y private in derived1
class derived1 : private base {
public:
  using base::x; // x is now public
};
// public inheritance menas x is public and y is protected
// in derived2
class derived2 : public base {
public:
  using base::y; // y is now public
private:
  using base::x; // pointless: x is still public
};

int main(int argc, char *argv[]){
	
  base b;
  derived1 d1;
  derived2 d2;
  b.x = 0;       // OK: x is public in base
  b.y = 42;      // Error: y is protected in base
  d1.x = b.x;    // OK: x is public in derived1
  d2.x = d1.x;   // OK: x is public in derived2
  d1.y = 42;     // Error: y is private in derived1
  d2.y = b.x;    // OK: y is public in derived2
  return d2.y;
}
