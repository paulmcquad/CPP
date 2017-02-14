// Example 6-23: Access levels and overloading.
class base {
public:
  void func(double);
protected:
  void func(long);
private:
  void func(int);
};

class demo : public base {
public:
  demo()   { func(42L); } // calls base::func(long)
  void f() { func(42); }  // Error: func(int) is private
};

class closed : private demo {
public:
  closed() { f(); } // OK: f() is accessible from closed
};

int main(int argc, char *argv[]){
	
  demo d;
  d.func(42L); // Error: func(long) accessibly only from
               // base and demo.
  d.func(42);  // Error: func(int) is private

  closed c;
  c.f();       // Error: private inheritance makes demo::f()
               // private in closed.
}
