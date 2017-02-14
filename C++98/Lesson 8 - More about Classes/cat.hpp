#include <iostream>using namespace std;class Cat{
 public:     Cat (int initialAge);     ~Cat();
     int GetAge() { return itsAge;}             // inline!     void SetAge (int age) { itsAge = age;}     // inline!     void Meow() { cout << "Meow.\n";}   		// inline! private:     int itsAge;
 };