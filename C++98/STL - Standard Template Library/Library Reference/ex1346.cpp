// Example 13-46: A simple 2D matrix class.
#include <cstddef>
#include <valarray>
using namespace std;

template<typename T>
class matrix2D {
public:
  matrix2D(size_t rows, size_t columns) :
    rows_(rows), cols_(columns), data_(rows * columns) {}
  size_t rows() const { return rows_; }
  size_t cols() const { return cols_; }
  valarray<T> row(size_t r) const
    { return data_[slice(r*cols(),cols(), 1)]; }
  valarray<T> col(size_t c) const
    { return data_[slice(c, rows(), cols())]; }
  slice_array<T> row(size_t r)
    { return data_[slice(r*cols(),cols(), 1)]; }
  slice_array<T> col(size_t c)
    { return data_[slice(c, rows(), cols())]; }
  T& operator()(size_t r, size_t c)
    { return data_[r*cols()+c]; }
  T operator()(size_t r, size_t c) const
    { return row(r)[c]; }
  matrix2D<T> transpose() {
    matrix2D<T> result(cols(), rows());
    for (size_t i = 0; i < rows(); ++i)
      result.col(i) = static_cast<valarray<T> >(row(i));
    return result;
  }
private:
  size_t rows_;
  size_t cols_;
  valarray<T> data_;
};
