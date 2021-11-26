#include "neuron.h"
#include "tools.h"
#include <iostream>
#include <cmath>

Neuron::Neuron(int inputCount) {
  this->weights = new Matrix(1, inputCount);
  this->weights->fillRandom(-1, 1);
}

void Neuron::printWeights() {
  this->weights->print();
}

float Neuron::guess(Matrix inputs) {
  Matrix outputMatrix = this->weights->multiply(inputs);
  this->guesses++;
  return sigmoid(outputMatrix.get(1,1));
}

void Neuron::train(Matrix inputs, float target) {
  float guess = this->guess(inputs);
  float error = target - guess;
  this->guessesCorrect+=(guess==target?1:0);
  this->successRate=((float)this->guessesCorrect/this->guesses)*100;
  Matrix correctionMatrix(this->weights->getRows(),this->weights->getCols());
  for (int row = 0; row < this->weights->getRows(); row++) {
    for (int col = 0; col < this->weights->getCols(); col++) {
      correctionMatrix.set(row+1,col+1,error*inputs.get(col+1,row+1)*this->learningRate);
    }
  }
  this->weights->set(this->weights->add(correctionMatrix));
  // this->weights->set(this->weights->sign());
}

float Neuron::getSuccessRate() {
  return this->successRate;
}
