//Listing 20.1 static data members
#include <iostream>
using namespace std; 

class Cat
{
 public:
     Cat(int age = 1):itsAge(age){HowManyCats++; }
     virtual ~Cat() { HowManyCats--; }
     virtual int GetAge() { return itsAge; }
     virtual void SetAge(int age) { itsAge = age; }
     static int HowManyCats;

 private:
     int itsAge;
};

int Cat::HowManyCats = 0;

int main(int argc, char *argv[]){

     const int MaxCats = 5;
     Cat *CatHouse[MaxCats];

     int i;
     for (i = 0; i<MaxCats; i++)
         CatHouse[i] = new Cat(i);

     for (i = 0; i<MaxCats; i++)
     {

         cout << "There are ";
         cout << Cat::HowManyCats;
         cout << " cats left!\n";

         cout << "Deleting the one which is ";
         cout << CatHouse[i]->GetAge();
         cout << " years old\n";

         delete CatHouse[i];
         CatHouse[i] = 0;
     }
     return 0;
}