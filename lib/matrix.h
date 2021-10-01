#include <vector>
#include <string>

class Matrix {
  private:
    int rows;
    int cols;
    std::vector<std::vector<float>> matrix;
  public:
    Matrix(int rows, int cols);
    int getRows();
    int getCols();
    float get(int row, int col);
    void set(int row, int col, float value);
    void fill(float value);
    void fillRandom(int min, int max);
    Matrix add(Matrix guestMatrix);
    Matrix subtract(Matrix guestMatrix);
    Matrix multiply(Matrix guestMatrix);
    Matrix multiply(float value);
    Matrix abs();
    void print();
};
