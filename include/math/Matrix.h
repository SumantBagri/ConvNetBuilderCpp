#ifndef MATRIX_H
#define MATRIX_H

#include <math/Shape.h>
#include <memory>
#include <vector>

namespace cnncpp {

class Matrix {
 public:
  Shape shape;

  Matrix(size_t x_dim = 1, size_t y_dim = 1);
  Matrix(Shape shape);

  void allocateMemory();
  void allocateMemoryIfNotAllocated(Shape shape);

  float& operator[](const int index);              // to set a value
  const float& operator[](const int index) const;  // to read a value

  // expensive CPU matrix multiplication
  Matrix operator*(const Matrix& rhs) const;

 private:
  bool mIsHostAllocated;
  std::shared_ptr<float> mDataHost;

  void allocateHostMemory();
};

}  // namespace cnncpp

#endif  // MATRIX_H