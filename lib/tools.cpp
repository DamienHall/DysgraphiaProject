#include "tools.h"
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

// random numbers
int randomInt(int min, int max) {
    return (rand()%(max-min+1))+min;
}

double randomDouble(double min, double max) {
    return min+((double)rand()/RAND_MAX)*(max-min);
}

void seedRandom() {
    srand(time(NULL));

}

// debug tools
void debugLog(int line) {
    cout << "WORKING UP TO LINE: " << line << endl;
}

void debugLog(char a) {
  cout << a << endl;
}

void debugLog(float a) {
  cout << a << endl;
}

void debugLog(double a) {
  cout << a << endl;
}

void debugLog(string a) {
  cout << a << endl;
}
