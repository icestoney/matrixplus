#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix temp(*this);

  return temp += other;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix temp(*this);

  return temp -= other;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix temp(*this);
  return temp *= other;
}

S21Matrix S21Matrix::operator*(const double &value) {
  S21Matrix temp(*this);
  return temp *= value;
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this != &other) {
    if (matrix_) {
      delete[] * matrix_;
      delete[] matrix_;
      matrix_ = nullptr;
    }
    rows_ = other.rows_;
    cols_ = other.cols_;
    if (other.matrix_) {
      create_matrix();
      for (int i = 0; i < rows_; ++i) {
        std::memcpy(matrix_[i], other.matrix_[i], cols_ * sizeof(double));
      }
    }
  }

  return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) {
  if (matrix_) {
    delete[] * matrix_;
    delete[] matrix_;
    matrix_ = nullptr;
  }
  this->matrix_ = other.matrix_;
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
  return *this;
}

bool S21Matrix::operator==(const S21Matrix &other) { return EqMatrix(other); }

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);

  return *this;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);

  return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);

  return *this;
}

S21Matrix &S21Matrix::operator*=(const double &value) {
  MulNumber(value);

  return *this;
}

double &S21Matrix::operator()(int row, int col) {
  if (row < 0 || col < 0 || row >= rows_ || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}