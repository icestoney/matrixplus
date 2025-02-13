#include "s21_tests.h"

TEST_F(S21MatrixTest, MutatorsFailureRows) {
  int order = 2;
  S21Matrix A(order, order);

  EXPECT_THROW(A.set_rows(-1), std::invalid_argument);
}

TEST_F(S21MatrixTest, MutatorsFailureCols) {
  int order = 2;
  S21Matrix A(order, order);

  EXPECT_THROW(A.set_cols(-1), std::invalid_argument);
}

TEST_F(S21MatrixTest, EmptyMatrixAndColsAfterMove) {
  int order = 2;
  S21Matrix A(order, order);
  S21Matrix temp(std::move(A));
  S21Matrix expected(order, 0);

  A.set_rows(2);
  EXPECT_EQ(A.get_rows(), expected.get_rows());
  EXPECT_EQ(A.get_cols(), expected.get_cols());
  EXPECT_EQ(A.get_matrix(), expected.get_matrix());
  EXPECT_EQ(A.get_matrix(), nullptr);
}

TEST_F(S21MatrixTest, EmptyMatrixAndRowsAfterMove) {
  int order = 2;
  S21Matrix A(order, order);
  S21Matrix temp(std::move(A));
  S21Matrix expected(0, order);

  A.set_cols(2);
  EXPECT_EQ(A.get_cols(), expected.get_cols());
  EXPECT_EQ(A.get_rows(), expected.get_rows());
  EXPECT_EQ(A.get_matrix(), expected.get_matrix());
  EXPECT_EQ(A.get_matrix(), nullptr);
}

TEST_F(S21MatrixTest, DecreaseRowsSuccess) {
  int order = 2;
  S21Matrix A(order, order);
  S21Matrix expected(order - 1, order);
  expected(0, 0) = 0;
  expected(0, 1) = 1;
  for (int i = 0; i < order; i++) {
    for (int j = 0; j < order; j++) {
      A(i, j) = i + j;
    }
  }

  A.set_rows(1);
  EXPECT_EQ(A.get_rows(), expected.get_rows());
  EXPECT_EQ(A.get_cols(), expected.get_cols());
  EXPECT_TRUE(A.EqMatrix(expected));
}

TEST_F(S21MatrixTest, DecreaseColsSuccess) {
  int order = 2;
  S21Matrix A(order, order);
  S21Matrix expected(order, order - 1);
  expected(0, 0) = 0;
  expected(1, 0) = 1;
  for (int i = 0; i < order; i++) {
    for (int j = 0; j < order; j++) {
      A(i, j) = i + j;
    }
  }

  A.set_cols(1);
  EXPECT_EQ(A.get_cols(), expected.get_cols());
  EXPECT_EQ(A.get_rows(), expected.get_rows());
  EXPECT_TRUE(A.EqMatrix(expected));
}