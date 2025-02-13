#include "s21_tests.h"

#define SUM (i + j)

TEST_F(S21MatrixTest, MulNumberSuccess) {
  int order = 2;
  S21Matrix matrix1(order, order);
  S21Matrix matrix2(order, order);
  S21Matrix matrixN(order, order);
  S21Matrix expectedMatrix(order, order);
  double number = 2.2;

  for (int i = 0; i < order; i++) {
    for (int j = 0; j < order; j++) {
      matrix1(i, j) = SUM;
      matrix2(i, j) = SUM;
      matrixN(i, j) = SUM;
      expectedMatrix(i, j) = SUM * number;
    }
  }

  matrix1.MulNumber(number);
  matrix2 *= number;
  S21Matrix matrix3 = matrixN * number;

  EXPECT_EQ(matrix1.get_rows(), expectedMatrix.get_rows());
  EXPECT_EQ(matrix1.get_cols(), expectedMatrix.get_cols());
  EXPECT_EQ(matrix2.get_rows(), expectedMatrix.get_rows());
  EXPECT_EQ(matrix2.get_cols(), expectedMatrix.get_cols());
  EXPECT_EQ(matrix3.get_rows(), expectedMatrix.get_rows());
  EXPECT_EQ(matrix3.get_cols(), expectedMatrix.get_cols());

  for (int i = 0; i < expectedMatrix.get_rows(); i++) {
    for (int j = 0; j < expectedMatrix.get_cols(); j++) {
      EXPECT_EQ(matrix1(i, j), expectedMatrix(i, j));
      EXPECT_EQ(matrix2(i, j), expectedMatrix(i, j));
      EXPECT_EQ(matrix3(i, j), expectedMatrix(i, j));
    }
  }
}