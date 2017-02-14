// Example 11-2: Testing functions.
#include <iostream>
#include <string>

int main(int argc, char *argv[]){
	
  using namespace std;

  string s("hello, world");

#define TEST(func) cout << #func "=" << s.func << '\n'

  TEST(erase(9, 1));
  TEST(erase(5));
  TEST(find_first_not_of("aeiou"));
}
