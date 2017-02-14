// Example 5-4: Default arguments in member functions.
class example {
public:
  void func1(int x, int y = data_); // Error

  // Achieve the desired effect with overloaded functions.
  void func2(int x, int y);
  void func2(int x)         { func(x, data_); }
private:
  int data_;
};
