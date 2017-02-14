// Example 9-10: Handling serious I/O errors.
#include <algorithm>
#include <cstddef>
#include <exception>
#include <iostream>
#include <map>
#include <string>
#include <utility>

void print(const std::pair<std::string, std::size_t>& count)
{
  std::cout << count.first << '\t' << count.second << '\n';
}

int main(int argc, char *argv[]){
	
  using namespace std;

  try {
    string word;
    map<string, size_t> counts;
    cin.exceptions(ios_base::badbit);
    cout.exceptions(ios_base::badbit);
    while (cin >> word)
      ++counts[word];
    for_each(counts.begin(), counts.end(), print);
  } catch(ios_base::failure& ex) {
    std::cerr << "I/O error: " << ex.what() << '\n';
    return 1;
  } catch(exception& ex) {
    std::cerr << "Fatal error: " << ex.what() << '\n';
    return 2;
  } catch(...) {
    std::cerr << "Total disaster.\n";
    return 3;
  }
}
