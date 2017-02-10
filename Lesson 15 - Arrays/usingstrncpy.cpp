// Listing 15.9 Using strncpy()
#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char *argv[]){
	
     const int MaxLength = 80;
     char String1[] = "No man is an island";
     char String2[MaxLength+1];

     strncpy(String2,String1,MaxLength);
     String2[strlen(String1)] = '\0'; // add a null to the end
     cout << "String1: " << String1 << endl;
     cout << "String2: " << String2 << endl;
     return 0;
 }