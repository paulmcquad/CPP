// Example 13-29: Using a map to count word frequencies.
#include <algorithm>
#include <iostream>
#include <istream>
#include <map>
#include <ostream>
#include <string>
using namespace std;

typedef map<string, size_t> freqmap;

// Print a single word and its count.
void print(const freqmap::value_type info)
{
  cout << info.first << '\t' << info.second << '\n';
}

int main(int argc, char *argv[]){
	
  freqmap fm;
  string word;
  // Count words: if a word is not in the map, add it.
  // When a new word is added, its count is initially zero.
  // Each time, including the first, increment the count.
  while (cin >> word)
    ++fm[word];
  // Print the frequencies of each word, in order.
  for_each(fm.begin(), fm.end(), print);
}
