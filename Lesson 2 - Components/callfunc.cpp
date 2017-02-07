#include <iostream>using namespace std; 
// function Demonstrating a Call to a Function// prints out a useful message
void DemonstrationFunction(){
 cout << "In Demonstration Function\n"; }
// function main - prints out a message, then// calls DemonstrationFunction, then prints out// a second message.
int main(int argc, char *argv[]) {
 cout << "In main\n" ;
 DemonstrationFunction();
 cout << "Back in main\n";
 return 0;
}
