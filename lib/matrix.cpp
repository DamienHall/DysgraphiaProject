#include "matrix.h"
#include <vector>
#include <iostream>

// constructor for matrix, rows↓, cols→
Matrix::Matrix(int rows, int cols) {
  // set values
  this->rows = rows;
  this->cols = cols;
  // initialize matrix
  this->matrix.resize(rows);
  for (int row = 0; row < rows; row++) {
    this->matrix[row].resize(cols);
    for (int col = 0; col < cols; col++) {
      this->matrix[row][col] = 0;
    }
  }
}

// get the rows of the matrix
int Matrix::getRows() {
  return this->rows;
}

// get the cols of the matrix
int Matrix::getCols() {
  return this->cols;
}

// get the value at row↓-1,col→-1
float Matrix::get(int row, int col) {
  return this->matrix[row-1][col-1];
}

// get the value at row↓-1,col→-1
void Matrix::set(int row, int col, float value) {
  this->matrix[row-1][col-1] = value;
}



// print out the matrix
void Matrix::print() {
  for (int row = 0; row < this->rows; row++) {
    for (int col = 0; col < this->cols; col++) {
      std::cout << this->matrix[row][col];
    }
    std::cout << std::endl;
  }
}
