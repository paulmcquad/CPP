// Example 13-36: Interpreting an HTML color string.

#include <iostream>
#include <istream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

typedef map<string, unsigned long> colormap;
colormap colors;

unsigned long get_color(const string& text)
{
  unsigned long rgb;
  colormap::iterator i = colors.find(text);
  if (i != colors.end())
    return i->second;
  else if (text.length() == 0)
    return 0;
  else {
    istringstream in(text);
    if (in.peek() == '#')
      in.ignore();
    in >> noskipws >> hex >> rgb;
    if (in)
      return rgb;
    else
      return 0;
  }
}

void initcolors(colormap& colors)
{
  colors["aqua"]    = 0x00FFFF;
  colors["black"]   = 0x000000;
  colors["blue"]    = 0x0000FF;
  colors["fuschia"] = 0xFF00FF;
  colors["gray"]    = 0x808080;
  colors["green"]   = 0x008000;
  colors["lime"]    = 0x00FF00;
  colors["maroon"]  = 0x800000;
  colors["navy"]    = 0x000080;
  colors["olive"]   = 0x808000;
  colors["puple"]   = 0x800080;
  colors["red"]     = 0xFF0000;
  colors["silver"]  = 0xC0C0C0;
  colors["teal"]    = 0x008080;
  colors["white"]   = 0xFFFFFF;
  colors["yellow"]  = 0xFFFF00;
}
