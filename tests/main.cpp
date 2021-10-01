#include "../lib/matrix.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {

  int inputs = 4;
  int neurons = 3;


  Matrix mA(neurons, inputs);
  Matrix mB(inputs, 1);
  Matrix mC(inputs, 1);

  mA.fillRandom(1,4);
  mB.fillRandom(1,5);

  mC = mA.multiply(mB);

  mA.print();
  cout << endl;
  mB.print();
  cout << endl;
  mC.print();

  return 0;
}
