// Example 13-7: Reading input until interrupted.
#include <csignal>
#include <iostream>
#include <string>
using namespace std;

volatile sig_atomic_t interrupted;

// Signal handler sets a global flag.
extern "C" void sigint(int sig)
{
  interrupted = 1;
}

int main(int argc, char *argv[]){

  //
  if (signal(SIGINT, sigint) == SIG_ERR)
    cerr << "Cannot set signal handler\n";
  else
  {
    unsigned long count = 0;           // count lines
    while(! interrupted)
    {
      cout << "> ";               // user prompt
      string s;
      if (! getline(cin, s))
        // EOF does not terminate the loop, only SIGINT
        cin.clear();
      ++count;
    }
    cout << "I counted " << count << " line(s).\n";
  }
}
