// Example 5-21: Binding references to conversion lvalues.
enum color { red, black };

template<typename T>
class rbnode {
public:
  rbnode(const T& value, color c);
  operator color()  { return color_; }
  operator T&()     { return value_; }
private:
  T value_;
  color color_;
};

rbnode<int> n(42, black);
const color& c1 = n;
int& i1 = n;
