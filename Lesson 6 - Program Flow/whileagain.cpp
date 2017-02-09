// Listing 6.7
// Looping with while

#include <iostream>
using namespace std;
 
int main(int argc, char *argv[]){
	
     int counter = 0;

     while(counter < 5)
     {
         counter++;
         cout << "Looping!  ";
     }

     cout << "\nCounter: " << counter << ".\n";

     return 0;
}

