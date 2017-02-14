// Example 13-23: Using infinity or maximum finite value to mean "no data."
#include <limits>
using namespace std;

// Define a template that will differentiate types that
// have a specialized numeric_limits and an explicit
// value for infinity.
template<typename T, bool is_specialized, bool has_infinity>
struct max_or_infinity
{};

// Specialize the template to obtain the value of infinity.
template<typename T>
struct max_or_infinity<T, true, true>
{
  static T value()
    { return numeric_limits<T>::infinity(); }
};

// Specialize the template if infinity is not supported.
template<typename T>
struct max_or_infinity<T, true, false>
{
  static T value() { return numeric_limits<T>::max(); }
};

// Note that type without a numeric_limits specialization
// do not have a max_or_infinity specialization, so the
// no_data function would result in compile-time errors
// when applies to such a type.
//
// The no_data function returns a value that can be used
// to mark points that do not have valid data.
template<typename T>
T no_data()
{
  return max_or_infinity<T,
    numeric_limits<T>::is_specialized,
    numeric_limits<T>::has_infinity>::value();
}
