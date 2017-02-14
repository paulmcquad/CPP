 // Listing 9.2 Using pointers
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	
     int myAge;         // a variable
     int * pAge = NULL;    // a pointer

     myAge = 5;
     pAge = &myAge;     // assign address of myAge to pAge
     cout << "myAge: " << myAge << "\n";
     cout << "*pAge: " << *pAge << "\n\n";

     cout << "*pAge = 7\n";
     *pAge = 7;         // sets myAge to 7
     cout << "*pAge: " << *pAge << "\n";
     cout << "myAge: " << myAge << "\n\n";

     cout << "myAge = 9\n";
     myAge = 9;
     cout << "myAge: " << myAge << "\n";
     cout << "*pAge: " << *pAge << "\n";

     return 0;
 }