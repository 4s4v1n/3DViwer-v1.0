#include <gtest/gtest.h>

#include "../matrix/s21_matrix_oop.h"

using namespace s21;

TEST(Matrixes, based_constructor) {
  S21Matrix M;
  ASSERT_EQ(M.get_rows(), STANDART_MATRIX_SIZE);
  ASSERT_EQ(M.get_cols(), STANDART_MATRIX_SIZE);
}

TEST(Matrixes, param_constructor) {
  S21Matrix M(5, 6);
  ASSERT_EQ(M.get_rows(), 5);
  ASSERT_EQ(M.get_cols(), 6);
}

TEST(Matrixes, move_construct) {
  S21Matrix A(3, 3);
  A.set_elem(-1., 0, 0);
  S21Matrix B(std::move(A));
  ASSERT_DOUBLE_EQ(B.get_elem(0, 0), -1.);
}

TEST(Matrixes, cpy_construct) {
  S21Matrix A(2, 2);
  A.set_elem(2., 0, 0);
  S21Matrix B(A);
  ASSERT_DOUBLE_EQ(B.get_elem(0, 0), 2.);
}

TEST(Matrixes, eq_matrix_wrong_size) {
  S21Matrix A(2, 3);
  S21Matrix B(3, 3);
  ASSERT_FALSE(A.eq_matrix(B));
}

TEST(Matrixes, eq_matrix_1) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  ASSERT_TRUE(A.eq_matrix(B));
}

TEST(Matrixes, eq_matrix_2) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  A.set_elem(1.5, 1, 1);
  B.set_elem(1.5, 1, 1);
  ASSERT_TRUE(A.eq_matrix(B));
}

TEST(Matrixes, eq_matrix_3) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  A.set_elem(1.5, 1, 1);
  B.set_elem(2.5, 1, 1);
  ASSERT_FALSE(A.eq_matrix(B));
}

TEST(Matrixes, sum_2) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  A.set_elem(15.5, 2, 2);
  B.set_elem(14.5, 2, 2);
  A.set_elem(1., 1, 1);
  B.set_elem(1., 1, 1);
  A.sum_matrix(B);
  ASSERT_DOUBLE_EQ(A.get_elem(2, 2), 30.);
  ASSERT_DOUBLE_EQ(A.get_elem(1, 1), 2.);
}

TEST(Matrixes, sub_2) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  A.set_elem(3.5, 1, 1);
  B.set_elem(1., 1, 1);
  B.set_elem(2., 2, 2);
  A.sub_matrix(B);
  ASSERT_DOUBLE_EQ(A.get_elem(1, 1), 2.5);
  ASSERT_DOUBLE_EQ(A.get_elem(2, 2), -2.);
}

TEST(Matrixes, mul_n_1) {
  S21Matrix A(3, 3);
  A.set_elem(8., 1, 1);
  A.set_elem(1., 2, 2);
  A.mul_number(-3.);
  ASSERT_DOUBLE_EQ(A.get_elem(1, 1), -24.);
  ASSERT_DOUBLE_EQ(A.get_elem(2, 2), -3.);
}

TEST(Matrixes, mul_matrix_2) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A.set_elem(2., 0, 0);
  A.set_elem(4., 1, 1);
  B.set_elem(-1., 0, 0);
  B.set_elem(3., 1, 0);
  A.mul_matrix(B);
  ASSERT_EQ(A.get_rows(), 2);
  ASSERT_EQ(A.get_cols(), 2);
  ASSERT_DOUBLE_EQ(A.get_elem(0, 0), -2.);
  ASSERT_DOUBLE_EQ(A.get_elem(1, 0), 12.);
}

TEST(Matrixes, mul_matrix_3) {
  S21Matrix A(2, 3);
  S21Matrix B(3, 1);
  A.set_elem(4., 0, 0);
  A.set_elem(17., 0, 2);
  A.set_elem(-290., 1, 1);
  B.set_elem(-1., 0, 0);
  B.set_elem(3., 1, 0);
  B.set_elem(1., 2, 0);
  A.mul_matrix(B);
  ASSERT_DOUBLE_EQ(A.get_elem(0, 0), 13.);
  ASSERT_DOUBLE_EQ(A.get_elem(1, 0), -870.);
}

