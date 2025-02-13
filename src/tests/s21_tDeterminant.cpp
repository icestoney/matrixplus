#include "s21_tests.h"

TEST_F(S21MatrixTest, DeterminantSuccess3x3) {
  int order = 3;
  S21Matrix A(order, order);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 4;
  A(1, 1) = 5;
  A(1, 2) = 6;
  A(2, 0) = 7;
  A(2, 1) = 8;
  A(2, 2) = 9;

  S21Matrix expectedA(A);

  double expected = 0;

  EXPECT_NEAR(expected, A.Determinant(), 1e-7);

  EXPECT_EQ(A.get_rows(), expectedA.get_rows());
  EXPECT_EQ(A.get_cols(), expectedA.get_cols());

  for (int i = 0; i < expectedA.get_rows(); i++) {
    for (int j = 0; j < expectedA.get_cols(); j++) {
      EXPECT_EQ(A(i, j), expectedA(i, j));
    }
  }
}

TEST_F(S21MatrixTest, DeterminantSuccess4x4) {
  int order = 4;
  S21Matrix A(order, order);

  A(0, 0) = 1;
  A(0, 1) = 10;
  A(0, 2) = 2;
  A(0, 3) = 3;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 8;
  A(1, 3) = 1;
  A(2, 0) = 4;
  A(2, 1) = 2;
  A(2, 2) = 7;
  A(2, 3) = 6;
  A(3, 0) = 6;
  A(3, 1) = 11;
  A(3, 2) = 32;
  A(3, 3) = 54;

  S21Matrix expectedA(A);

  double expected = 2317;

  EXPECT_NEAR(expected, A.Determinant(), 1e-7);

  EXPECT_EQ(A.get_rows(), expectedA.get_rows());
  EXPECT_EQ(A.get_cols(), expectedA.get_cols());

  for (int i = 0; i < expectedA.get_rows(); i++) {
    for (int j = 0; j < expectedA.get_cols(); j++) {
      EXPECT_EQ(A(i, j), expectedA(i, j));
    }
  }
}

TEST_F(S21MatrixTest, DeterminantSuccess2x2) {
  int order = 2;
  S21Matrix A(order, order);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  S21Matrix expectedA(A);

  double expected = -2;

  EXPECT_NEAR(expected, A.Determinant(), 1e-7);

  EXPECT_EQ(A.get_rows(), expectedA.get_rows());
  EXPECT_EQ(A.get_cols(), expectedA.get_cols());

  for (int i = 0; i < expectedA.get_rows(); i++) {
    for (int j = 0; j < expectedA.get_cols(); j++) {
      EXPECT_EQ(A(i, j), expectedA(i, j));
    }
  }
}

TEST_F(S21MatrixTest, DeterminantSuccess1x1) {
  int order = 1;
  S21Matrix A(order, order);

  A(0, 0) = 12.12;

  S21Matrix expectedA(A);

  double expected = 12.12;

  EXPECT_NEAR(expected, A.Determinant(), 1e-7);

  EXPECT_EQ(A.get_rows(), expectedA.get_rows());
  EXPECT_EQ(A.get_cols(), expectedA.get_cols());

  for (int i = 0; i < expectedA.get_rows(); i++) {
    for (int j = 0; j < expectedA.get_cols(); j++) {
      EXPECT_EQ(A(i, j), expectedA(i, j));
    }
  }
}

TEST_F(S21MatrixTest, DeterminantFailureDiffRowsCols) {
  S21Matrix A(2, 3);

  EXPECT_THROW(A.Determinant(), std::invalid_argument);
}
