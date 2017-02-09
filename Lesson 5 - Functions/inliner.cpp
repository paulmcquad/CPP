// Listing 5.7 - demonstrates inline functions
#include <iostream>
using namespace std;

inline int Doubler(int);

int main(int argc, char *argv[]){
	
     int target;

     cout << "Enter a number to work with: ";
     cin >> target;
     cout << "\n";

     target = Doubler(target);
     cout << "Target: " << target << endl;

     target = Doubler(target);
     cout << "Target: " << target << endl;

     target = Doubler(target);
     cout << "Target: " << target << endl;
     return 0;
 }

 int Doubler(int target){
     return 2*target;
 }