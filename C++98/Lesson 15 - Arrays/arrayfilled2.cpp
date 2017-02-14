//Listing 15.7 using cin.get()
#include <iostream>
using namespace std;
 
int main(int argc, char *argv[]){
	
     char buffer[80];

     cout << "Enter the string: ";
     cin.get(buffer, 79);       // get up to 79 or newline
     cout << "Here's the buffer:  " << buffer << endl;

     return 0;
} 

