#include "s21_tests.h"

#define SUM (i + i + j)

TEST_F(S21MatrixTest, IndexOperatorOverloadSuccess) {
  double num1 = 0;
  double num2 = 9.999;
  double num3 = -0.009;
  double num4 = 9999999999;
  S21Matrix A(2, 2);
  A(0, 0) = num1;
  A(0, 1) = num2;
  A(1, 0) = num3;
  A(1, 1) = num4;
  EXPECT_EQ(A(0, 0), num1);
  EXPECT_EQ(A(0, 1), num2);
  EXPECT_EQ(A(1, 0), num3);
  EXPECT_EQ(A(1, 1), num4);
}

TEST_F(S21MatrixTest, IndexOperatorOverloadFailureOutOfRange) {
  S21Matrix A(1, 1);
  EXPECT_THROW(A(1, 0), std::out_of_range);
  EXPECT_THROW(A(0, 1), std::out_of_range);
  EXPECT_THROW(A(1, 1), std::out_of_range);
}

TEST_F(S21MatrixTest, CopyOperatorOverloadSuccess) {
  int order = 2;
  S21Matrix A(order, order);

  for (int i = 0; i < order; i++) {
    for (int j = 0; j < order; j++) {
      A(i, j) = SUM;
    }
  }

  S21Matrix expected(A);

  S21Matrix result(2, 2);
  result = A;
  for (int i = 0; i < expected.get_rows(); i++) {
    for (int j = 0; j < expected.get_cols(); j++) {
      EXPECT_EQ(A(i, j), expected(i, j));
      EXPECT_EQ(result(i, j), expected(i, j));
    }
  }
}

TEST_F(S21MatrixTest, CopyOperatorOverloadSuccessDiffRows) {
  int order = 2;
  S21Matrix A(3, order);

  for (int i = 0; i < A.get_rows(); i++) {
    for (int j = 0; j < order; j++) {
      A(i, j) = SUM;
    }
  }

  S21Matrix expected(A);

  S21Matrix result(order, order);
  result = A;
  for (int i = 0; i < expected.get_rows(); i++) {
    for (int j = 0; j < expected.get_cols(); j++) {
      EXPECT_EQ(A(i, j), expected(i, j));
      EXPECT_EQ(result(i, j), expected(i, j));
    }
  }
}

TEST_F(S21MatrixTest, CopyOperatorOverloadSuccessDiffCols) {
  int order = 2;
  S21Matrix A(order, 3);

  for (int i = 0; i < order; i++) {
    for (int j = 0; j < A.get_cols(); j++) {
      A(i, j) = SUM;
    }
  }

  S21Matrix expected(A);
  S21Matrix result(order, order);

  result = A;

  for (int i = 0; i < expected.get_rows(); i++) {
    for (int j = 0; j < expected.get_cols(); j++) {
      EXPECT_EQ(A(i, j), expected(i, j));
      EXPECT_EQ(result(i, j), expected(i, j));
    }
  }
}

TEST_F(S21MatrixTest, CopyOperatorOverloadSuccessDiffRowsCols) {
  int order = 2;
  S21Matrix A(4, 3);

  for (int i = 0; i < A.get_rows(); i++) {
    for (int j = 0; j < A.get_cols(); j++) {
      A(i, j) = SUM;
    }
  }

  S21Matrix expected(A);
  S21Matrix result(order, order);

  result = A;

  for (int i = 0; i < expected.get_rows(); i++) {
    for (int j = 0; j < expected.get_cols(); j++) {
      EXPECT_EQ(A(i, j), expected(i, j));
      EXPECT_EQ(result(i, j), expected(i, j));
    }
  }
}

TEST_F(S21MatrixTest, MoveOperatorOverloadSuccess) {
  int order = 2;
  S21Matrix A(order, order);

  for (int i = 0; i < order; i++) {
    for (int j = 0; j < order; j++) {
      A(i, j) = SUM;
    }
  }

  S21Matrix expected(A);

  S21Matrix result(3, 3);

  result = std::move(A);

  for (int i = 0; i < expected.get_rows(); i++) {
    for (int j = 0; j < expected.get_cols(); j++) {
      EXPECT_EQ(result(i, j), expected(i, j));
    }
  }

  EXPECT_EQ(A.get_rows(), 0);
  EXPECT_EQ(A.get_cols(), 0);
}

TEST_F(S21MatrixTest, MoveOperatorOverloadSuccessResultEmpty) {
  int order = 2;
  S21Matrix A(order, order);

  for (int i = 0; i < order; i++) {
    for (int j = 0; j < order; j++) {
      A(i, j) = SUM;
    }
  }

  S21Matrix expected(A);

  S21Matrix result;
  S21Matrix temp(std::move(result));

  result = std::move(A);

  for (int i = 0; i < expected.get_rows(); i++) {
    for (int j = 0; j < expected.get_cols(); j++) {
      EXPECT_EQ(result(i, j), expected(i, j));
    }
  }

  EXPECT_EQ(A.get_rows(), 0);
  EXPECT_EQ(A.get_cols(), 0);
}

TEST_F(S21MatrixTest, CopyOperatorOverloadSuccessNullMatrix) {
  int order = 2;
  S21Matrix A(order, 0);

  S21Matrix expected(A);

  S21Matrix result(2, 2);
  result = A;
  EXPECT_EQ(result.get_rows(), expected.get_rows());
  EXPECT_EQ(result.get_cols(), expected.get_cols());
  EXPECT_EQ(result.get_matrix(), nullptr);
  EXPECT_EQ(result.get_matrix(), expected.get_matrix());
}

TEST_F(S21MatrixTest, CopyOperatorOverloadSuccessSelfMatrix) {
  int order = 1;
  S21Matrix A(order, 0);
  S21Matrix expected(A);
  A = A;
  EXPECT_EQ(A.get_rows(), expected.get_rows());
  EXPECT_EQ(A.get_cols(), expected.get_cols());
  EXPECT_EQ(A.get_matrix(), nullptr);
  EXPECT_EQ(A.get_matrix(), expected.get_matrix());
}

TEST_F(S21MatrixTest, CopyOperatorOverloadSuccessNotNullMatrix) {
  int order = 1;
  S21Matrix A(order, 1);
  A(0, 0) = 5;
  S21Matrix expected(A);

  S21Matrix result(1, 0);
  result = A;
  EXPECT_EQ(result.get_rows(), expected.get_rows());
  EXPECT_EQ(result.get_cols(), expected.get_cols());
  EXPECT_EQ(result.EqMatrix(expected), true);
}

TEST_F(S21MatrixTest, BracketsOperatorOverloadFailure) {
  int order = 1;
  S21Matrix A(order, 1);
  EXPECT_ANY_THROW(A(0, -1));
}