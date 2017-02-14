// Example 13-26: A simple facet for working with units of measure.
#include <iostream>
#include <istream>
#include <locale>
#include <ostream>
#include <string>
using namespace std;

// "units" is a facet to represent measurements in the preferred units
// for a locale, e.g., inches in the United States, or centimeters in France.
// This class is simple and meant for demonstration, not production use.
//
// For each kind of measurement, values are stored in terms of a single
// common unit, such as tenths of a millimeter.

class units : public locale::facet
{
public:
  enum length_units { length_base=1, mm=10, cm=10*mm, m=10*cm, km=1000*m,
                      in=254, ft=12*in, yd=3*ft, mi=5280*ft };
  enum weight_units { weight_base=1, gm=100, kg=1000*gm, oz=2835, lb=16*oz };
  typedef double value_t;

  static locale::id id;

  units();

  value_t length_get(istream& stream) const;
  value_t weight_get(istream& stream) const;

  void length_put(ostream& stream, value_t value) const
  {
    stream << convert(value, get_length_units()) << unit_name(get_length_units());
  }

  void weight_put(ostream& stream, value_t value) const
  {
    stream << convert(value, get_weight_units()) << unit_name(get_weight_units());
  }

  // Make a base unit value from a value in src_units.
  value_t make(value_t src_value, length_units src_units) const
  {
    return src_value * src_units;
  }

  value_t make(value_t src_value, weight_units src_units) const
  {
    return src_value * src_units;
  }

  // Convert base units to dst_unit.
  value_t convert(value_t src_value, length_units dst_units) const
  {
    return src_value / dst_units;
  }

  value_t convert(value_t src_value, weight_units dst_units) const
  {
    return src_value / dst_units;
  }

  const char* unit_name(length_units units) const;
  const char* unit_name(weight_units units) const;
  length_units get_length_units() const { return length_units_; }
  weight_units get_weight_units() const { return weight_units_; }
private:
  length_units length_units_;
  weight_units weight_units_;
};

locale::id units::id;

units::units()
{
  // To do: get preferred units from locale-specific source.
  length_units_ = in;
  weight_units_ = lb;
}

// Read a sequence of alphabetic characters.
static string getalpha(istream& stream)
{
  char c;
  string text;

  while (stream.get(c))
    if (isalpha(c, locale()))
      text += c;
    else {
      stream.unget();
      break;
    }

  return text;
}

units::value_t units::length_get(istream& stream) const
{
  value_t tmp;
  stream >> tmp;
  string text = getalpha(stream);

  if (text == "mm")
    return make(tmp, mm);
  else if (text == "cm")
    return make(tmp, cm);
  else if (text == "m")
    return make(tmp, m);
  else if (text == "km")
    return make(tmp, km);
  else if (text == "in")
    return make(tmp, in);
  else if (text == "ft")
    return make(tmp, ft);
  else if (text == "yd")
    return make(tmp, yd);
  else if (text == "mi")
    return make(tmp, mi);
  else
    return tmp;
}

units::value_t units::weight_get(istream& stream) const
{
  value_t tmp;
  stream >> tmp;
  string text = getalpha(stream);

  if (text == "gm")
    return make(tmp, gm);
  else if (text == "kg")
    return make(tmp, kg);
  else if (text == "oz")
    return make(tmp, oz);
  else if (text == "lb")
    return make(tmp, lb);
  else
    return tmp;
}


const char* units::unit_name(length_units units) const
{
  switch(units) {
  case mm: return "mm";
  case cm: return "cm";
  case m:  return "m";
  case km: return "km";
  case in: return "in";
  case ft: return "ft";
  case yd: return "yd";
  case mi: return "mi";
  default:
      return "?";
  }
}

const char* units::unit_name(weight_units units) const
{
  switch(units) {
  case gm: return "gm";
  case kg: return "kg";
  case oz: return "oz";
  case lb: return "lb";
  default:
      return "?";
  }
}

int main(int argc, char *argv[]){
	
  // Add the units facet to the global locale.
  locale::global(locale(locale(), new units));

  while (cin)
  {
    const units& u = use_facet<units>(locale());
    units::value_t len = u.length_get(cin);
    u.length_put(cout, len);
    cout << '\n';
  }
}
