#include "../lib/matrix.h"
#include <iostream>

using namespace std;

int main() {

  // Matrix mA(2,3);
  // Matrix mB(3,5);
  // Matrix mC(2,5);
  Matrix mA(2,2);
  Matrix mB(2,2);
  Matrix mC(2,2);

  mA.fill(1);
  mB.fill(2);
  mC = mA.add(mB);

  mA.print();
  cout << endl;
  mB.print();
  cout << endl;
  mC.print();

  return 0;
}
