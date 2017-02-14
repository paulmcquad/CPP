// Example 6-16: Declaring and using virtual functions.
#include <exception>
#include <iostream>
#include <istream>
#include <limits>
#include <memory>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

class expr {
public:
  virtual ~expr() {}
  virtual double evaluate() const = 0;
  string as_string() const {
    ostringstream out;
    print(out);
    return out.str();
  }
  virtual void print(ostream& out) const {}
  virtual int precedence() const = 0;
  template<typename charT, typename traits>
  static auto_ptr<expr> parse(basic_istream<charT,traits>& in);
protected:
  template<typename charT, typename traits>
  static auto_ptr<expr> term(basic_istream<charT,traits>& in);
  template<typename charT, typename traits>
  static auto_ptr<expr> factor(basic_istream<charT,traits>& in);
};

template<typename charT, typename traits>
basic_ostream<charT,traits>& operator<<(basic_ostream<charT,traits>& out, const expr& e)
{
  e.print(out);
  return out;
}


class literal : public expr {
public:
  literal(double value) : value_(value) {}
  virtual double evaluate() const { return value_; }
  virtual void print(ostream& out) const {
    out << value_;
  }
  virtual int precedence() const { return 1; }
private:
  double value_;
};

class binop : public expr {
public:
  binop(auto_ptr<expr> left, auto_ptr<expr> right) : left_(left), right_(right) {}
  virtual double evaluate() const { return eval(left_->evaluate(), right_->evaluate()); }
  virtual void print(ostream& out) const {
    if (left_->precedence() > precedence())
      out << '(' << *left_ << ')';
    else
      out << *left_;

    out << op();

    if (right_->precedence() > precedence())
      out << '(' << *right_ << ')';
    else
      out << *right_;
  }
  virtual int precedence() const = 0;
protected:
  virtual double eval(double left, double right) const = 0;
  virtual const char* op() const = 0;
private:
  binop(const binop&);
  void operator=(const binop&);
  auto_ptr<expr> left_;
  auto_ptr<expr> right_;
};

class plus : public binop {
public:
  plus(auto_ptr<expr> left, auto_ptr<expr> right) : binop(left, right) {}
  virtual int precedence() const { return 3; }
protected:
  virtual double eval(double left, double right) const {
    return left + right;
  }
  virtual const char* op() const { return "+"; }
};

class times : public binop {
public:
  times(auto_ptr<expr> left, auto_ptr<expr> right) : binop(left, right) {}
  virtual int precedence() const { return 2; }
protected:
  virtual double eval(double left, double right) const {
    return left * right;
  }
  virtual const char* op() const { return "*"; }
};

#define BINOP(name, symbol, prec)                               \
class name : public binop {                                     \
public:                                                         \
  name(auto_ptr<expr> left, auto_ptr<expr> right)     \
    : binop(left, right) {}                                     \
  virtual int precedence() const { return prec; }               \
protected:                                                      \
  virtual double eval(double left, double right) const {        \
    return left symbol right;                                   \
  }                                                             \
  virtual const char* op() const { return #symbol; }            \
};
BINOP(divide,        /,   2)
BINOP(minus,         -,   3)
BINOP(equal,         ==,  4)
BINOP(not_equal,     !=,  4)
BINOP(less,          <,   5)
BINOP(less_equal,    <=,  5)
BINOP(greater,       >,   5)
BINOP(greater_equal, >=,  5)

class parse_error : public runtime_error {
public:
  parse_error(char c) : runtime_error(string("syntax error near '") + c + "'") {}
  parse_error(const string& msg) : runtime_error(msg) {}
};

template<typename charT, typename traits>
auto_ptr<expr> expr::factor(basic_istream<charT,traits>& in)
{
  charT c;
  in >> c;
  if (!in)
    throw parse_error("unexpected EOF");
  if (c == '(') {
    auto_ptr<expr> rtn(parse(in));
    if (! (in >> c))
      throw parse_error("unexpected EOF");
    else if (c != ')')
      throw parse_error(string("expected ), got ") + c);
    else
      return rtn;
  } else {
    double x;
    in.unget();
    in >> x;
    return auto_ptr<expr>(new literal(x));
  }
}

template<typename charT, typename traits>
auto_ptr<expr> expr::term(basic_istream<charT,traits>& in)
{
  auto_ptr<expr> left(factor(in));
  charT c;
  in >> c;
  if (! in)
    return left;
  if (c != '*' && c != '/')
  {
    in.unget();
    return left;
  }

  auto_ptr<expr> right(factor(in));
  switch (c) {
  case '*': return auto_ptr<expr>(new times(left, right));
  case '/': return auto_ptr<expr>(new divide(left, right));
  default:  throw parse_error(string("cannot happen in term: c == ") + c);
  }
}

template<typename charT, typename traits>
auto_ptr<expr> expr::parse(basic_istream<charT,traits>& in)
{
  auto_ptr<expr> left(term(in));
  charT c;
  in >> c;
  if (! in)
    return left;
  if (c != '+' && c != '-')
  {
    in.unget();
    return left;
  }

  auto_ptr<expr> right(term(in));
  switch (c) {
  case '+': return auto_ptr<expr>(new plus(left, right));
  case '-': return auto_ptr<expr>(new minus(left, right));
  default: throw parse_error(string("cannot happen in parse: c == ") + c);
  }
}

int main(int argc, char *argv[]){
	
  do
    try {
      string line;
      cout << "> ";
      if (! getline(cin, line))
        break;
      istringstream in(line);

      in >> ws;
      if (in.eof())
        continue;
        
      auto_ptr<expr> e(expr::parse(in));
      in >> ws;
      if (! in.eof())
        cerr << "syntax error at end of expression\n";

      cout << *e << '\n';
      double (expr::* func)() const = &expr::evaluate;
      cout << (e.get()->*func)() << '\n';
    } catch (parse_error& p) {
      cerr << p.what() << '\n';
    } catch (exception& e) {
      cerr << e.what() << '\n';
      abort();
    }
  while(cin);
}
