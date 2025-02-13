#ifndef __S21MATRIX_H__
#define __S21MATRIX_H__

#include <cmath>
#include <cstring>
#include <iostream>
#include <new>

#define IncorrectValuesRowsOrColumns \
  "Incorrect values for initialization, rows and cols should be >= 0 "
#define IncorrectValuesRowsOrColumnsResize \
  "Incorrect values for resize, rows and cols should be > 0 "
#define DiffSizesMatrix "Different matrix size"
#define NumColsNotEqNumRows                                                  \
  "The number of columns of the first matrix is not equal to the number of " \
  "rows of the second matrix"
#define MatrixNotSquare "The matrix is not square."
#define DetIsZero "The determinant of the matrix is zero"
#define IndexesOutOfRange "Indexes is out of range"
#define UndefinedResult \
  "The result is undefined. At least one operand is an empty matrix"

class S21Matrix {
 private:
  // Attributes
  int rows_, cols_;  // Rows and columns
  double **matrix_;  // Pointer to the memory where the matrix is allocated

  void create_matrix();
  bool check_same_size(int o_rows, int o_cols);
  bool check_lcols_vs_rrows(int o_rows);
  bool check_eq_cols_rows();
  double get_minor(int row, int col) const;
  void AriphmeticMatrix(const S21Matrix &other, int sign);

 public:
  S21Matrix();                        // default constructor
  S21Matrix(int rows, int cols);      // parameterized constructor
  S21Matrix(const S21Matrix &other);  // copy constructor
  S21Matrix(S21Matrix &&other);       // move constructor
  ~S21Matrix();                       // destructor

  // accessors
  int get_rows() const noexcept;
  int get_cols() const noexcept;
  double **get_matrix() const noexcept;

  // mutators
  void set_rows(int o_rows);
  void set_cols(int o_cols);

  // Overloads
  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  S21Matrix operator*(const S21Matrix &other);
  S21Matrix operator*(const double &value);
  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix &operator=(S21Matrix &&other);
  bool operator==(const S21Matrix &other);
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(const double &value);
  double &operator()(int row, int col);

  // Default methods
  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();
};

#endif