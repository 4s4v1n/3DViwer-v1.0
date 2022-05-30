// Copyright 2022 Savin Anton

#ifndef S21_MATRIX_OOP_H_
#define S21_MATRIX_OOP_H_

#include <cmath>
#include <iostream>

#define STANDART_MATRIX_SIZE 3

namespace s21 {

class S21Matrix {
 private:
  int rows, cols;
  double** matrix;

 public:
  // Конструкторы
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  // Основные методы
  bool eq_matrix(const S21Matrix& other);
  void sum_matrix(const S21Matrix& other);
  void sub_matrix(const S21Matrix& other);
  void mul_number(const double num);
  void mul_matrix(const S21Matrix& other);
  S21Matrix transpose();
  S21Matrix calc_complements();
  double determinant();
  S21Matrix inverse_matrix();

  // Операторы
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);
  friend S21Matrix operator*(const double num, const S21Matrix&);
  bool operator==(const S21Matrix& other);
  void operator=(const S21Matrix& other);
  void operator+=(const S21Matrix& other);
  void operator-=(const S21Matrix& other);
  void operator*=(const S21Matrix& other);
  void operator*=(const double num);
  double& operator()(const int i, const int j);

  // accessor'ы и mutator'ы
  int get_rows();
  void set_rows(const int i);
  int get_cols();
  void set_cols(const int j);
  double get_elem(const int i, const int j);
  void set_elem(const double n, const int i, const int j);
  double& get_adress(const int i, const int j);

  // Вспомогательные функции
  void print_matrix();
  void new_matrix_wo_row_col(const S21Matrix& other, int r, int c);
  void SetToIdentity();
};
}  // namespace s21
#endif  // S21_MATRIX_OOP_H_
