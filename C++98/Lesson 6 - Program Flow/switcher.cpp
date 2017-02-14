//Listing 6.14
// Demonstrates switch statement

#include <iostream>
using namespace std;
 
int main(int argc, char *argv[]){

     unsigned short int number;

     cout << "Enter a number between 1 and 5: ";
     cin >> number;

     switch (number){

     case 0:

         cout << "Too small, sorry!";

         break;

     case 5:  
         cout << "Good job!\n";  // fall through
     case 4:  
         cout << "Nice Pick!\n"; // fall through
     case 3:  
         cout << "Excellent!\n"; // fall through
     case 2:  
         cout << "Masterful!\n"; // fall through
     case 1:  
         cout << "Incredible!\n";
         break;

     default: 
         cout << "Too large!\n";
         break;

     }
     cout << "\n\n";

     return 0;
}

