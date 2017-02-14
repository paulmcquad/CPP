// Example 11-1: Defining type traits with a macro.
#ifndef ISINTEGER_H
#define ISINTEGER_H

// Type trait to test whether a type is an integer.
struct is_integer_tag {};
struct is_not_integer_tag {};

// The default is that a type is not an integral type.
template<typename T>
struct is_integer {
  enum { value = 0 };
  typedef is_not_integer_tag tag;
};

// Explicitly override the default for all integral types.
#define DECL_IS_INTEGER(T)     \
template<>                     \
struct is_integer<T> {         \
  enum { value = 1 };          \
  typedef is_integer_tag tag;  \
}

DECL_IS_INTEGER(bool);
DECL_IS_INTEGER(char);
DECL_IS_INTEGER(signed char);
DECL_IS_INTEGER(unsigned char);
DECL_IS_INTEGER(int);
DECL_IS_INTEGER(unsigned int);
DECL_IS_INTEGER(short);
DECL_IS_INTEGER(unsigned short);
DECL_IS_INTEGER(long);
DECL_IS_INTEGER(unsigned long);

#undef  DECL_IS_INTEGER
#endif
