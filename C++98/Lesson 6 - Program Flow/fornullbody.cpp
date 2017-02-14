//Listing 6.12
//Demonstrates null statement
// as body of for loop

#include <iostream>
using namespace std;
 
int main(int argc, char *argv[]){

     for (int i = 0; i<5; cout << "i: " << i++ << endl)
         ;

     return 0;
}

