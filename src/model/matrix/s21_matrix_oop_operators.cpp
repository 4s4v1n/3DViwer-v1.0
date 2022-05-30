// Copyright 2022 Savin Anton

#include "s21_matrix_oop.h"

namespace s21 {

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix A(*this);
  A.sum_matrix(other);
  return A;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix A(*this);
  A.sub_matrix(other);
  return A;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix A(*this);
  A.mul_matrix(other);
  return A;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix A(*this);
  A.mul_number(num);
  return A;
}

bool S21Matrix::operator==(const S21Matrix& other) {
  return this->eq_matrix(other);
}

void S21Matrix::operator=(const S21Matrix& other) {
  this->rows = other.rows;
  this->cols = other.cols;
  for (int i = 0; i < this->rows; i++) {
    for (int j = 0; j < this->cols; j++) {
      this->matrix[i][j] = other.matrix[i][j];
    }
  }
}

void S21Matrix::operator+=(const S21Matrix& other) { this->sum_matrix(other); }

void S21Matrix::operator-=(const S21Matrix& other) { this->sub_matrix(other); }

void S21Matrix::operator*=(const S21Matrix& other) { this->mul_matrix(other); }

void S21Matrix::operator*=(const double num) { this->mul_number(num); }

double& S21Matrix::operator()(const int i, const int j) {
  if (i < 0 || j < 0 || i > rows || j > cols) {
    throw std::invalid_argument("Index outside matrix");
  }
  return matrix[i][j];
}

S21Matrix operator*(const double num, const S21Matrix& other) {
  S21Matrix A(other);
  A.mul_number(num);
  return A;
}
}