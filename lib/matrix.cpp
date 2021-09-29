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

// set the value at row↓-1,col→-1
void Matrix::set(int row, int col, float value) {
  this->matrix[row-1][col-1] = value;
}

// fill the matrix with a specified value
void Matrix::fill(float value) {
  for (int row = 0; row < this->rows; row++) {
    for (int col = 0; col < this->cols; col++) {
      this->matrix[row][col] = value;
    }
  }
}

// add the guestMatrix to the current matrix
Matrix Matrix::add(Matrix guestMatrix) {
  Matrix outputMatrix(this->rows, this->cols);
  for (int row = 0; row < this->rows; row++) {
    for (int col = 0; col < this->cols; col++) {
      outputMatrix.set(row+1, col+1, this->matrix[row][col]+guestMatrix.get(row+1,col+1));
    }
  }
  return outputMatrix;
}

// subtract the current matrix by the guestMatrix
Matrix Matrix::subtract(Matrix guestMatrix) {
  Matrix outputMatrix(this->rows, this->cols);
  for (int row = 0; row < this->rows; row++) {
    for (int col = 0; col < this->cols; col++) {
      outputMatrix.set(row+1, col+1, this->matrix[row][col]-guestMatrix.get(row+1,col+1));
    }
  }
  return outputMatrix;
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
