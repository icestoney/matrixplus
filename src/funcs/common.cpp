#include "../s21_matrix_oop.h"

bool S21Matrix::check_same_size(int o_rows, int o_cols) {
  return rows_ == o_rows && cols_ == o_cols;
}

bool S21Matrix::check_lcols_vs_rrows(int o_rows) { return cols_ == o_rows; }

bool S21Matrix::check_eq_cols_rows() { return rows_ == cols_; }

void S21Matrix::AriphmeticMatrix(const S21Matrix &other, int sign) {
  if (!check_same_size(other.rows_, other.cols_)) {
    throw std::invalid_argument(DiffSizesMatrix);
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] + sign * other.matrix_[i][j];
    }
  }
}