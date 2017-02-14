// Example 5-20: Initializing non-class objects by calling conversion functions.
enum color { red, black };

template<typename T>
class rbnode {
public:
  rbnode(const T& value, color c);
  operator color() const { return color_; }
  operator T() const { return value_; }
private:
  T value_;
  color color_;
};

rbnode<int> n(42, black);

color c = n;
int i = n;
