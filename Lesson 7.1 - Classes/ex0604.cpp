// Example 6-4: Using a local class.
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// Take a string and break it up into tokens,
// storing the tokens in a vector.
void get_tokens(vector<string>& tokens,
                const string& str)
{
  class tokenizer {
  public:
    tokenizer(const string& str) : in_(str) {}
    bool next()
    {
      return in_ >> token_;
    }
    string token() const { return token_; }
  private:
    istringstream in_;
    string token_;
  };

  tokens.clear();
  tokenizer t(str);
  while (t.next())
    tokens.push_back(t.token());
}

int main(int argc, char *argv[]){
	
  string line;

  while (getline(cin, line)) {
    vector<string> tokens;
    get_tokens(tokens, line);
    copy(tokens.begin(), tokens.end(),
              ostream_iterator<string>(cout, "\n"));
  }
}
