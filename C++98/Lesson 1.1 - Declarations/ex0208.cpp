// Example 2-8: Defining members outside of a class declaration.
class node {
public:
  enum color { red, black };
  node(color x);
  color toggle(color c);
private:
  color c;
  static color root_color;
};

// Must qualify node::color and node::root_color, but
// initializer is in the scope of node, so it doesn't need
// to be qualified.
node::color node::root_color = red;

// Similarly, return type must be qualified, but parameter
// type need not be.
node::color node::toggle(color c)
{
  return static_cast<color>(1 - c);
}