TEST(Matrixes, det_1) {
  S21Matrix A(2, 2);
  A.set_elem(3., 0, 0);
  A.set_elem(2., 0, 1);
  A.set_elem(4., 1, 1);
  A.set_elem(-1., 1, 0);
  ASSERT_DOUBLE_EQ(A.determinant(), 14.);
}

TEST(Matrixes, det_2) {
  S21Matrix A(4, 4);
  A.set_elem(7., 0, 0);
  A.set_elem(2., 0, 1);
  A.set_elem(1., 0, 2);
  A.set_elem(3., 0, 3);
  A.set_elem(3., 1, 2);
  A.set_elem(2., 2, 0);
  A.set_elem(5., 2, 2);
  A.set_elem(1., 3, 0);
  A.set_elem(6., 3, 1);
  A.set_elem(-9., 3, 3);
  ASSERT_DOUBLE_EQ(A.determinant(), -216.);
}

TEST(Matrixes, calc_compl_1) {
  S21Matrix A(4, 4);
  A.set_elem(-1, 0, 0);
  A.set_elem(3., 0, 2);
  A.set_elem(2., 1, 1);
  A.set_elem(4., 1, 2);
  A.set_elem(7., 1, 3);
  A.set_elem(5., 2, 2);
  A.set_elem(2., 3, 0);
  A.set_elem(6., 3, 1);
  A.set_elem(9., 3, 3);
  S21Matrix B(A.calc_complements());
  ASSERT_DOUBLE_EQ(B.get_elem(0, 0), -120.);
  ASSERT_DOUBLE_EQ(B.get_elem(0, 1), 70.);
  ASSERT_DOUBLE_EQ(B.get_elem(0, 2), 0.);
  ASSERT_DOUBLE_EQ(B.get_elem(0, 3), -20.);
  ASSERT_DOUBLE_EQ(B.get_elem(1, 1), -45.);
  ASSERT_DOUBLE_EQ(B.get_elem(1, 3), 30.);
  ASSERT_DOUBLE_EQ(B.get_elem(2, 0), 72.);
  ASSERT_DOUBLE_EQ(B.get_elem(2, 1), -6.);
  ASSERT_DOUBLE_EQ(B.get_elem(2, 2), 24.);
  ASSERT_DOUBLE_EQ(B.get_elem(2, 3), -12.);
  ASSERT_DOUBLE_EQ(B.get_elem(3, 1), 35.);
  ASSERT_DOUBLE_EQ(B.get_elem(3, 3), -10.);
}

TEST(Matrixes, transpose) {
  S21Matrix A(3, 2);
  A.set_elem(-1., 0, 1);
  S21Matrix B(A.transpose());
  ASSERT_DOUBLE_EQ(B.get_elem(1, 0), -1.);
  ASSERT_EQ(B.get_rows(), 2);
  ASSERT_EQ(B.get_cols(), 3);
}

TEST(Matrixes, inverse_1) {
  S21Matrix A(3, 3);
  A.set_elem(1., 0, 0);
  A.set_elem(3., 0, 1);
  A.set_elem(2., 1, 1);
  A.set_elem(4., 1, 2);
  A.set_elem(-5., 2, 1);
  S21Matrix B(A.inverse_matrix());
  ASSERT_DOUBLE_EQ(B.get_elem(0, 0), 1.);
  ASSERT_DOUBLE_EQ(B.get_elem(0, 2), 0.6);
  ASSERT_DOUBLE_EQ(B.get_elem(1, 2), -0.2);
  ASSERT_DOUBLE_EQ(B.get_elem(2, 1), 0.25);
  ASSERT_DOUBLE_EQ(B.get_elem(2, 2), 0.1);
}

TEST(Matrixes, oper_plus) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  A.set_elem(15.5, 2, 2);
  B.set_elem(14.5, 2, 2);
  A.set_elem(1., 1, 1);
  B.set_elem(1., 1, 1);
  S21Matrix C(A + B);
  ASSERT_DOUBLE_EQ(C.get_elem(2, 2), 30.);
  ASSERT_DOUBLE_EQ(C.get_elem(1, 1), 2.);
}

