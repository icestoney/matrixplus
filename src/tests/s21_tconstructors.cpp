#include "s21_tests.h"

TEST_F(S21MatrixTest, BasicConstructor) {
  S21Matrix matrix;

  int expectedRows = 3;
  int expectedCols = 3;

  for (int i = 0; i < expectedRows; i++) {
    for (int j = 0; j < expectedCols; j++) {
      matrix(i, j) = 9.9;
      EXPECT_EQ(matrix(i, j), 9.9);
    }
  }

  EXPECT_EQ(matrix.get_rows(), expectedRows);
  EXPECT_EQ(matrix.get_cols(), expectedCols);
}

TEST_F(S21MatrixTest, ParametrizedConstructorSuccess) {
  int expectedRows = 2;
  int expectedCols = 4;

  S21Matrix matrix(expectedRows, expectedCols);

  for (int i = 0; i < expectedRows; i++) {
    for (int j = 0; j < expectedCols; j++) {
      matrix(i, j) = 9.9;
      EXPECT_EQ(matrix(i, j), 9.9);
    }
  }

  EXPECT_EQ(matrix.get_rows(), expectedRows);
  EXPECT_EQ(matrix.get_cols(), expectedCols);
}

TEST_F(S21MatrixTest, ParametrizedConstructorFailure) {
  int exception = 0;

  try {
    S21Matrix matrix(-1, 4);
  } catch (std::bad_array_new_length& e) {
    exception += 1;
  }

  try {
    S21Matrix matrix(-1, -1);
  } catch (std::bad_array_new_length& e) {
    exception += 1;
  }

  try {
    S21Matrix matrix(1, -1);
  } catch (std::bad_array_new_length& e) {
    exception += 1;
  }

  EXPECT_EQ(exception, 3);
}

TEST_F(S21MatrixTest, CopyConstructorSuccess) {
  S21Matrix expectedMatrix(2, 2);
  expectedMatrix(0, 0) = 1.1;
  expectedMatrix(0, 1) = 2.2;
  expectedMatrix(1, 0) = 3.3;
  expectedMatrix(1, 1) = 4.4;

  S21Matrix matrix(expectedMatrix.get_rows(), expectedMatrix.get_cols());
  matrix(0, 0) = expectedMatrix(0, 0);
  matrix(0, 1) = expectedMatrix(0, 1);
  matrix(1, 0) = expectedMatrix(1, 0);
  matrix(1, 1) = expectedMatrix(1, 1);
  S21Matrix copyMatrix(matrix);

  for (int i = 0; i < expectedMatrix.get_rows(); i++) {
    for (int j = 0; j < expectedMatrix.get_cols(); j++) {
      EXPECT_EQ(matrix(i, j), expectedMatrix(i, j));
      EXPECT_EQ(copyMatrix(i, j), expectedMatrix(i, j));
    }
  }

  EXPECT_EQ(matrix.get_rows(), expectedMatrix.get_rows());
  EXPECT_EQ(matrix.get_cols(), expectedMatrix.get_cols());
  EXPECT_EQ(copyMatrix.get_rows(), expectedMatrix.get_rows());
  EXPECT_EQ(copyMatrix.get_cols(), expectedMatrix.get_cols());
}

TEST_F(S21MatrixTest, MoveConstructorSuccess) {
  S21Matrix expectedMatrix(2, 2);
  expectedMatrix(0, 0) = 1.1;
  expectedMatrix(0, 1) = 2.2;
  expectedMatrix(1, 0) = 3.3;
  expectedMatrix(1, 1) = 4.4;

  S21Matrix matrix(expectedMatrix.get_rows(), expectedMatrix.get_cols());
  matrix(0, 0) = expectedMatrix(0, 0);
  matrix(0, 1) = expectedMatrix(0, 1);
  matrix(1, 0) = expectedMatrix(1, 0);
  matrix(1, 1) = expectedMatrix(1, 1);
  S21Matrix moveMatrix(std::move(matrix));

  for (int i = 0; i < expectedMatrix.get_rows(); i++) {
    for (int j = 0; j < expectedMatrix.get_cols(); j++) {
      EXPECT_EQ(moveMatrix(i, j), expectedMatrix(i, j));
    }
  }

  EXPECT_EQ(matrix.get_rows(), 0);
  EXPECT_EQ(matrix.get_cols(), 0);
  EXPECT_EQ(moveMatrix.get_rows(), expectedMatrix.get_rows());
  EXPECT_EQ(moveMatrix.get_cols(), expectedMatrix.get_cols());
}