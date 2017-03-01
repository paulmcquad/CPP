#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


int main(int argc, char *argv[]){
	cout << "C++11 Tutorials" << endl;
	cout << "Episode 1: Range-based for loops" << endl;
		
	// Range-based For Loop
	vector<int> v{-1, 42, 123, 9000};
	for (int x : v){
		cout << x << endl;
	}

	// Range-based For Loop
	vector<string> strings = {"Bacon is the worlds's best meat", "Chicken", "Beef"};
	for (const string& s : strings){
		cout << s << endl;
	}
	
	// Range-based For Loop - auto
	vector<string> strings2 = {"Bacon is the worlds's best meat", "Chicken", "Beef"};
	for (const auto& s : strings2){
		cout << s << endl;
	}
	

	// Range-based For Loop - map
	map<int, string> phonebook{ make_pair(1, "James"), make_pair(2, "Kathryn"), make_pair(3, "Jonny")};
	for (const pair<int, string>& p : phonebook) {
		cout << "(" << p.first << "," << p.second << ")" << endl;	
	}
	
	// Range-based For Loop - map auto
	map<int, string> phonebook2{ make_pair(1, "James"), make_pair(2, "Kathryn"), make_pair(3, "Jonny")};
	for (const auto& p : phonebook2) {
		cout << "(" << p.first << "," << p.second << ")" << endl;	
	}
	
	return 0;
}