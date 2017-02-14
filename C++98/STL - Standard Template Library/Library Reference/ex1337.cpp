// Example 13-37: Classifying a string.
#include <ciso646>
#include <iostream>
#include <string>
using namespace std;

enum kind { empty, ident, integer, floatingpt, error };

kind classify(const string& s)
{
  using string;
  const string lower("abcdefghijklmnopqrstuvwxyz");
  const string upper("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  const string letters = lower + upper + '_';
  const string digits("0123456789");
  const string identchars = letters + digits;

  if (s.empty())
    return empty;

  else if (letters.find_first_of(s[0]) != string::npos) {
    // Check for valid identifier.
    if (s.find_first_not_of(identchars, 1) == string::npos)
      return ident;
    else
      return error;
  }

  // Skip a leading sign, if present.
  string::size_type pos;
  if (s[0] == '+' or s[0] == '-')
    pos = 1;
  else
    pos = 0;

  // The number must start with a digit.
  if (pos == s.length())
    return error;
  if (not digits.find_first_of(s[pos]))
    return error;
  // Find where the digit string ends.
  pos = s.find_first_not_of(digits, pos);
  if (pos == string::npos)
    // Only digits => integer.
    return integer;

  else if (s[pos] == '.') {
    // There is a decimal point.
    pos = s.find_first_not_of(digits, pos+1);
    if (pos == string::npos)
      // Integer part "." fractional part
      return floatingpt;
  }

  // Look for optional exponent.
  if (s[pos] == 'e' or s[pos] == 'E') {
    if (pos == s.length() - 1)
      return error; // 'e' or 'E' is last char
    else if (s[pos+1] == '+' or s[pos+1] == '-')
      ++pos;        // skip over sign;
    if (pos == s.length() - 1)
      return error; // sign is last char
    pos = s.find_first_not_of(digits, pos+1);
    if (pos == string::npos)
      return floatingpt;
  }

  return error;
}
