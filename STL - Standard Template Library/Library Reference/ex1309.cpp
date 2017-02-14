// Example 13-9: Copying a file using ifstream and ofstream.
#include <cstdlib>
#include <fstream>
#include <cstdio>    // for perror()
#include <iostream>  // for cerr

int main(int argc, char *argv[]){
	
  if (argc != 3) {
    cerr << "usage: copy FROM TO\n";
    return EXIT_FAILURE;
  }

  // Open the input file.
  ifstream in(argv[1]);
  if (! in) {
    perror(argv[1]);
    return EXIT_FAILURE;
  }

  // Open the output file.
  ofstream out(argv[2]);
  if (! out) {
    perror(argv[2]);
    return EXIT_FAILURE;
  }

  // Copy the input to the output, one character at a time.
  char c;
  while (in.get(c))
    out.put(c);
  out.close();
  // Make sure the output was written.
  if (! out) {
    perror(argv[2]);
    return EXIT_FAILURE;
  }
}
