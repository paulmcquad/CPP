// Example 11-4: Nesting conditional directives.
#define zero zero  // identifiers are converted to 0
#define one  true  // bool expressions are promoted to int

#if one
// This region is compiled
  #if zero
  This region can contain erroneous C++ code. The code is not
  compiled, so the errors do not matter.
  #else // This #else matches the inner #if
    // This region is compiled.
    const int zero = 0;
  #endif // This #endif matches the inner #if
  int x = zero;
#else
  This #else matches the outer #if. Because the #if
  condition was true, the #else region is not compiled.
#endif

int main(int argc, char *argv[]){
	
  return x;
}
