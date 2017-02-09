// Listing 4.4 - A complex, nested if tatement
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){

     // Ask for two numbers
     // Assign the numbers to bigNumber and littleNumber
     // If bigNumber is bigger than littleNumber,
     // see if they are evenly divisible
     // If they are, see if they are the same number

     int firstNumber, secondNumber;

     cout << "Enter two numbers.\nFirst: ";
     cin >> firstNumber;
     cout << "\nSecond: ";
     cin >> secondNumber;
     cout << "\n\n";

	 
     if (firstNumber >= secondNumber)
     {
         if ( (firstNumber % secondNumber) == 0) // evenly divisible?
         {
             if (firstNumber == secondNumber)

                 cout << "They are the same!\n";
             else
                 cout << "They are evenly divisible!\n";
         }
         else
             cout << "They are not evenly divisible!\n";
     }

     else
         cout << "Hey! The second one is larger!\n";
     return 0;

 }