// Example 2-10: Overloading operators for enumerations.
#include <cstdlib>
using namespace std;

enum iostate { goodbit=0, badbit=1, failbit=2, eofbit=4 };

// Explicitly cast to int, to avoid infinite recursion.
inline iostate operator|(iostate a, iostate b) {
  return iostate(int(a) | int(b));
}
inline iostate& operator|=(iostate& a, iostate b) {
  a = a | b;
  return a;
}

inline iostate operator&(iostate a, iostate b) {
  return iostate(int(a) & int(b));
}
inline iostate& operator&=(iostate& a, iostate b) {
  a = a & b;
  return a;
}

inline iostate operator^(iostate a, iostate b) {
  return iostate(int(a) ^ int(b));
}
inline iostate& operator^=(iostate& a, iostate b) {
  a = a ^ b;
  return a;
}

inline iostate operator~(iostate a) {
  return iostate(~int(a));
}

bool error()
{
  return rand() % 2 != 0;
}

int main(int argc, char *argv[]){
	
  iostate err = goodbit;
  if (error())
    err |= badbit;
}
