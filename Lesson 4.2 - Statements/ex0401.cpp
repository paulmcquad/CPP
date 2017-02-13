// Example 4-1: Mixing declarations and statements.
#include <cstddef>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>
using namespace std;

// Count lines, words, and characters in the standard input.
int main(int argc, char *argv[]){
	
  unsigned long num_lines, num_words, num_chars;

  num_lines = num_words = num_chars = 0;

  string line;
  while (getline(cin, line)) {
    ++num_lines;
    num_chars += line.length() + 1;

    bool in_word = false;
    for (size_t i = 0; char c = line[i]; ++i)
     if (isspace(static_cast<unsigned char>(c))) {
       if (in_word)
         ++num_words;
       in_word = false;
     } else if (! in_word)
       in_word = true;
    if (in_word)
      ++num_words;
  }
  cout << right <<
    setw(10) << num_lines <<
    setw(10) << num_words <<
    setw(10) << num_chars << '\n';
}
