//Listing 11.1
// Creating and Using References
#include <iostream>
using namespace std;
 
int main(int argc, char *argv[]){
     
	 int  intOne;
     int &rSomeRef = intOne;

     intOne = 5;

     cout << "intOne: " << intOne << endl;
     cout << "rSomeRef: " << rSomeRef << endl;

     rSomeRef = 7;

     cout << "intOne: " << intOne << endl;
     cout << "rSomeRef: " << rSomeRef << endl;

     return 0;
}

