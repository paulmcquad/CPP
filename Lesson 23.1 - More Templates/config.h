// Example 7-19: Configuring template compilation macros.
#ifndef CONFIG_H
#define CONFIG_H

#ifdef __COMO__
  #define HAS_EXPORT
  #undef NEED_TEMPLATE_DEFINITIONS
#elif defined(__BORLANDC__) || defined(__GNUC__) || defined(__INTEL_COMPILER) ||\
    defined(_MSC_VER) || defined(__MWERKS__)
  #undef HAS_EXPORT
  #define NEED_TEMPLATE_DEFINITIONS
#else
  #error Unknown compiler
#endif

#endif // CONFIG_H
