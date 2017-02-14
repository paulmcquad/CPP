// Example 7-15: Defining type lists
#ifndef TYPELIST_H
#define TYPELIST_H

struct empty {};
template<typename H, typename T>
struct node {
  typedef H head;
  typedef T tail;
};

template<typename T1  = empty, typename T2  = empty,
         typename T3  = empty, typename T4  = empty,
         typename T5  = empty, typename T6  = empty,
         typename T7  = empty, typename T8 = empty,
         typename T9  = empty, typename T10 = empty,
         typename T11 = empty, typename T12 = empty
>
struct list {
  typedef node<T1, node<T2, node<T3, node<T4,
          node<T5, node<T6, node<T7, node<T8,
          node<T9, node<T10, node<T11, node<T12,
          empty
          > > > > > > > > > > > > type;
};

template<typename L>
struct length {
  enum { value = 1 + length<typename L::tail>::value };
};
template<>
struct length<empty> {
  enum { value = 0 };
};

template<typename L>
struct is_empty {
  enum { value = false };
};
template<>
struct is_empty<empty> {
  enum { value = true };
};

// Example 7-16: Testing membership in a type list.
template<typename T, typename U>
struct is_same_type {
  enum  { value = false };
};
template<typename T>
struct is_same_type<T, T> {
  enum { value = true };
};

template<typename T, typename L>
struct is_member {
  enum { value = is_same_type<T, typename L::head>::value
              || is_member<T, typename L::tail>::value };
};

template<typename T>
struct is_member<T, empty> {
  enum { value = false };
};
#endif
