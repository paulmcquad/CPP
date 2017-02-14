// Listing 4.2 - Demonstrates 
// prefix and postfix and increment and
// decrement operators
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){

     int myAge = 39;      // initialize two integers
     int yourAge = 39;

     cout << "I am:\t\t" << myAge << "\tyears old.\n";
     cout << "You are:\t" << yourAge << "\tyears old\n";

     myAge++;         // postfix increment
     ++yourAge;       // prefix increment

     cout << "One year passes...\n";
     cout << "I am:\t\t" << myAge << "\tyears old.\n";
     cout << "You are:\t" << yourAge << "\tyears old\n";
     cout << "Another year passes\n";
     cout << "I am:\t\t" << myAge++ << "\tyears old.\n";
     cout << "You are:\t" << ++yourAge << "\tyears old\n";
     cout << "Let's print it again.\n";
     cout << "I am:\t\t" << myAge << "\tyears old.\n";
     cout << "You are:\t" << yourAge << "\tyears old\n";

     return 0;
 }

