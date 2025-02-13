#include "s21_tests.h"

TEST_F(S21MatrixTest, EqMatrixSuccess) {
  int order = 2;
  S21Matrix matrix1(order, order);
  S21Matrix matrix2(order, order);

  for (int i = 0; i < order; i++) {
    for (int j = 0; j < order; j++) {
      matrix1(i, j) = i + j;
      matrix2(i, j) = matrix1(i, j);
    }
  }

  EXPECT_TRUE(matrix1.EqMatrix(matrix2));
  EXPECT_TRUE(matrix1 == matrix2);
}

TEST_F(S21MatrixTest, EqMatrixFailure) {
  int order = 2;
  S21Matrix matrix1(order, order);
  S21Matrix matrix2(order, order);

  for (int i = 0; i < order; i++) {
    for (int j = 0; j < order; j++) {
      matrix1(i, j) = i + j;
      matrix2(i, j) = matrix1(i, j);
    }
  }

  matrix1(0, 0) = 1;

  EXPECT_FALSE(matrix1.EqMatrix(matrix2));
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST_F(S21MatrixTest, EqMatrixSuccess1x1) {
  int order = 1;
  S21Matrix matrix1(order, order);
  S21Matrix matrix2(order, order);

  matrix1(0, 0) = 1.1;
  matrix2(0, 0) = matrix1(0, 0);

  EXPECT_TRUE(matrix1.EqMatrix(matrix2));
  EXPECT_TRUE(matrix1 == matrix2);
}

TEST_F(S21MatrixTest, EqMatrixFailureDiffRows) {
  int order = 1;
  S21Matrix matrix1(order, order);
  S21Matrix matrix2(order, order);
  matrix1.set_rows(2);

  matrix1(0, 0) = 0;
  matrix2(0, 0) = 0;

  EXPECT_FALSE(matrix1.EqMatrix(matrix2));
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST_F(S21MatrixTest, EqMatrixFailureDiffCols) {
  int order = 1;
  S21Matrix matrix1(order, order);
  S21Matrix matrix2(order, order);
  matrix1.set_cols(2);

  matrix1(0, 0) = 0;
  matrix2(0, 0) = 0;

  EXPECT_FALSE(matrix1.EqMatrix(matrix2));
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST_F(S21MatrixTest, EqMatrixFailureDiffRowsCols) {
  int order = 1;
  S21Matrix matrix1(2, order);
  S21Matrix matrix2(order, 2);

  matrix1(0, 0) = 0;
  matrix1(1, 0) = 0;
  matrix2(0, 0) = 0;
  matrix2(0, 1) = 0;

  EXPECT_FALSE(matrix1.EqMatrix(matrix2));
  EXPECT_FALSE(matrix1 == matrix2);
}

TEST_F(S21MatrixTest, EqMatrixFailureFraction6) {
  int order = 1;
  S21Matrix matrix1(order, order);
  S21Matrix matrix2(order, order);

  matrix1(0, 0) = 1.11111111;
  matrix2(0, 0) = 1.11111911;

  EXPECT_FALSE(matrix1.EqMatrix(matrix2));
  EXPECT_FALSE(matrix1 == matrix2);
}