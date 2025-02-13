#include "s21_tests.h"

TEST_F(S21MatrixTest, InverseMatrixSuccess3x3) {
  int order = 3;
  S21Matrix A(order, order);
  S21Matrix expected(order, order);

  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;

  expected(0, 0) = 1;
  expected(0, 1) = -1;
  expected(0, 2) = 1;
  expected(1, 0) = -38;
  expected(1, 1) = 41;
  expected(1, 2) = -34;
  expected(2, 0) = 27;
  expected(2, 1) = -29;
  expected(2, 2) = 24;

  S21Matrix expectedA(A);

  S21Matrix result = A.InverseMatrix();

  EXPECT_EQ(result.get_rows(), expected.get_rows());
  EXPECT_EQ(result.get_cols(), expected.get_cols());
  EXPECT_EQ(A.get_rows(), expectedA.get_rows());
  EXPECT_EQ(A.get_cols(), expectedA.get_cols());

  for (int i = 0; i < expected.get_rows(); i++) {
    for (int j = 0; j < expected.get_cols(); j++) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-5);
    }
  }

  for (int i = 0; i < expectedA.get_rows(); i++) {
    for (int j = 0; j < expectedA.get_cols(); j++) {
      EXPECT_EQ(A(i, j), expectedA(i, j));
    }
  }
}

TEST_F(S21MatrixTest, InverseMatrixSuccess4x4) {
  int order = 4;
  S21Matrix A(order, order);
  S21Matrix expected(order, order);

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

  expected(0, 0) = 0.090203;
  expected(0, 1) = -0.749676;
  expected(0, 2) = 1.606388;
  expected(0, 3) = -0.169616;
  expected(1, 0) = 0.102719;
  expected(1, 1) = 0.036254;
  expected(1, 2) = -0.084592;
  expected(1, 3) = 0.003021;
  expected(2, 0) = -0.110488;
  expected(2, 1) = 0.717307;
  expected(2, 2) = -1.245145;
  expected(2, 3) = 0.131204;
  expected(3, 0) = 0.034527;
  expected(3, 1) = -0.349158;
  expected(3, 2) = 0.576608;
  expected(3, 3) = -0.041001;

  S21Matrix expectedA(A);

  S21Matrix result = A.InverseMatrix();

  EXPECT_EQ(result.get_rows(), expected.get_rows());
  EXPECT_EQ(result.get_cols(), expected.get_cols());
  EXPECT_EQ(A.get_rows(), expectedA.get_rows());
  EXPECT_EQ(A.get_cols(), expectedA.get_cols());

  for (int i = 0; i < expected.get_rows(); i++) {
    for (int j = 0; j < expected.get_cols(); j++) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-5);
    }
  }

  for (int i = 0; i < expectedA.get_rows(); i++) {
    for (int j = 0; j < expectedA.get_cols(); j++) {
      EXPECT_EQ(A(i, j), expectedA(i, j));
    }
  }
}

TEST_F(S21MatrixTest, InverseMatrixFailureDeterminant0) {
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

  EXPECT_THROW(A.InverseMatrix(), std::invalid_argument);

  EXPECT_EQ(A.get_rows(), expectedA.get_rows());
  EXPECT_EQ(A.get_cols(), expectedA.get_cols());

  for (int i = 0; i < expectedA.get_rows(); i++) {
    for (int j = 0; j < expectedA.get_cols(); j++) {
      EXPECT_EQ(A(i, j), expectedA(i, j));
    }
  }
}

TEST_F(S21MatrixTest, InverseMatrixFailureDiffRowsCols) {
  S21Matrix A(2, 3);

  EXPECT_THROW(A.InverseMatrix(), std::invalid_argument);
}