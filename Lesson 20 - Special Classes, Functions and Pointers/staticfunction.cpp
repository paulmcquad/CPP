//Listing 20.2 static data members
#include <iostream>
using namespace std;
 
class Cat
{
 public:
     Cat(int age = 1):itsAge(age){HowManyCats++; }
     virtual ~Cat() { HowManyCats--; }
     virtual int GetAge() { return itsAge; }
     virtual void SetAge(int age) { itsAge = age; }
     static int GetHowMany() { return HowManyCats; }

 private:
     int itsAge;
     static int HowManyCats;

};

int Cat::HowManyCats = 0;
void TelepathicFunction();

int main(int argc, char *argv[]){
	
     const int MaxCats = 5;
     Cat *CatHouse[MaxCats];

     int i;
     for (i = 0; i<MaxCats; i++)
     {
         CatHouse[i] = new Cat(i);
         TelepathicFunction();
     }

     for ( i = 0; i<MaxCats; i++)
     {
         delete CatHouse[i];
         TelepathicFunction();
     }

     return 0;
}

void TelepathicFunction(){

     cout << "There are " << Cat::GetHowMany()
         << " cats alive!\n";
}