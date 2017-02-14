// Example 13-14: Copying information associated with streams
#include <fstream>
#include <ios>
using namespace std;

class infostruct {};

void manage_info(ios_base::event event,
                 ios_base& stream, int index)
{
  infostruct* ip;

  switch(event) {
  case ios_base::erase_event:
    ip = static_cast<infostruct*>(stream.pword(index));
    stream.pword(index) = 0;
    delete ip;
    break;
  case ios_base::copyfmt_event:
    stream.pword(index) = new infostruct;
    break;
  default:
    break; // imbue_event does not affect storage
  }
}

void openread(ifstream& f, const char* name)
{
  f.open(name);
  int index = f.xalloc();
  f.pword(index) = new infostruct;
  f.register_callback(manage_info, index);
}
