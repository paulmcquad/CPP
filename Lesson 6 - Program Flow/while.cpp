// Listing 6.1
// Looping with while

#include <iostream>
using namespace std;
 
int main(int argc, char *argv[]){
	
     int counter = 0;            // initialize the condition

     while(counter < 5)          // test condition still true
     {
         counter++;              // body of the loop
         cout << "counter: " << counter << "\n";
     }

     cout << "Complete. counter: " << counter << ".\n";

     return 0;

}

