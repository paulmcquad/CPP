// Example 5-22: Taking the address of an overloaded function.
int abs(int x)            { return x < 0 ? -x : x; }
long abs(long x)          { return x < 0 ? -x : x; }
double abs(double x)      { return x < 0 ? -x : x; }

template<typename T>
T abs(T x)
{ return x < 0 ? -x : x; }

template<typename T, typename U>
T abs(T x, U = U())
{ return x < 0 ? -x : x; }

int main()
{
  int (*intfunc)(int) = &abs;            // abs(int)
  double (*dblfunc)(double) = &abs;      // abs(double)
  float (*fltfunc)(float) = &abs;        // abs<float>
  short (*shrtfunc1)(short, int) = &abs; // abs<short,int>
  short (*shrtfunc2)(short) = &abs;      // abs<short>
}
