// Listing 6.6
// Demonstrates do while

#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	
     int counter;

     cout << "How many hellos? ";
     cin >> counter;

    do{
         cout << "Hello\n";
         counter--;

     } while (counter > 0);

     cout << "counter is: " << counter << endl;

     return 0;
}

