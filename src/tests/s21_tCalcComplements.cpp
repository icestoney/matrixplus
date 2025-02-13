#include "s21_tests.h"

TEST_F(S21MatrixTest, CalcComplementsSuccess3x3) {
  int order = 3;
  S21Matrix A(order, order);
  S21Matrix expected(order, order);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 0;
  A(1, 1) = 4;
  A(1, 2) = 2;
  A(2, 0) = 5;
  A(2, 1) = 2;
  A(2, 2) = 1;

  expected(0, 0) = 0;
  expected(0, 1) = 10;
  expected(0, 2) = -20;
  expected(1, 0) = 4;
  expected(1, 1) = -14;
  expected(1, 2) = 8;
  expected(2, 0) = -8;
  expected(2, 1) = -2;
  expected(2, 2) = 4;

  S21Matrix expectedA(A);

  S21Matrix result = A.CalcComplements();

  EXPECT_EQ(result.get_rows(), expected.get_rows());
  EXPECT_EQ(result.get_cols(), expected.get_cols());
  EXPECT_EQ(A.get_rows(), expectedA.get_rows());
  EXPECT_EQ(A.get_cols(), expectedA.get_cols());

  for (int i = 0; i < expected.get_rows(); i++) {
    for (int j = 0; j < expected.get_cols(); j++) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-7);
    }
  }

  for (int i = 0; i < expectedA.get_rows(); i++) {
    for (int j = 0; j < expectedA.get_cols(); j++) {
      EXPECT_EQ(A(i, j), expectedA(i, j));
    }
  }
}

TEST_F(S21MatrixTest, CalcComplementsSuccess4x4) {
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

  expected(0, 0) = 209;
  expected(0, 1) = 238;
  expected(0, 2) = -256;
  expected(0, 3) = 80;
  expected(1, 0) = -1737;
  expected(1, 1) = 84;
  expected(1, 2) = 1662;
  expected(1, 3) = -809;
  expected(2, 0) = 3722;
  expected(2, 1) = -196;
  expected(2, 2) = -2885;
  expected(2, 3) = 1336;
  expected(3, 0) = -393;
  expected(3, 1) = 7;
  expected(3, 2) = 304;
  expected(3, 3) = -95;

  S21Matrix expectedA(A);

  S21Matrix result = A.CalcComplements();

  EXPECT_EQ(result.get_rows(), expected.get_rows());
  EXPECT_EQ(result.get_cols(), expected.get_cols());
  EXPECT_EQ(A.get_rows(), expectedA.get_rows());
  EXPECT_EQ(A.get_cols(), expectedA.get_cols());

  for (int i = 0; i < expected.get_rows(); i++) {
    for (int j = 0; j < expected.get_cols(); j++) {
      EXPECT_NEAR(result(i, j), expected(i, j), 1e-7);
    }
  }

  for (int i = 0; i < expectedA.get_rows(); i++) {
    for (int j = 0; j < expectedA.get_cols(); j++) {
      EXPECT_EQ(A(i, j), expectedA(i, j));
    }
  }
}

TEST_F(S21MatrixTest, CalcComplementsSuccess2x2) {
  int order = 2;
  S21Matrix A(order, order);
  S21Matrix expected(order, order);

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 3;
  A(1, 1) = 4;

  expected(0, 0) = 4;
  expected(0, 1) = -3;
  expected(1, 0) = -2;
  expected(1, 1) = 1;

  S21Matrix expectedA(A);

  S21Matrix result = A.CalcComplements();

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

TEST_F(S21MatrixTest, CalcComplementsFailures) {
  int order = 1;
  S21Matrix A(order, order);

  S21Matrix B(order, order + 1);
  A(0, 0) = 1;
  B(0, 0) = 2;
  B(0, 1) = 3;

  EXPECT_ANY_THROW(A.CalcComplements());
  EXPECT_ANY_THROW(B.CalcComplements());
}