#include "s21_tests.h"

TEST_F(S21MatrixTest, MulMatrixSuccess) {
  S21Matrix matrix11(3, 2);
  S21Matrix matrix2(2, 3);
  S21Matrix expectedMatrix(3, 3);

  matrix11(0, 0) = 1;
  matrix11(0, 1) = 4;
  matrix11(1, 0) = 2;
  matrix11(1, 1) = 5;
  matrix11(2, 0) = 3;
  matrix11(2, 1) = 6;

  S21Matrix matrix12(matrix11);
  S21Matrix matrix13(matrix11);

  matrix2(0, 0) = 1;
  matrix2(0, 1) = -1;
  matrix2(0, 2) = 1;
  matrix2(1, 0) = 2;
  matrix2(1, 1) = 3;
  matrix2(1, 2) = 4;
  expectedMatrix(0, 0) = 9;
  expectedMatrix(0, 1) = 11;
  expectedMatrix(0, 2) = 17;
  expectedMatrix(1, 0) = 12;
  expectedMatrix(1, 1) = 13;
  expectedMatrix(1, 2) = 22;
  expectedMatrix(2, 0) = 15;
  expectedMatrix(2, 1) = 15;
  expectedMatrix(2, 2) = 27;

  matrix11.MulMatrix(matrix2);
  matrix12 *= matrix2;
  S21Matrix matrix3 = matrix13 * matrix2;

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

TEST_F(S21MatrixTest, MulMatrixFailureDiffMatrixes) {
  S21Matrix matrix11(2, 1);
  S21Matrix matrix12(2, 1);
  S21Matrix matrix13(2, 1);
  S21Matrix matrix2(3, 2);

  int exception = 0;
  try {
    matrix11.MulMatrix(matrix2);
  } catch (std::invalid_argument& e) {
    exception++;
  }
  try {
    matrix12 *= matrix2;
  } catch (std::invalid_argument& e) {
    exception++;
  }
  try {
    S21Matrix matrix3 = matrix13 * matrix2;
  } catch (std::invalid_argument& e) {
    exception++;
  }

  EXPECT_EQ(exception, 3);
}

TEST_F(S21MatrixTest, MulMatrixEmptyMatrix) {
  S21Matrix matrix22(2, 2);
  S21Matrix matrix20(2, 0);
  S21Matrix matrix21(0, 2);
  S21Matrix matrix23(0, 0);
  S21Matrix matrix24(0, 0);

  int exception = 0;

  try {
    matrix22.MulMatrix(matrix20);
  } catch (std::invalid_argument& e) {
    exception++;
  }
  try {
    matrix20 *= matrix21;
  } catch (std::invalid_argument& e) {
    exception++;
  }
  try {
    S21Matrix matrix25 = matrix23 * matrix24;
  } catch (std::invalid_argument& e) {
    exception++;
  }

  EXPECT_EQ(exception, 3);
}