//Listing 11.3
//Reassigning a reference
#include <iostream>
using namespace std; // use  objects in this file

int main(int argc, char *argv[]){

     int  intOne;
     int &rSomeRef = intOne;

     intOne = 5;

     cout << "intOne:\t\t" << intOne << endl;
     cout << "rSomeRef:\t" << rSomeRef << endl;
     cout << "&intOne:\t"  << &intOne << endl;
     cout << "&rSomeRef:\t" << &rSomeRef << endl;

     int intTwo = 8;

     rSomeRef = intTwo;  // not what you think!

     cout << "\nintOne:\t\t" << intOne << endl;
     cout << "intTwo:\t\t" << intTwo << endl;
     cout << "rSomeRef:\t" << rSomeRef << endl;
     cout << "&intOne:\t"  << &intOne << endl;
     cout << "&intTwo:\t"  << &intTwo << endl;
     cout << "&rSomeRef:\t" << &rSomeRef << endl;

     return 0;
}

