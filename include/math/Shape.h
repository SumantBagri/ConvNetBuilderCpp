#ifndef SHAPE_H
#define SHAPE_H

#include <cstddef>

namespace cnncpp {

struct Shape {
  size_t x, y;

  Shape(size_t x = 1, size_t y = 1) : x(x), y(y) {}
};

}  // namespace cnncpp

#endif  // SHAPE_H
