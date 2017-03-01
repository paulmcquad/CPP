#include <iostream>
using namespace std;


int main(int argc, char *argv[]){
	
	cout << "C++11 Tutorials" << endl;
	cout << "Episode 2: Rvalue References Part 1 - Move Semantics." << endl;
	
	// lvalues and rvalues recap!
	
	extern int x, *p arr[5], y, foo();
	
	&x; // lvalue
	&*p; // lvalue
	&arr[0]; // lvalue
	
	2; // rvalue
	x + y; // rvalue
	foo() // rvalue
	
	int& rx = x;
	const int& crx = foo();
	
	int&& rrx = foo();
		
	
	return 0;
}