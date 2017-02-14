// Example 5-24: Overloading the increment operator.
enum status { stopped, running, waiting };
status& operator++(status& s) { // prefix
  if (s != waiting)
    s = status(s + 1);
  return s;
}
status operator++(status& s, int) {   // postfix
  status rtn = s;
  ++s;
  return rtn;
}
int main(int argc, char *argv[]){
	
  status s(stopped);
  ++s;                  // calls operator++(s);
  s++;                  // calls operator++(s, 0);
}
