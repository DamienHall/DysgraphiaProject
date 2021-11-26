#include "neuron.h"
#include "matrix.h"
#include <iostream>

Neuron::Neuron(int inputCount) {
  this->inputCount = inputCount;
  this->weights = new Matrix(1, inputCount);
  this->biases = new Matrix(inputCount, 1);
  initialize();
}

void Neuron::initialize() {
  this->weights->fillRandom(0, 1);
  this->weights->print();
  this->biases->fillRandom(0, 1);
  this->biases->print();
}
