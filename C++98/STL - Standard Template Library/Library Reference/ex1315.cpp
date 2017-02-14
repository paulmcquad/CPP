// Example 13-15: Ensuring proper initialization of standard I/O streams
#include <ios>
#include <iostream>

class myclass {
public:
  myclass() {
    if (! okay())
      cerr << "Oops: not okay!\n";
  }
private:
  bool okay() { return false; }
};
static ios_base::Init init;
static myclass myobject;

int main(int argc, char *argv[]){
}