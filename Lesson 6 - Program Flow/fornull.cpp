// Listing 6.10
// For loops with null statements

#include <iostream>
using namespace std;
 
int main(int argc, char *argv[]){

     int counter = 0;

     for( ; counter < 5; ) {

         counter++;
         cout << "Looping!  ";
     }

     cout << "\nCounter: " << counter << ".\n";
     return 0;
}

