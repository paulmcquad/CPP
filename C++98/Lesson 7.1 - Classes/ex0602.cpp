// Example 6-2: Declaring POD and non-POD types.
struct point1 {                   // POD
  int x, y;
};

class point2 {                    // not POD
public:
  point2(int x, int y);
private:
  int x, y;
};

struct info {                    // POD
  static const int max_size = 50;
  char name[max_size];
  bool is_name_valid() const;
  bool operator<(const info& i); // compare names
};

struct employee : info {         // not POD
  int salary;
};
