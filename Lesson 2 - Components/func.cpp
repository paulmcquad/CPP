#include <iostream>
using namespace std;

int Add (int x, int y){
 cout << "In Add(), received " << x << " and " << y << "\n";
 return (x+y);
}

int main(int argc, char *argv[]){

 cout << "I'm in main()!\n";
 cout << "\nCalling Add()\n";
 cout << "The value returned is: " << Add(3,4);
 cout << "\nBack in main().\n";
 cout << "\nExiting...\n\n";

 return 0;
}





