// Example 4-9: Using goto statements.
#include <iostream>
#include <ostream>
using namespace std;

int main(int argc, char* argv[])
{
  int matrix[4][5];
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 5; ++j)
      if (! (cin >> matrix[i][j]))
        goto error;
  goto end;

error:
  cerr << "Need 20 values for the matrix\n";
end:
  return 0;
}
