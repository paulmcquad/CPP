//Listing 15.1 - Arrays
#include <iostream>
using namespace std; 

int main(int argc, char *argv[]){

     int myArray[5];

     for (int i=0; i<5; i++)  // 0-4
     {
         cout << "Value for myArray[" << i << "]: ";
         cin >> myArray[i];
     }

     for (int i = 0; i<5; i++)
         cout << i << ": " << myArray[i] << "\n";

     return 0;
}

