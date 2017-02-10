// Listing 18.1 - virtual methods
#include <iostream>
using namespace std;

class Mammal
{
 public:
     Mammal():itsAge(1) { cout << "Mammal constructor...\n"; }
     virtual ~Mammal() { cout << "Mammal destructor...\n"; }
     virtual void Speak() const { cout << "Mammal speak!\n"; }
 protected:
     int itsAge;
};

class Cat: public Mammal
{
 public:
     Cat() { cout << "Cat constructor...\n"; }
     ~Cat() { cout << "Cat destructor...\n"; }
     void Speak()const { cout << "Meow!\n"; }
};

int main(int argc, char *argv[]){
	
     Mammal *pCat = new Cat;
     pCat->Speak();
     return 0;
}