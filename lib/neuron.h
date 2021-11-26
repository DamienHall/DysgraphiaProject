#include "matrix.h"

class Neuron {
  private:
    Matrix* weights;
    float learningRate = 0.1;
    float successRate = 0.0;
    int guesses = 0;
    int guessesCorrect = 0;
  public:
    Neuron(int inputCount);
    void printWeights();
    float guess(Matrix inputs);
    void train(Matrix inputs, float targets);
    float getSuccessRate();
};
