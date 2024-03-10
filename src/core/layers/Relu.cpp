#include "Relu.h"

namespace cnncpp {

Relu::Relu(std::string name) {
  mName = name;
}

void Relu::forward(const Matrix& input) {
  mInput = input;
  mOutput.allocateMemoryIfNotAllocated(input.shape);

  // mOutput = mInput > 0 ? mInput : 0
  for (size_t i = 0; i < mInput.shape.x * mInput.shape.y; i++) {
    mOutput[i] = mInput[i] > 0 ? mInput[i] : 0.0f;
  }
}

void Relu::backward(const Matrix& output_gradient) {
  mInputGradient.allocateMemoryIfNotAllocated(mInput.shape);

  // mInputGradient = mOutput > 0 ? 1 : 0
  for (size_t i = 0; i < mInput.shape.x * mInput.shape.y; i++) {
    mInputGradient[i] = mInput[i] > 0 ? output_gradient[i] : 0.0f;
  }
}

}  // namespace cnncpp
