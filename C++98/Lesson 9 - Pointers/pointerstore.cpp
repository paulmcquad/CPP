// Listing 9.3 What is stored in a pointer.
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	

     unsigned short int myAge = 5, yourAge = 10;
     unsigned short int * pAge = &myAge;  // a pointer

     cout << "myAge:\t" << myAge;
     cout << "\t\tyourAge:\t" << yourAge << "\n";
     cout << "&myAge:\t" << &myAge;
     cout << "\t&yourAge:\t" << &yourAge <<"\n";

     cout << "pAge:\t" << pAge << "\n";
     cout << "*pAge:\t" << *pAge << "\n\n";

     pAge = &yourAge;       // reassign the pointer

     cout << "myAge:\t" << myAge;
     cout << "\t\tyourAge:\t" << yourAge << "\n";
     cout << "&myAge:\t" << &myAge;
     cout << "\t&yourAge:\t" << &yourAge <<"\n";

     cout << "pAge:\t" << pAge << "\n";
     cout << "*pAge:\t" << *pAge << "\n\n";
     cout << "&pAge:\t" << &pAge << "\n";

     return 0;

}

