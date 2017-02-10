//Listing 16.7 Calling base method from overridden method.
#include <iostream>
using namespace std;
 
class Mammal
{

 public:

     void Move() const { cout << "Mammal move one step\n"; }
     void Move(int distance) const 
         { cout << "Mammal move " 
               << distance << " steps.\n"; }

 protected:
     int itsAge;
     int itsWeight;

};

class Dog : public Mammal
 {

 public:
     void Move()const;
};

void Dog::Move() const
 {
     cout << "In dog move...\n";
     Mammal::Move(3);
}

int main(int argc, char *argv[]){

     Mammal bigAnimal;

     Dog fido;

     bigAnimal.Move(2);

     fido.Mammal::Move(6);

     return 0;
}