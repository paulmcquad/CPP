//Listing 15.6 char array buffers
#include <iostream>
using namespace std;
 
int main(int argc, char *argv[]){

     char buffer[80];
     cout << "Enter the string: ";
     cin >> buffer;
     cout << "Here's the buffer:  " << buffer << endl;

     return 0;
}

