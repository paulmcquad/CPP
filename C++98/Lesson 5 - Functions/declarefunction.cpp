// Listing 5.1 - demonstrates the use of function prototypes
#include <iostream>
using namespace std;

int FindArea(int length, int width); //function prototype (declaration)

int main(int argc, char *argv[]){
	 
     int lengthOfYard;
     int widthOfYard;
     int areaOfYard;

     cout << "\nHow wide is your yard? ";
     cin >> widthOfYard;
     cout << "\nHow long is your yard? ";
     cin >> lengthOfYard;

     areaOfYard= FindArea(lengthOfYard,widthOfYard);

     cout << "\nYour yard is ";
     cout << areaOfYard;
     cout << " square feet\n\n";
     return 0;
 }

 int FindArea(int l, int w) // function definition
 {
      return l * w;
 }