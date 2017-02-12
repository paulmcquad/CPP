// Example 2-11: Simplifying function pointer declarations with typedef.
// Array of 10 function pointers.
int* (*fp1[10])(int*(*)(int*), int);

// Declare a type for pointer to int.
typedef int* int_ptr;
// Declare a function pointer type for a function that
// takes an int_ptr parameter and returns an int_ptr.
typedef int_ptr (*int_ptr_func)(int_ptr);
// Declare a function pointer type for a function that
// returns int_ptr and takes two parameters: the first
// of type int_ptr and the second of type int.
typedef int_ptr (*func_ptr)(int_ptr_func, int);
// Declare an array of 10 func_ptrs.
func_ptr fp2[10];
