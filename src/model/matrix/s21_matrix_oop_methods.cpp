// Copyright 2022 Savin Anton

#include "s21_matrix_oop.h"

namespace s21 {

// Проверка равенства текущей и пришедшей матриц
bool S21Matrix::eq_matrix(const S21Matrix& other) {
  bool result = true;
  if (this->rows != other.rows || this->cols != other.rows) {
    result = false;
  }
  if (result) {
    for (int i = 0; i < this->rows && result; i++) {
      for (int j = 0; j < this->cols && result; j++) {
        if (fabs(this->matrix[i][j] - other.matrix[i][j]) > 1e-7) {
          result = false;
        }
      }
    }
  }
  return result;
}

// Сумма
void S21Matrix::sum_matrix(const S21Matrix& other) {
  if (this->rows != other.rows || this->cols != other.cols) {
    throw std::invalid_argument("Sizes of matrixes are not the same");
  } else {
    for (int i = 0; i < this->rows; i++) {
      for (int j = 0; j < this->cols; j++) {
        this->matrix[i][j] += other.matrix[i][j];
      }
    }
  }
}

// Разность
void S21Matrix::sub_matrix(const S21Matrix& other) {
  if (this->rows != other.rows || this->cols != other.cols) {
    throw std::invalid_argument("Sizes of matrixes are not the same");
  } else {
    for (int i = 0; i < this->rows; i++) {
      for (int j = 0; j < this->cols; j++) {
        this->matrix[i][j] -= other.matrix[i][j];
      }
    }
  }
}

// Умножение матрицы на число
void S21Matrix::mul_number(const double num) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i][j] *= num;
    }
  }
}

// Матрица алгебраических дополнений
S21Matrix S21Matrix::calc_complements() {
  if (rows == cols && rows > 1) {
    S21Matrix A(*this);
    S21Matrix B(rows - 1, cols - 1);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        B.new_matrix_wo_row_col(*this, i, j);
        A.matrix[i][j] = B.determinant() * pow(-1, i + j + 2);
      }
    }
    return A;
  } else {
    throw std::invalid_argument("Matrix is not square");
  }
}

// Транспонирование
S21Matrix S21Matrix::transpose() {
  S21Matrix A(cols, rows);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.cols; j++) {
      A.matrix[i][j] = matrix[j][i];
    }
  }
  return A;
}

// Умножение матрицы на матрицу
void S21Matrix::mul_matrix(const S21Matrix& other) {
  if (this->cols != other.rows) {
    throw std::invalid_argument("Rows from 1st M != cols from 2nd M");
  } else {
    S21Matrix A(this->rows, other.cols);
    for (int i = 0; i < this->rows; i++) {
      for (int j = 0; j < other.cols; j++) {
        for (int k = 0; k < this->cols; k++) {
          A.matrix[i][j] += this->matrix[i][k] * other.matrix[k][j];
        }
      }
    }
    this->~S21Matrix();
    this->matrix = new double*[A.rows];
    for (int i = 0; i < A.rows; i++) {
      this->matrix[i] = new double[A.cols];
    }
    *this = A;
  }
}

// Определитель
double S21Matrix::determinant() {
  double det = 0.;
  if (rows == cols) {
    if (rows == 1) {
      det = matrix[0][0];
    } else if (rows == 2) {
      det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
      int degree = 1;
      S21Matrix A(rows - 1, cols - 1);
      for (int i = 0; i < rows; i++) {
        A.new_matrix_wo_row_col(*this, 0, i);
        det += degree * this->matrix[0][i] * A.determinant();
        degree = -degree;
      }
    }
  } else {
    throw std::invalid_argument("Matrix is not square");
  }
  return det;
}

// Обратная матрица
S21Matrix S21Matrix::inverse_matrix() {
  S21Matrix A(rows, cols);
  if (rows == cols) {
    if (rows == 1) {
      if (matrix[0][0] == 0.) {
        throw std::invalid_argument("Determinant is equal 0");
      } else {
        A.matrix[0][0] = 1. / matrix[0][0];
      }
    } else {
      double det = this->determinant();
      if (det == 0.) {
        throw std::invalid_argument("Determinant is equal 0");
      } else {
        S21Matrix B(this->calc_complements());
        B = B.transpose();
        B *= 1. / det;
        A = B;
      }
    }
  } else {
    throw std::invalid_argument("Matrix is not square");
  }
  return A;
}
}