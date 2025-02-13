#include "../s21_matrix_oop.h"

void S21Matrix::create_matrix() {
  matrix_ = nullptr;
  if (rows_ > 0 && cols_ > 0) {
    matrix_ = new double *[rows_];
    *matrix_ = new double[rows_ * cols_];  // ooo ****|****|****
    for (int i = 1; i < rows_; i++) {
      matrix_[i] = matrix_[0] + i * cols_;
    }
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = 0.0;
      }
    }
  }
}

S21Matrix::S21Matrix() : rows_(3), cols_(3) { create_matrix(); }

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if ((rows < 0 || cols < 0)) {
    throw std::bad_array_new_length();
  }
  create_matrix();
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(nullptr) {
  create_matrix();
  if (other.matrix_)
    std::memcpy(matrix_[0], other.matrix_[0],
                other.rows_ * other.cols_ * sizeof(double));
}

S21Matrix::S21Matrix(S21Matrix &&other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

S21Matrix::~S21Matrix() {
  if (matrix_) {
    delete[] * matrix_;
    delete[] matrix_;
  }
}