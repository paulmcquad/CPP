// Example 13-27: Reading and writing monetary values.
#include <iostream>
#include <locale>
#include <ostream>
using namespace std;

int main(int argc, char *argv[]){
	
  ios_base::iostate err = ios_base::goodbit;
  long double value;
  locale::global(locale(""));
  cin.imbue(locale());
  cout.imbue(locale());
  cout << showbase;
  cout << "What is your hourly wage? ";
  use_facet<money_get<char> >(locale()).get(
    cin, istreambuf_iterator<char>(),
    false, cin, err, value);
  if (err)
    cerr << "Invalid input\n";
  else {
    cout << value << '\n';
    cout << "You make ";
    use_facet<money_put<char> >(locale()).put(
      cout, false, cout, cout.fill(),
      value * 40);
    cout << " in a 40-hour work week.\n";
  }
}
