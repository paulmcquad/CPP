// Listing 5.5 - demonstrates multiple return
// statements
#include <iostream>
using namespace std;

int Doubler(int AmountToDouble);

int main(int argc, char *argv[]){
	
     int result = 0;
     int input;

     cout << "Enter a number between 0 and "
               << "10,000 to double: ";
     cin >> input;

     cout << "\nBefore doubler is called...";
     cout << "\ninput: " << input
               << " doubled: " << result << "\n";

     result = Doubler(input);

     cout << "\nBack from Doubler...";
     cout << "\ninput: " << input
               << " doubled: " << result << "\n\n";

     return 0;
}

 int Doubler(int original) {
     if (original <= 10000)
         return original * 2;
     else
         return -1;
     cout << "You can't get here!\n";
}