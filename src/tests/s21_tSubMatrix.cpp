#include "s21_tests.h"

#define SUM1 (i + i + j)
#define SUM2 (i - j - j)

TEST_F(S21MatrixTest, SubMatrixSuccess) {
  int order = 2;
  S21Matrix matrix11(order, order);
  S21Matrix matrix12(order, order);
  S21Matrix matrix13(order, order);
  S21Matrix matrix2(order, order);
  S21Matrix expectedMatrix(order, order);

  for (int i = 0; i < order; i++) {
    for (int j = 0; j < order; j++) {
      matrix11(i, j) = SUM1;
      matrix12(i, j) = SUM1;
      matrix13(i, j) = SUM1;
      matrix2(i, j) = SUM2;
      expectedMatrix(i, j) = SUM1 - SUM2;
    }
  }

  matrix11.SubMatrix(matrix2);
  matrix12 -= matrix2;
  S21Matrix matrix3 = matrix13 - matrix2;

  EXPECT_EQ(matrix11.get_rows(), expectedMatrix.get_rows());
  EXPECT_EQ(matrix11.get_cols(), expectedMatrix.get_cols());
  EXPECT_EQ(matrix12.get_rows(), expectedMatrix.get_rows());
  EXPECT_EQ(matrix12.get_cols(), expectedMatrix.get_cols());
  EXPECT_EQ(matrix3.get_rows(), expectedMatrix.get_rows());
  EXPECT_EQ(matrix3.get_cols(), expectedMatrix.get_cols());

  for (int i = 0; i < expectedMatrix.get_rows(); i++) {
    for (int j = 0; j < expectedMatrix.get_cols(); j++) {
      EXPECT_EQ(matrix11(i, j), expectedMatrix(i, j));
      EXPECT_EQ(matrix12(i, j), expectedMatrix(i, j));
      EXPECT_EQ(matrix3(i, j), expectedMatrix(i, j));
    }
  }
}