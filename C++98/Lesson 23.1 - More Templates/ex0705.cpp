// Example 7-5: Defining class templates.
template<typename T, typename U = int>
class demo {
public:
  demo(T t, U u);
  ~demo();
  static T data;
  class inner; // inner is a plain class, not a template
};

template<typename T, typename U>
demo<T,U>::demo(T, U)  // or demo<T,U>::demo<T,U>(T, U)
{}

template<typename T, typename U>
demo<T,U>::~demo<T,U>() // or demo<T,U>::~demo()
{}

template<typename U, typename T> // allowed, but confusing
U demo<U,T>::data;

template<typename T, typename U>
class demo<T,U>::inner {
public:
  inner(T, demo<T,U>& outer);
private:
  demo<T,U>& outer;
};

// The class name is "demo<T,U>::inner", and the constructor
// name is "inner".
template<typename T, typename U>
demo<T,U>::inner::inner(T, demo<T,U>& outer)
: outer(outer)
{}