TEST(Matrixes, oper_sub) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  A.set_elem(3.5, 1, 1);
  B.set_elem(1., 1, 1);
  B.set_elem(2., 2, 2);
  S21Matrix C(std::move(A - B));
  ASSERT_DOUBLE_EQ(C.get_elem(1, 1), 2.5);
  ASSERT_DOUBLE_EQ(C.get_elem(2, 2), -2.);
}

TEST(Matrixes, oper_mul_num) {
  S21Matrix A(3, 3);
  A.set_elem(8., 1, 1);
  A.set_elem(1., 2, 2);
  A = (A * -3.);
  ASSERT_DOUBLE_EQ(A.get_elem(1, 1), -24.);
  ASSERT_DOUBLE_EQ(A.get_elem(2, 2), -3.);
}

TEST(Matrixes, oper_mul_matrix) {
  S21Matrix A(2, 3);
  S21Matrix B(3, 1);
  A.set_elem(4., 0, 0);
  A.set_elem(17., 0, 2);
  A.set_elem(-290., 1, 1);
  B.set_elem(-1., 0, 0);
  B.set_elem(3., 1, 0);
  B.set_elem(1., 2, 0);
  A = (A * B);
  ASSERT_DOUBLE_EQ(A.get_elem(0, 0), 13.);
  ASSERT_DOUBLE_EQ(A.get_elem(1, 0), -870.);
}

TEST(Matrixes, oper_plus_eq) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  A.set_elem(15.5, 2, 2);
  B.set_elem(14.5, 2, 2);
  A.set_elem(1., 1, 1);
  B.set_elem(1., 1, 1);
  A += B;
  ASSERT_DOUBLE_EQ(A.get_elem(2, 2), 30.);
  ASSERT_DOUBLE_EQ(A.get_elem(1, 1), 2.);
}

TEST(Matrixes, oper_sub_eq) {
  S21Matrix A(3, 3);
  S21Matrix B(3, 3);
  A.set_elem(3.5, 1, 1);
  B.set_elem(1., 1, 1);
  B.set_elem(2., 2, 2);
  A -= B;
  ASSERT_DOUBLE_EQ(A.get_elem(1, 1), 2.5);
  ASSERT_DOUBLE_EQ(A.get_elem(2, 2), -2.);
}

TEST(Matrixes, oper_mul_num_eq) {
  S21Matrix A(3, 3);
  A.set_elem(8., 1, 1);
  A.set_elem(1., 2, 2);
  A *= -3;
  ASSERT_DOUBLE_EQ(A.get_elem(1, 1), -24.);
  ASSERT_DOUBLE_EQ(A.get_elem(2, 2), -3.);
}

TEST(Matrixes, oper_mul_eq_matrix) {
  S21Matrix A(2, 3);
  S21Matrix B(3, 1);
  A.set_elem(4., 0, 0);
  A.set_elem(17., 0, 2);
  A.set_elem(-290., 1, 1);
  B.set_elem(-1., 0, 0);
  B.set_elem(3., 1, 0);
  B.set_elem(1., 2, 0);
  A *= B;
  ASSERT_DOUBLE_EQ(A.get_elem(0, 0), 13.);
  ASSERT_DOUBLE_EQ(A.get_elem(1, 0), -870.);
}

TEST(Matrixes, oper_eq) {
  S21Matrix A(2, 2);
  A.set_elem(-12.3, 0, 0);
  S21Matrix B(A);
  ASSERT_TRUE(A == B);
}

TEST(Matrixes, bracket_val) {
  S21Matrix A(2, 3);
  A.set_elem(7.5, 1, 1);
  ASSERT_DOUBLE_EQ(A(1, 1), 7.5);
}

TEST(Matrixes, bracket_adr) {
  S21Matrix A(2, 3);
  ASSERT_EQ(A.get_adress(1, 2), A(1, 2));
}

TEST(Matrixes, num_mul) {
  S21Matrix A(2, 3);
  A(1, 1) = 6.;
  S21Matrix B(2 * A);
  ASSERT_DOUBLE_EQ(B(1, 1), 12.);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
