#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


int main(int argc, char *argv[]){
	cout << "C++11 Tutorials" << endl;
	cout << "Episode 1.2: More Range-based for loops" << endl;
		
	vector<int> v = {0, 1, 2, 3, 4, 5};
 
    for (const int& i : v) // access by const reference
        cout << i << ' ';
    cout << '\n';
 
    for (auto i : v) // access by value, the type of i is int
        cout << i << ' ';
    cout << '\n';
 
    for (auto&& i : v) // access by reference, the type of i is int&
        cout << i << ' ';
    cout << '\n';
 
    for (int n : {0, 1, 2, 3, 4, 5}) // the initializer may be a braced-init-list
        cout << n << ' ';
    cout << '\n';
 
    int a[] = {0, 1, 2, 3, 4, 5};
    for (int n : a) // the initializer may be an array
        cout << n << ' ';
    cout << '\n';
 
    for (int n : a)  
        cout << 1 << ' '; // the loop variable need not be used
    cout << '\n';
 
	return 0;
}