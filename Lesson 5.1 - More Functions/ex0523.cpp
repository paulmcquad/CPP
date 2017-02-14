// Example 5-23: Resolving overloaded functions.
#include <string>

void func(double);
void func(long);
void func(int);
void func(const string&);

class Num {
public:
  Num(int i) : num_(i) {}
  operator long() const { return num_; }
private:
  int num_;
};

int main(int argc, char *argv[]){
	
  short n = 42;
  func(n);           // func(int)
  func(Num(n));      // func(long)
  func(true);        // func(int)
  func(3.1415f);     // func(double)
  func("string");    // func(string);
  string s("string");
  func(s);           // func(string);
  func(3.14159L);    // Error: ambiguous
  func(42UL);        // Error: ambiguous
  func(L"widestr");  // Error: no match
}
