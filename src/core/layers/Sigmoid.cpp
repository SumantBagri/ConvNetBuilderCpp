#include "Sigmoid.h"
#include <cmath>

namespace cnncpp {

Sigmoid::Sigmoid(std::string name) {
  mName = name;
}

void Sigmoid::forward(const Matrix& input) {
  mInput = input;
  mOutput.allocateMemoryIfNotAllocated(input.shape);

  // mOutput = 1 / 1 + e^(-input)
  for (size_t i = 0; i < mInput.shape.x * mInput.shape.y; i++) {
    mOutput[i] = 1.0f / (1.0f + std::exp(-input[i]));
  }
}

void Sigmoid::backward(const Matrix& output_gradient) {
  mInputGradient.allocateMemoryIfNotAllocated(mInput.shape);

  // mInputGradient = output_gradient * sigmoid(x) * (1 - sigmoid(x))
  for (size_t i = 0; i < mInput.shape.x * mInput.shape.y; i++) {
    mInputGradient[i] = mOutput[i] * (1.0f - mOutput[i]) * output_gradient[i];
  }
}

}  // namespace cnncpp
