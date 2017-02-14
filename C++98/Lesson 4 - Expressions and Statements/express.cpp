#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	
     int a=0, b=0, x=0, y=35;
     cout << "before a: " << a << " b: " << b;
     cout << " x: " << x << " y: " << y << endl;
     a = 9;
     b = 7;
     y = x = a+b;
     cout << "after a: " << a << " b: " << b;
     cout << " x: " << x << " y: " << y << endl;
     return 0;
 }