// Listing 6.4
// Demonstrates a while true loop

#include <iostream>
using namespace std;
 
int main(int argc, char *argv[]){

     int counter = 0;

     while (1) {

         counter++;
         if (counter > 10)

             break;

     }

     cout << "counter: " << counter << "\n";

     return 0;
}

