#include "tools.h"
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <cmath>

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

float relu(float x) {
  return (abs(x)+x)/2;
}

float sigmoid(float x) {
  return round(x/(1+abs(x)));
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
