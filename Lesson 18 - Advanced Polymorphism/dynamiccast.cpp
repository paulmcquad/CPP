// Listing 18.2 - dynamic cast
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
     void Speak()const { cout << "Meow\n"; }
     void Purr() const { cout << "rrrrrrrrrrr\n"; }
};

class Dog: public Mammal
{
 public:
     Dog() { cout << "Dog Constructor...\n"; }
     ~Dog() { cout << "Dog destructor...\n"; }
     void Speak()const { cout << "Woof!\n"; }
};

int main(int argc, char *argv[]){

     const int NumberMammals = 3;
     Mammal* Zoo[NumberMammals];
     Mammal* pMammal;

     int choice,i;
     for (i=0; i<NumberMammals; i++)
     {
         cout << "(1)Dog (2)Cat: ";
         cin >> choice;

         if (choice == 1)
             pMammal = new Dog;
         else
             pMammal = new Cat;

         Zoo[i] = pMammal;
     }
     cout << "\n";

     for (i=0; i<NumberMammals; i++)
     {
         Zoo[i]->Speak();

         Cat *pRealCat =  dynamic_cast<Cat *> (Zoo[i]);

         if (pRealCat)
             pRealCat->Purr();
         else
             cout << "Uh oh, not a cat!\n";
 

         delete Zoo[i];
         cout << "\n";

     }
     return 0;
}