//Listing 6.11 illustrating
//empty for loop statement

#include <iostream>
using namespace std;
 
int main(int argc, char *argv[]){

     int counter=0;       // initialization
     int max;

     cout << "How many hellos?";
     cin >> max;

     for (;;)          // a for loop that doesn't end
     {
         if (counter < max){    // test
		 	 
             cout << "Hello!\n";
             counter++;          // increment

         }
         else
             break;
     }

     return 0;
}

