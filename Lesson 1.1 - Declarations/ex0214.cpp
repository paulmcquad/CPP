// Example 2-14: Using an empty initializer.
template<typename T>
struct wrapper {
  wrapper() : value_(T()) {}
  explicit wrapper(const T& v) : value_(v) {}
private:
  T value_;
};

enum color { black, red, green, blue };
struct point { int x, y; };

int main(int argc, char *argv[]){
	
  wrapper<int> i;    // initializes i with int(), or zero
  wrapper<color> c;  // initializes c with color(), or black
  wrapper<bool> b;   // initializes b with bool(), or false
  wrapper<point> p;  // initializes p with point()
}

