// Listing 4.5 - Demonstrates why braces
// help clarify which else statement goes with which if statement
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	
     int x;
     cout << "Enter a number less than 10 or greater than 100: ";
     cin >> x;
     cout << "\n";

     if (x > 10)
         if (x > 100)
             cout << "More than 100, Thanks!\n";
     else                            // not the else intended!
         cout << "Less than 10, Thanks!\n";

     return 0;
 }