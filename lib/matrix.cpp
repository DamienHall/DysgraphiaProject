#include "matrix.h"
#include "tools.h"
#include <vector>
#include <iostream>

// empty constructor to satisfy the c++ gods
Matrix::Matrix() {}

// constructor for matrix, rows↓, cols→
Matrix::Matrix(int rows, int cols) {
  init(rows, cols);
}

// class initializer
void Matrix::init(int rows, int cols) {
  this->rows = rows;
  this->cols = cols;
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

// set the matrix values to the guest matrix values
void Matrix::set(Matrix guestMatrix) {
  for (int row = 0; row < this->rows; row++) {
    for (int col = 0; col < this->cols; col++) {
      this->matrix[row][col] = guestMatrix.get(row+1,col+1);
    }
  }
}

// fill the matrix with a specified value
void Matrix::fill(float value) {
  for (int row = 0; row < this->rows; row++) {
    for (int col = 0; col < this->cols; col++) {
      this->matrix[row][col] = value;
    }
  }
}

// fill matrix with random values in a range
void Matrix::fillRandom(int min, int max) {
  for (int row = 0; row < this->rows; row++) {
    for (int col = 0; col < this->cols; col++) {
      this->matrix[row][col] = randomInt(min, max);
    }
  }
}

// add the guestMatrix to the current matrix
Matrix Matrix::add(Matrix guestMatrix) {
  Matrix outputMatrix(this->rows, this->cols);
  if (this->rows!=guestMatrix.getRows()&&this->cols!=guestMatrix.getCols()) {
    cout<<"ERR"<<endl;
    return outputMatrix;
  }
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
  if (this->rows!=guestMatrix.getRows()&&this->cols!=guestMatrix.getCols()) {
    return outputMatrix;
  }
  for (int row = 0; row < this->rows; row++) {
    for (int col = 0; col < this->cols; col++) {
      outputMatrix.set(row+1, col+1, this->matrix[row][col]-guestMatrix.get(row+1,col+1));
    }
  }
  return outputMatrix;
}

// multiply the current matrix by the guestMatrix
Matrix Matrix::multiply(Matrix guestMatrix) {
  Matrix outputMatrix(this->rows, guestMatrix.getCols());
  if (this->cols!=guestMatrix.getRows()) {
    std::cout << "WARNING: this->cols!=passedMatrix->rows" << std::endl;
    return outputMatrix;
  }
  // for every col→ in guestMatrix
  for (int c2 = 0; c2 < guestMatrix.getCols(); c2++) {
    // for every row↓ in this matrix
    for (int r1 = 0; r1 < this->rows; r1++) {
      float sum = 0;
      // for every col→ in this matrix
      for (int c1 = 0; c1 < this->cols; c1++) {
        float a = this->matrix[r1][c1];
        float b = guestMatrix.get(c1+1, c2+1);
        sum += a*b;
      }
      outputMatrix.set(r1+1, c2+1, sum);
    }
  }
  return outputMatrix;
}

// multiply the current matrix by a value
Matrix Matrix::multiply(float value) {
  Matrix outputMatrix(this->rows, this->cols);
  for (int row = 0; row < this->rows; row++) {
    for (int col = 0; col < this->cols; col++) {
      outputMatrix.set(row+1, col+1, this->matrix[row][col]*value);
    }
  }
  return outputMatrix;
}

// sigmoid all of the values in Matrix
Matrix Matrix::sign() {
  Matrix outputMatrix(this->rows, this->cols);
  for (int row = 0; row < this->rows; row++) {
    for (int col = 0; col < this->cols; col++) {
      outputMatrix.set(row+1, col+1, sigmoid(this->matrix[row][col]));
    }
  }
  return outputMatrix;
}

// print out the matrix
void Matrix::print() {
  for (int row = 0; row < this->rows; row++) {
    for (int col = 0; col < this->cols; col++) {
      std::cout << this->matrix[row][col] << "\t";
    }
    std::cout << std::endl;
  }
}
