// Copyright 2022 Savin Anton

#include "s21_matrix_oop.h"
namespace s21 {

// Матрица с вычеркнутыми i, j строкой и столбцом
void S21Matrix::new_matrix_wo_row_col(const S21Matrix& other, int r, int c) {
  int offset_row = 0;
  for (int i = 0; i < other.rows - 1; i++) {
    if (i == r) {
      offset_row = 1;
    }
    int offset_col = 0;
    for (int j = 0; j < other.cols - 1; j++) {
      if (j == c) {
        offset_col = 1;
      }
      this->matrix[i][j] = other.matrix[i + offset_row][j + offset_col];
    }
  }
}

void S21Matrix::SetToIdentity() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (i == j)
        matrix[i][j] = 1;
      else
        matrix[i][j] = 0;
    }
  }
}

void S21Matrix::print_matrix() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int S21Matrix::get_rows() { return rows; }

void S21Matrix::set_rows(const int i) { rows = i; }

void S21Matrix::set_cols(const int j) { cols = j; }

int S21Matrix::get_cols() { return cols; }

double S21Matrix::get_elem(const int i, const int j) { return matrix[i][j]; }

void S21Matrix::set_elem(const double n, const int i, const int j) {
  matrix[i][j] = n;
}

double& S21Matrix::get_adress(const int i, const int j) { return matrix[i][j]; }
}