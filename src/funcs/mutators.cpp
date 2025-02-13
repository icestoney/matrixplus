#include "../s21_matrix_oop.h"

void S21Matrix::set_rows(int o_rows) {
  if (o_rows < 0) {
    throw std::invalid_argument(IncorrectValuesRowsOrColumnsResize);
  }

  S21Matrix result(o_rows, cols_);
  if (matrix_) {
    int min_rows = std::min(o_rows, rows_);
    std::memcpy(result.matrix_[0], matrix_[0],
                min_rows * cols_ * sizeof(double));
  }

  *this = std::move(result);
}

void S21Matrix::set_cols(int o_cols) {
  if ((o_cols < 0)) {
    throw std::invalid_argument(IncorrectValuesRowsOrColumnsResize);
  }

  S21Matrix result(rows_, o_cols);
  if (matrix_) {
    int min_cols = std::min(o_cols, cols_);
    std::memcpy(result.matrix_[0], matrix_[0],
                rows_ * min_cols * sizeof(double));
  }

  *this = std::move(result);
}