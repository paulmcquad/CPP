// Listing 15.8 - Using strcpy()
#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, char *argv[]){
	
     char String1[] = "No man is an island";
     char String2[80];

     strcpy(String2,String1);

     cout << "String1: " << String1 << endl;
     cout << "String2: " << String2 << endl;

    return 0;
} 

