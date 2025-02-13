#include "../s21_matrix_oop.h"

int S21Matrix::get_cols() const noexcept { return cols_; }

int S21Matrix::get_rows() const noexcept { return rows_; }

double** S21Matrix::get_matrix() const noexcept { return matrix_; };