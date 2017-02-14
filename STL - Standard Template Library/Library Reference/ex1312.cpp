// Example 13-12: Wrapping a member function as a function object
#include <algorithm>
#include <functional>
#include <list>
#include <string>

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

list<Employee> emps;
// Fill emps with Employee objects

int main(int argc, char *argv[]){
	
  // Erase the employees who will NOT receive bonuses.
  // The call to remove_if rearranges emps; the call to
  // erase removes the unlucky employees from the list.
  emps.erase(
    remove_if(emps.begin(), emps.end(),
         not1(mem_fun_ref(&Employee::gets_bonus))),
    emps.end());
}

