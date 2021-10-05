#include "matrix.h"

class Neuron {
  private:
    int inputCount;
    Matrix* weights = NULL;
    Matrix* biases = NULL;
  public:
    Neuron(int inputCount);
    void initialize();
    float guess(Matrix inputs);
};
