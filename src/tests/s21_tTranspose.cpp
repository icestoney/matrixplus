#include "s21_tests.h"

#define SUM (i + i + j)

TEST_F(S21MatrixTest, TransposeSuccess) {
  int rows = 3;
  int cols = 2;
  S21Matrix A(rows, cols);
  S21Matrix expected(cols, rows);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      A(i, j) = expected(j, i) = SUM;
    }
  }

  S21Matrix expectedA(A);

  S21Matrix result = A.Transpose();

  EXPECT_EQ(result.get_rows(), expected.get_rows());
  EXPECT_EQ(result.get_cols(), expected.get_cols());
  EXPECT_EQ(A.get_rows(), expectedA.get_rows());
  EXPECT_EQ(A.get_cols(), expectedA.get_cols());

  for (int i = 0; i < expected.get_rows(); i++) {
    for (int j = 0; j < expected.get_cols(); j++) {
      EXPECT_EQ(result(i, j), expected(i, j));
      EXPECT_EQ(A(j, i), expectedA(j, i));
    }
  }
}

TEST_F(S21MatrixTest, TransposeSuccessEqualRowsCols) {
  int order = 2;
  S21Matrix A(order, order);
  S21Matrix expected(order, order);

  for (int i = 0; i < A.get_rows(); i++) {
    for (int j = 0; j < A.get_cols(); j++) {
      A(i, j) = expected(j, i) = SUM;
    }
  }

  S21Matrix expectedA(A);

  S21Matrix result = A.Transpose();

  EXPECT_EQ(A.get_rows(), expected.get_rows());
  EXPECT_EQ(A.get_cols(), expected.get_cols());
  EXPECT_EQ(A.get_rows(), expectedA.get_rows());
  EXPECT_EQ(A.get_cols(), expectedA.get_cols());

  for (int i = 0; i < expected.get_rows(); i++) {
    for (int j = 0; j < expected.get_cols(); j++) {
      EXPECT_EQ(result(i, j), expected(i, j));
      EXPECT_EQ(A(j, i), expectedA(j, i));
    }
  }
}