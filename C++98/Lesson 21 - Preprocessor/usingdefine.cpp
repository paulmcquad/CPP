// Listing 21.1 Using #define
#define DemoVersion
#define DOS_VERSION 5
#include <iostream>
using namespace std;
 
int main(int argc, char *argv[]){
	
     cout << "Checking on the definitions of DemoVersion,"
         << "DOS_VERSION and WINDOWS_VERSION...\n";

 #ifdef DemoVersion
     cout << "DemoVersion defined.\n";
 #else // DemoVersion
     cout << "DemoVersion not defined.\n";
 #endif // DemoVersion

 #ifndef DOS_VERSION
     cout << "DOS_VERSION not defined!\n";
 #else // DOS_VERSION
     cout << "DOS_VERSION defined as: "
          << DOS_VERSION << endl;
 #endif // DOS_VERSION 

 #ifdef WINDOWS_VERSION
     cout << "WINDOWS_VERSION defined!\n";
 #else // WINDOWS_VERSION
     cout << "WINDOWS_VERSION was not defined.\n";
 #endif // WINDOWS_VERSION

     cout << "Done.\n";
     return 0;
 }