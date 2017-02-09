// Listing 9.1 Demonstrates address of operator
// and addresses of local variables
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	
     unsigned short shortVar=5;
     unsigned long  longVar=65535;
     long sVar = -65535;

     cout << "shortVar:\t" << shortVar;
     cout << "\tAddress of shortVar:\t" << &shortVar << "\n";
     cout << "longVar:\t"  << longVar;
     cout << "\tAddress of longVar:\t"  << &longVar  << "\n";
     cout << "sVar:\t\t"   << sVar;
     cout << "\tAddress of sVar:\t"     << &sVar     << "\n";

     return 0;

}