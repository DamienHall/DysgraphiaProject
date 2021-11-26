#include "../lib/neuron.h"
#include "../lib/tools.h"
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  seedRandom();

  int colors = 2;
  int trainingDataSize = 1000;
  Matrix inputLayer(colors, 1);
  Neuron n1(colors);

  int i = 0;
  float old;
  while (n1.getSuccessRate()<100) {
    inputLayer.fillRandom(0,255);
    n1.train(inputLayer, inputLayer.get(1,1)>inputLayer.get(2,1)?1:-1);
    if (old != floor(n1.getSuccessRate())) {
      old = floor(n1.getSuccessRate());
      cout<<floor(n1.getSuccessRate())<<endl;
    }
    i++;
  }

  return 0;
}
