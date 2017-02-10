//Listing 11.7
// Returning multiple values from a function
#include <iostream>
using namespace std;
 
short Factor(int, int*, int*);

int main(int argc, char *argv[]){

     int number, squared, cubed;
     short error;

     cout << "Enter a number (0 - 20): ";
     cin >> number;

     error = Factor(number, &squared, &cubed);

     if (!error){

         cout << "number: " << number << "\n";
         cout << "square: " << squared << "\n";
         cout << "cubed: "  << cubed   << "\n";
     }
     else
         cout << "Error encountered!!\n";
     return 0;
}

 

short Factor(int n, int *pSquared, int *pCubed) {

     short Value = 0;
     if (n > 20)
         Value = 1;
     else
     {
         *pSquared = n*n;
         *pCubed = n*n*n;
         Value = 0;
     }
     return Value;
}

