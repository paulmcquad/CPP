// Example 13-11: Wrapping a member function as a function object
#include <algorithm>
#include <functional>
#include <list>
#include <string>
using namespace std;

class Employee {
public:
  int         sales()      const { return sales_; }
  string name()       const { return name_; }
  bool        gets_bonus() const { return sales() > bonus_; }
private:
  int sales_;
  string name_;
  int bonus_;
};

list<Employee*> empptrs;
// Fill empptrs with pointers to Employee objects

int main(int argc, char *argv[]){
	
  // Remove the employees who will NOT receive bonuses.
  list<Employee*>::iterator last =
    remove_if(empptrs.begin(), empptrs.end(),
        not1(mem_fun(&Employee::gets_bonus)));
}

