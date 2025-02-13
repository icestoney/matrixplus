#include "../s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool res = true;
  if (!check_same_size(other.rows_, other.cols_)) {
    res = false;
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-7) res = false;
      }
    }
  }
  return res;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  AriphmeticMatrix(other, +1);
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  AriphmeticMatrix(other, -1);
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (!check_lcols_vs_rrows(other.rows_)) {
    throw std::invalid_argument(NumColsNotEqNumRows);
  }
  if (matrix_ == nullptr || other.matrix_ == nullptr) {
    throw std::invalid_argument(UndefinedResult);
  }
  S21Matrix result(rows_, other.cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      result.matrix_[i][j] = 0;
      for (int k = 0; k < cols_; k++) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = std::move(result);
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }
  return result;
}

double S21Matrix::get_minor(int row, int col) const {
  S21Matrix result(rows_ - 1, cols_ - 1);
  for (int i = 0, x = 0; i < rows_; i++) {
    if (i == row) {
      continue;
    }
    for (int j = 0, y = 0; j < cols_; j++) {
      if (j == col) {
        continue;
      }
      result(x, y) = matrix_[i][j];
      y++;
    }
    x++;
  }

  return result.Determinant();
}

S21Matrix S21Matrix::CalcComplements() {
  if (!check_eq_cols_rows()) {
    throw std::invalid_argument(MatrixNotSquare);
  }
  S21Matrix result(rows_, cols_);

  if (rows_ == 1) {
    throw std::invalid_argument("Matrix is 1x1, cannot calculate complements");
  } else if (rows_ == 2) {
    result.matrix_[0][0] = matrix_[1][1];
    result.matrix_[1][1] = matrix_[0][0];
    result.matrix_[0][1] = -matrix_[1][0];
    result.matrix_[1][0] = -matrix_[0][1];
    /*
      a b
      c d

      M(1,1) = d
      M(1,2) = c
      M(2,1) = b
      M(2,2) = a

      C(1,1) = (-1)^(1+1) * M(1,1) = 1 * d = d
      C(1,2) = (-1)^(1+2) * M(1,2) = -1 * c = -c
      C(2,1) = (-1)^(2+1) * M(2,1) = -1 * b = -b
      C(2,2) = (-1)^(2+2) * M(2,2) = 1 * a = a

       d -c
      -b  a
    */
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if ((i + j) % 2 == 0) {
          result.matrix_[i][j] = get_minor(i, j);
        } else {
          result.matrix_[i][j] = -(get_minor(i, j));
        }
      }
    }
  }

  return result;
}

double S21Matrix::Determinant() {
  if (!check_eq_cols_rows()) {
    throw std::invalid_argument(MatrixNotSquare);
  }

  double result = 0.0;

  if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - (matrix_[1][0] * matrix_[0][1]);
  } else {
    result += 1.0;
    S21Matrix B(*this);
    for (int i = 0; i < B.rows_; ++i) {
      double mx_row = fabs(B(i, i));
      int idx = i;
      for (int j = i + 1; j < B.rows_; ++j)
        if (mx_row < fabs(B(i, j))) mx_row = fabs(B(i, idx = j));
      if (idx != i) {
        for (int j = i; j < B.rows_; ++j) {
          double t = B(j, i);
          B(j, i) = B(j, idx);
          B(j, idx) = t;
        }
        result = -(result);
      }
      if (mx_row) {
        for (int k = i + 1; k < B.rows_; ++k) {
          double t = B(k, i) / B(i, i);
          for (int j = i; j < B.rows_; ++j) B(k, j) -= B(i, j) * t;
        }
      } else
        result *= 0;
    }
    for (int i = 0; i < B.rows_; ++i) result *= B(i, i);
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  S21Matrix result(rows_, cols_);

  double determinant = Determinant();

  if (determinant == 0.0) {
    throw std::invalid_argument(DetIsZero);
  } else {
    S21Matrix calc_matrix = CalcComplements();
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        // matrix[i][j] = calc * (1/det)
        result.matrix_[j][i] = calc_matrix.matrix_[i][j] / determinant;
      }
    }
  }
  return result;
}
