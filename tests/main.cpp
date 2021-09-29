#include "../lib/matrix.h"
#include <iostream>

using namespace std;

int main() {

  Matrix mA(2,3);
  Matrix mB(3,5);
  Matrix mC(2,5);

  mA.print();
  cout << endl;
  mB.print();
  cout << endl;
  mC.print();

  return 0;
}
