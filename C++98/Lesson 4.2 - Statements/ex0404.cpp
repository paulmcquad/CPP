// Example 4-4: Switch statements.
#include <cstdlib>
#include <iostream>
#include <ostream>
using namespace std;

enum color { black, red, green, yellow, blue,
             magenta, cyan, white };

color get_pixel(unsigned row, unsigned col)
{
  color c = static_cast<color>(rand() % (white+1));
  cout << "get_pixel=" << c << '\n';
  return c;
}

void demo()
{

  int r = 0;
  int c = 0;

  switch (get_pixel(r, c))
  {
    cout << "this is never executed, but it is valid\n";
    case black:
       cout << "no color\n";
       break; // Don't forget the break statements!
    case red: case green: case blue:
      cout << "primary\n";
      break; // Omitting break is a common mistake.
    default:
      cout << "mixed\n";
      switch (get_pixel(r+1, c+1))
      case white: {
        const int x = 0;
        cout << "  white\n"; // This case is private to the
                             // inner switch statement.
        c = x;
      }
      if (r > 0)
        // If the color is yellow, the switch branches
        // directly to here. For colors other than red,
        // green, blue, and black, execution jumps to the
        // default label and gets here if r > 0.
        case yellow:
         cout << " yellow or r > 0\n";

      break; // A break after the last case is not necessary,
             // but a good idea in case you add a case later.
  }
}

int main(int argc, char *argv[]){
	
  for (int i = 0; i < 10; ++i)
    demo();
}
