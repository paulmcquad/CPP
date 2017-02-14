//Listing 6.13
//Illustrates nested for loops
#include <iostream>
using namespace std;
 
int main(int argc, char *argv[]){
	
     int rows, columns;
     char theChar;

     cout << "How many rows? ";
     cin >> rows;

     cout << "How many columns? ";
     cin >> columns;

     cout << "What character? ";
     cin >> theChar;

     for (int i = 0; i<rows; i++) {
         for (int j = 0; j < columns; j++)
             cout << theChar;
         cout << "\n";
     }
	 return 0;
 }

