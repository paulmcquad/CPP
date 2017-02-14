// Listing 6.5
// Demonstrates skipping the body of
// the while loop when the condition is false.

#include <iostream>
using namespace std;
 
int main(int argc, char *argv[]){

     int counter;

     cout << "How many hellos?: ";
     cin >> counter;

     while (counter > 0)

     {

         cout << "Hello!\n";
         counter--;

     }

     cout << "counter is OutPut: " << counter;

     return 0;

}

