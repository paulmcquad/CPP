// Example 7-11: Dependent names.
template<typename T> struct base {
  typedef T value_type; // value_type is dependent
  void func(T*);        // func is dependent
  void proc(int);       // proc is non-dependent

  class inner {         // inner is dependent
    int x;              // x is non-dependent
  };
  template<unsigned N>
  class data {          // data is dependent
    int array[N];       // array is dependent
  };

  class demo : inner {  // demo is dependent
    char y[sizeof(T)];  // y is dependent
  };
};

int main(int argc, char *argv[]){
		
  base<int> b;
}
