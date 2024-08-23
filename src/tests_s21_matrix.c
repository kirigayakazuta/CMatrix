#include <check.h>
#include <stdio.h>

#include "s21_matrix.h"

// Тесты для функции -- int s21_create_matrix(int rows, int columns, matrix_t
// *result);
START_TEST(s21_create_matrix_test_1) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(OK, s21_create_matrix(2, 2, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_2) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(OK, s21_create_matrix(15, 15, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_3) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(OK, s21_create_matrix(30, 30, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_4) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(OK, s21_create_matrix(1, 1, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_5) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(OK, s21_create_matrix(10, 1, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_6) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(OK, s21_create_matrix(1, 10, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_7) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(INCORRECT_MATRIX, s21_create_matrix(-5, 5, &matrix));
}
END_TEST

START_TEST(s21_create_matrix_test_8) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(INCORRECT_MATRIX, s21_create_matrix(0, 0, &matrix));
}
END_TEST

START_TEST(s21_create_matrix_test_9) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(INCORRECT_MATRIX, s21_create_matrix(5, -1, &matrix));
}
END_TEST

START_TEST(s21_create_matrix_test_10) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(INCORRECT_MATRIX, s21_create_matrix(-1, 5, &matrix));
}
END_TEST

START_TEST(s21_create_matrix_test_11) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(INCORRECT_MATRIX, s21_create_matrix(-5, -5, &matrix));
}
END_TEST

START_TEST(s21_create_matrix_test_12) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(INCORRECT_MATRIX, s21_create_matrix(-10, 10, &matrix));
}
END_TEST

START_TEST(s21_create_matrix_test_13) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(OK, s21_create_matrix(5, 10, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_14) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(OK, s21_create_matrix(10, 5, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_test_15) {
  matrix_t matrix = {NULL, 0, 0};
  ck_assert_int_eq(INCORRECT_MATRIX, s21_create_matrix(-1, 4, &matrix));
}
END_TEST

// Тесты для функции -- void s21_remove_matrix(matrix_t *A);
START_TEST(s21_remove_matrix_test_1) {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(2, 2, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(matrix.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_test_2) {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(20, 20, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(matrix.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_test_3) {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(20, 0, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(matrix.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_test_4) {
  matrix_t matrix = {NULL, 0, 0};
  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(matrix.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_test_5) {
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(1, 1, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(matrix.matrix);
}
END_TEST

// Тесты для функции -- int s21_eq_matrix(matrix_t *A, matrix_t *B);
START_TEST(s21_eq_matrix_test_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0000001;
  A.matrix[0][1] = 2.0000001;
  A.matrix[1][0] = 3.0000001;
  A.matrix[1][1] = 4.0000001;
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 4.0;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.12345671;
  A.matrix[0][1] = 2.12345672;
  A.matrix[1][0] = 3.12345673;
  A.matrix[1][1] = 4.12345674;
  B.matrix[0][0] = 1.12345675;
  B.matrix[0][1] = 2.12345676;
  B.matrix[1][0] = 3.12345677;
  B.matrix[1][1] = 4.12345679;
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.12345671;
  A.matrix[0][1] = 2.12345672;
  A.matrix[0][2] = 3.12345673;
  A.matrix[1][0] = 4.12345674;
  A.matrix[1][1] = 4.12345674;
  A.matrix[1][2] = 4.12345674;
  B.matrix[0][0] = 1.12345675;
  B.matrix[0][1] = 2.12345676;
  B.matrix[1][0] = 3.12345677;
  B.matrix[1][1] = 4.12345679;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  A.matrix[0][0] = 3454.213;
  A.matrix[0][1] = 32413.324;
  A.matrix[0][2] = 234.25;
  A.matrix[0][3] = 3124.3215;
  A.matrix[0][4] = 12.1;
  A.matrix[1][0] = 123.23;
  A.matrix[1][1] = 3456.46;
  A.matrix[1][2] = 32467.1;
  A.matrix[1][3] = -1234.56;
  A.matrix[1][4] = 1234.43;
  A.matrix[2][0] = 3454.213;
  A.matrix[2][1] = 32413.324;
  A.matrix[2][2] = 234.25;
  A.matrix[2][3] = 3124.3215;
  A.matrix[2][4] = 12.1;
  A.matrix[3][0] = 123.23;
  A.matrix[3][1] = 3456.46;
  A.matrix[3][2] = 32467.1;
  A.matrix[3][3] = 1234.56;
  A.matrix[3][4] = 1234.43;
  A.matrix[4][0] = 3454.213;
  A.matrix[4][1] = -32413.324;
  A.matrix[4][2] = 234.25;
  A.matrix[4][3] = 3124.3215;
  A.matrix[4][4] = 12.1;
  B.matrix[0][0] = 3454.213;
  B.matrix[0][1] = 32413.324;
  B.matrix[0][2] = 234.25;
  B.matrix[0][3] = 3124.3215;
  B.matrix[0][4] = 12.1;
  B.matrix[1][0] = 123.23;
  B.matrix[1][1] = 3456.46;
  B.matrix[1][2] = 32467.1;
  B.matrix[1][3] = -1234.56;
  B.matrix[1][4] = 1234.43;
  B.matrix[2][0] = 3454.213;
  B.matrix[2][1] = 32413.324;
  B.matrix[2][2] = 234.25;
  B.matrix[2][3] = 3124.3215;
  B.matrix[2][4] = 12.1;
  B.matrix[3][0] = 123.23;
  B.matrix[3][1] = 3456.46;
  B.matrix[3][2] = 32467.1;
  B.matrix[3][3] = 1234.56;
  B.matrix[3][4] = 1234.43;
  B.matrix[4][0] = 3454.213;
  B.matrix[4][1] = -32413.324;
  B.matrix[4][2] = 234.25;
  B.matrix[4][3] = 3124.3215;
  B.matrix[4][4] = 12.1;
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  A.matrix[0][0] = -3454.213;
  A.matrix[0][1] = -32413.324;
  A.matrix[0][2] = -234.25;
  A.matrix[0][3] = -3124.3215;
  A.matrix[0][4] = -12.1;
  A.matrix[1][0] = -123.23;
  A.matrix[1][1] = -3456.46;
  A.matrix[1][2] = -32467.1;
  A.matrix[1][3] = -1234.56;
  A.matrix[1][4] = 1234.43;
  A.matrix[2][0] = 3454.213;
  A.matrix[2][1] = 32413.324;
  A.matrix[2][2] = 234.25;
  A.matrix[2][3] = 3124.3215;
  A.matrix[2][4] = 12.1;
  A.matrix[3][0] = 123.23;
  A.matrix[3][1] = 3456.46;
  A.matrix[3][2] = -32467.1;
  A.matrix[3][3] = 1234.56;
  A.matrix[3][4] = 1234.43;
  A.matrix[4][0] = 3454.213;
  A.matrix[4][1] = -32413.324;
  A.matrix[4][2] = 234.25;
  A.matrix[4][3] = 3124.3215;
  A.matrix[4][4] = 12.1;
  B.matrix[0][0] = 3454.213;
  B.matrix[0][1] = 32413.324;
  B.matrix[0][2] = 234.25;
  B.matrix[0][3] = 3124.3215;
  B.matrix[0][4] = 12.1;
  B.matrix[1][0] = 123.23;
  B.matrix[1][1] = 3456.46;
  B.matrix[1][2] = 32467.1;
  B.matrix[1][3] = -1234.56;
  B.matrix[1][4] = 1234.43;
  B.matrix[2][0] = 3454.213;
  B.matrix[2][1] = 32413.324;
  B.matrix[2][2] = 234.25;
  B.matrix[2][3] = 3124.3215;
  B.matrix[2][4] = 12.1;
  B.matrix[3][0] = 123.23;
  B.matrix[3][1] = 3456.46;
  B.matrix[3][2] = 32467.1;
  B.matrix[3][3] = 1234.56;
  B.matrix[3][4] = 1234.43;
  B.matrix[4][0] = 3454.213;
  B.matrix[4][1] = -32413.324;
  B.matrix[4][2] = 234.25;
  B.matrix[4][3] = 3124.3215;
  B.matrix[4][4] = 12.1;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_6) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 234.12345679;
  B.matrix[0][0] = 234.1234567123;
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_7) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 234.12345679;
  B.matrix[0][0] = 234.1134567123;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_8) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 234.12345679;
  B.matrix[0][0] = -234.1234567123;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_9) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(1, 5, &B);
  A.matrix[0][0] = 123.2121;
  A.matrix[0][1] = 123;
  A.matrix[0][2] = 1243235;
  A.matrix[0][3] = 43532;
  A.matrix[0][4] = 2435;
  B.matrix[0][0] = 123.2121;
  B.matrix[0][1] = 123;
  B.matrix[0][2] = 1243235;
  B.matrix[0][3] = 43532;
  B.matrix[0][4] = 2435;
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_10) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(1, 5, &A);
  s21_create_matrix(1, 5, &B);
  A.matrix[0][0] = 123.2121;
  A.matrix[0][1] = 123;
  A.matrix[0][2] = 1243235;
  A.matrix[0][3] = 43532;
  A.matrix[0][4] = 2435;
  B.matrix[0][0] = 123.2121;
  B.matrix[0][1] = 123;
  B.matrix[0][2] = 1243235;
  B.matrix[0][3] = 43532;
  B.matrix[0][4] = 2;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_11) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(1, 5, &B);
  A.matrix[0][0] = 123.2121;
  A.matrix[0][1] = 123;
  A.matrix[0][2] = 1243235;
  B.matrix[0][0] = 123.2121;
  B.matrix[0][1] = 123;
  B.matrix[0][2] = 1243235;
  B.matrix[0][3] = 43532;
  B.matrix[0][4] = 2;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_12) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[0][0] = -123.2121;
  A.matrix[0][1] = -123;
  A.matrix[0][2] = -1243235;
  A.matrix[1][0] = -123.324;
  A.matrix[1][1] = -543.123;
  A.matrix[1][2] = -354.123;
  A.matrix[2][0] = -54.123;
  A.matrix[2][1] = -34.213;
  A.matrix[2][2] = -123.5;
  B.matrix[0][0] = -123.2121;
  B.matrix[0][1] = -123;
  B.matrix[0][2] = -1243235;
  B.matrix[1][0] = -123.324;
  B.matrix[1][1] = -543.123;
  B.matrix[1][2] = -354.123;
  B.matrix[2][0] = -54.123;
  B.matrix[2][1] = -34.213;
  B.matrix[2][2] = -123.5;
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_test_13) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[0][0] = -123.2121;
  A.matrix[0][1] = -123;
  A.matrix[0][2] = -1243235;
  A.matrix[1][0] = -123.324;
  A.matrix[1][1] = -543.123;
  A.matrix[1][2] = -354.123;
  A.matrix[2][0] = -54.123;
  A.matrix[2][1] = -34.213;
  A.matrix[2][2] = -123.5;
  B.matrix[0][0] = 123.2121;
  B.matrix[0][1] = 123;
  B.matrix[0][2] = 1243235;
  B.matrix[1][0] = 123.324;
  B.matrix[1][1] = 543.123;
  B.matrix[1][2] = 354.123;
  B.matrix[2][0] = 54.123;
  B.matrix[2][1] = 34.213;
  B.matrix[2][2] = 123.5;
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&A, &B));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// Тесты для функции -- int s21_sum_matrix(int rows, int columns, matrix_t
// *result);

START_TEST(s21_sum_matrix_test_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;

  ck_assert_int_eq(OK, s21_sum_matrix(&A, &B, &result));

  int count = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      if (result.matrix[i][j] == A.matrix[i][j] + B.matrix[i][j]) count++;

  ck_assert_int_eq(count, 2 * 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_test_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(2, 1, &A);
  s21_create_matrix(2, 3, &B);

  ck_assert_int_eq(CALCULATION_ERROR, s21_sum_matrix(&A, &B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_test_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(-2, 1, &A);
  s21_create_matrix(2, -3, &B);

  ck_assert_int_eq(INCORRECT_MATRIX, s21_sum_matrix(&A, &B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_test_4) {
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(INCORRECT_MATRIX, s21_sum_matrix(NULL, NULL, &result));
}
END_TEST

START_TEST(s21_sum_matrix_test_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);
  A.matrix[0][0] = 1.1;
  A.matrix[0][1] = 2.234234;
  A.matrix[1][0] = 3.23434;
  A.matrix[1][1] = 4.000001;
  A.matrix[2][0] = 34563.23434;
  A.matrix[2][1] = 54654.000001;
  B.matrix[0][0] = 1.34234;
  B.matrix[0][1] = 2834958945;
  B.matrix[1][0] = 323424234.234234234234;
  B.matrix[1][1] = 4.2423423423424;
  B.matrix[2][0] = 900323424234.234234234234;
  B.matrix[2][1] = 4.2423423423424;

  ck_assert_int_eq(OK, s21_sum_matrix(&A, &B, &result));

  int count = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++)
      if (result.matrix[i][j] == A.matrix[i][j] + B.matrix[i][j]) count++;

  ck_assert_int_eq(count, 3 * 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_test_6) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = -2.234234;
  A.matrix[1][0] = 3.23434;
  A.matrix[1][1] = 0;
  B.matrix[0][0] = -1.34234;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = -323424234.234234234234;
  B.matrix[1][1] = 4.2423423423424;

  ck_assert_int_eq(OK, s21_sum_matrix(&A, &B, &result));

  int count = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      if (result.matrix[i][j] == A.matrix[i][j] + B.matrix[i][j]) count++;

  ck_assert_int_eq(count, 2 * 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_test_7) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 3485903485903458.3453495;
  A.matrix[1][0] = 4369546945869456945645969456.456456;
  A.matrix[1][1] = 345345345345345.34535345;
  B.matrix[0][0] = -1.34234354345345;
  B.matrix[0][1] = 3453453485834545.3;
  B.matrix[1][0] = -323424234.234234234234;
  B.matrix[1][1] = -35345454.2423423423424;

  ck_assert_int_eq(OK, s21_sum_matrix(&A, &B, &result));

  int count = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      if (result.matrix[i][j] == A.matrix[i][j] + B.matrix[i][j]) count++;

  ck_assert_int_eq(count, 2 * 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_test_8) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.columns = -100;

  ck_assert_int_eq(INCORRECT_MATRIX, s21_sum_matrix(&A, &B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// Тесты для функции -- int s21_sub_matrix(int rows, int columns, matrix_t
// *result);

START_TEST(s21_sub_matrix_test_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;

  ck_assert_int_eq(OK, s21_sub_matrix(&A, &B, &result));

  int count = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      if (result.matrix[i][j] == A.matrix[i][j] - B.matrix[i][j]) count++;

  ck_assert_int_eq(count, 2 * 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_test_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(2, 1, &A);
  s21_create_matrix(2, 3, &B);

  ck_assert_int_eq(CALCULATION_ERROR, s21_sub_matrix(&A, &B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_test_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(-2, 1, &A);
  s21_create_matrix(2, -3, &B);

  ck_assert_int_eq(INCORRECT_MATRIX, s21_sub_matrix(&A, &B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_test_4) {
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(INCORRECT_MATRIX, s21_sub_matrix(NULL, NULL, &result));
}
END_TEST

START_TEST(s21_sub_matrix_test_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);
  A.matrix[0][0] = 1.1;
  A.matrix[0][1] = 2.234234;
  A.matrix[1][0] = 3.23434;
  A.matrix[1][1] = 4.000001;
  A.matrix[2][0] = 34563.23434;
  A.matrix[2][1] = 54654.000001;
  B.matrix[0][0] = 1.34234;
  B.matrix[0][1] = 2834958945;
  B.matrix[1][0] = 323424234.234234234234;
  B.matrix[1][1] = 4.2423423423424;
  B.matrix[2][0] = 900323424234.234234234234;
  B.matrix[2][1] = 4.2423423423424;

  ck_assert_int_eq(OK, s21_sub_matrix(&A, &B, &result));

  int count = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++)
      if (result.matrix[i][j] == A.matrix[i][j] - B.matrix[i][j]) count++;

  ck_assert_int_eq(count, 3 * 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_test_6) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = -2.234234;
  A.matrix[1][0] = 3.23434;
  A.matrix[1][1] = 0;
  B.matrix[0][0] = -1.34234;
  B.matrix[0][1] = 0;
  B.matrix[1][0] = -323424234.234234234234;
  B.matrix[1][1] = -4.2423423423424;

  ck_assert_int_eq(OK, s21_sub_matrix(&A, &B, &result));

  int count = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      if (result.matrix[i][j] == A.matrix[i][j] - B.matrix[i][j]) count++;

  ck_assert_int_eq(count, 2 * 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_test_7) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 3485903485903458.3453495;
  A.matrix[1][0] = 4369546945869456945645969456.456456;
  A.matrix[1][1] = 345345345345345.34535345;
  B.matrix[0][0] = -1.34234354345345;
  B.matrix[0][1] = 3453453485834545.3;
  B.matrix[1][0] = -323424234.234234234234;
  B.matrix[1][1] = -35345454.2423423423424;

  ck_assert_int_eq(OK, s21_sub_matrix(&A, &B, &result));

  int count = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      if (result.matrix[i][j] == A.matrix[i][j] - B.matrix[i][j]) count++;

  ck_assert_int_eq(count, 2 * 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

// test s21_mult_number
START_TEST(s21_mult_number_test_1) {
  matrix_t A = {NULL, 0, 0};
  double b = 9.234;
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1.1;
  A.matrix[0][1] = -2.234234;
  A.matrix[1][0] = 3.23434;
  A.matrix[1][1] = -4.000001;
  A.matrix[2][0] = 34563.23434;
  A.matrix[2][1] = 54654.000001;

  ck_assert_int_eq(OK, s21_mult_number(&A, b, &result));

  int count = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++)
      if (result.matrix[i][j] == A.matrix[i][j] * b) count++;

  ck_assert_int_eq(count, 2 * 3);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_test_2) {
  matrix_t A = {NULL, 0, 0};
  double b = -0.4878943;
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1.1;
  A.matrix[0][1] = 2.234234;
  A.matrix[1][0] = 3.23434;
  A.matrix[1][1] = 4.000001;
  A.matrix[2][0] = 34563.23434;
  A.matrix[2][1] = 54654.000001;

  ck_assert_int_eq(OK, s21_mult_number(&A, b, &result));

  int count = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++)
      if (result.matrix[i][j] == A.matrix[i][j] * b) count++;

  ck_assert_int_eq(count, 2 * 3);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_test_3) {
  matrix_t A = {NULL, 0, 0};
  double b = -999.4878943;
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1.1;
  A.matrix[0][1] = -2.234234;
  A.matrix[1][0] = -3.23434;
  A.matrix[1][1] = 0.000001;
  A.matrix[2][0] = 34563.23434;
  A.matrix[2][1] = -54654.000001;

  ck_assert_int_eq(OK, s21_mult_number(&A, b, &result));

  int count = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++)
      if (result.matrix[i][j] == A.matrix[i][j] * b) count++;

  ck_assert_int_eq(count, 2 * 3);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_test_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  double b = 0;
  ck_assert_int_eq(INCORRECT_MATRIX, s21_mult_number(&A, b, &result));
}
END_TEST

START_TEST(s21_mult_number_test_5) {
  double b = 0;
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(INCORRECT_MATRIX, s21_mult_number(NULL, b, &result));
}
END_TEST

// test s21_mult_matrix
START_TEST(s21_mult_matrix_test_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &R);
  A.matrix[0][0] = -45.5;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 64.46;
  A.matrix[1][1] = 7.7;
  A.matrix[2][0] = 31.87;
  A.matrix[2][1] = -44.454;
  B.matrix[0][0] = 78.16;
  B.matrix[0][1] = -14.11;
  B.matrix[0][2] = 44.11;
  B.matrix[1][0] = 118.23;
  B.matrix[1][1] = 58.36;
  B.matrix[1][2] = 6.97;
  R.matrix[0][0] = -3556.28;
  R.matrix[0][1] = 642.005;
  R.matrix[0][2] = -2007.005;
  R.matrix[1][0] = 5948.5646;
  R.matrix[1][1] = -460.1586;
  R.matrix[1][2] = 2896.9996;
  R.matrix[2][0] = -2764.83722;
  R.matrix[2][1] = -3044.02114;
  R.matrix[2][2] = 1095.94132;

  ck_assert_int_eq(OK, s21_mult_matrix(&A, &B, &result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &R);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 4.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 5.0;
  A.matrix[2][0] = 3.0;
  A.matrix[2][1] = 6.0;
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = -1.0;
  B.matrix[0][2] = 1.0;
  B.matrix[1][0] = 2.0;
  B.matrix[1][1] = 3.0;
  B.matrix[1][2] = 4.0;
  R.matrix[0][0] = 9.0;
  R.matrix[0][1] = 11.0;
  R.matrix[0][2] = 17.0;
  R.matrix[1][0] = 12.0;
  R.matrix[1][1] = 13.0;
  R.matrix[1][2] = 22.0;
  R.matrix[2][0] = 15.0;
  R.matrix[2][1] = 15.0;
  R.matrix[2][2] = 27.0;

  ck_assert_int_eq(OK, s21_mult_matrix(&A, &B, &result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_matrix_test_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 3, &B);
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(CALCULATION_ERROR, s21_mult_matrix(&A, &B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_test_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(INCORRECT_MATRIX, s21_mult_matrix(&A, &B, &result));
}
END_TEST

START_TEST(s21_mult_matrix_test_5) {
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(INCORRECT_MATRIX, s21_mult_matrix(NULL, NULL, &result));
}
END_TEST

// test s21_transpose
START_TEST(s21_transpose_test_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &R);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1.1;
  A.matrix[1][0] = -2.2;
  A.matrix[1][1] = 3.3;
  A.matrix[2][0] = 4.4;
  A.matrix[2][1] = -5.5;

  R.matrix[0][0] = 0;
  R.matrix[0][1] = -2.2;
  R.matrix[0][2] = 4.4;
  R.matrix[1][0] = 1.1;
  R.matrix[1][1] = 3.3;
  R.matrix[1][2] = -5.5;

  ck_assert_int_eq(OK, s21_transpose(&A, &result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_test_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &R);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1.1;
  A.matrix[1][0] = -2.2;
  A.matrix[1][1] = 3.3;
  A.matrix[2][0] = 4.4;
  A.matrix[2][1] = -5.5;

  R.matrix[0][0] = 0;
  R.matrix[0][1] = 1.1;
  R.matrix[0][2] = -2.2;
  R.matrix[1][0] = 3.3;
  R.matrix[1][1] = 4.4;
  R.matrix[1][2] = -5.5;

  ck_assert_int_eq(OK, s21_transpose(&A, &result));
  ck_assert_int_eq(FAILURE, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_test_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(3, 1, &R);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  R.matrix[0][0] = 1;
  R.matrix[1][0] = 2;
  R.matrix[2][0] = 3;

  ck_assert_int_eq(OK, s21_transpose(&A, &result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_test_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(INCORRECT_MATRIX, s21_transpose(&A, &result));
}
END_TEST

START_TEST(s21_transpose_test_5) {
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(INCORRECT_MATRIX, s21_transpose(NULL, &result));
}
END_TEST

// test s21_determinant
START_TEST(s21_determinant_test_1) {
  matrix_t A = {NULL, 0, 0};
  double result = 0;
  double my_res = 13;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 6;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 8;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 9;
  A.matrix[2][1] = 10;
  A.matrix[2][2] = 0;

  ck_assert_int_eq(OK, s21_determinant(&A, &result));
  ck_assert_int_eq(my_res, result);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_2) {
  matrix_t A = {NULL, 0, 0};
  double result = 0;
  double my_res = 9323182115255.62662111846136;
  s21_create_matrix(5, 5, &A);
  A.matrix[0][0] = -1.11;
  A.matrix[0][1] = 434.464;
  A.matrix[0][2] = -3611.4;
  A.matrix[0][3] = 99.3;
  A.matrix[0][4] = 8.7;
  A.matrix[1][0] = 2.89;
  A.matrix[1][1] = -63.23;
  A.matrix[1][2] = 0;
  A.matrix[1][3] = 87.11;
  A.matrix[1][4] = -12.8;
  A.matrix[2][0] = 994.6;
  A.matrix[2][1] = -134.15;
  A.matrix[2][2] = 58.461;
  A.matrix[2][3] = 115.466;
  A.matrix[2][4] = -161.21;
  A.matrix[3][0] = 251.1;
  A.matrix[3][1] = 356.14;
  A.matrix[3][2] = 365.44;
  A.matrix[3][3] = 34.411;
  A.matrix[3][4] = 124.416;
  A.matrix[4][0] = 15.2;
  A.matrix[4][1] = -31.8;
  A.matrix[4][2] = 8.1;
  A.matrix[4][3] = 611.61;
  A.matrix[4][4] = 0;

  ck_assert_int_eq(OK, s21_determinant(&A, &result));
  ck_assert_int_eq(my_res, result);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_3) {
  matrix_t A = {NULL, 0, 0};
  double result = 0;
  s21_create_matrix(3, 5, &A);
  ck_assert_int_eq(CALCULATION_ERROR, s21_determinant(&A, &result));
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_test_4) {
  matrix_t A = {NULL, 0, 0};
  double result = 0;
  ck_assert_int_eq(INCORRECT_MATRIX, s21_determinant(&A, &result));
}
END_TEST

START_TEST(s21_determinant_test_5) {
  double result = 0;
  ck_assert_int_eq(INCORRECT_MATRIX, s21_determinant(NULL, &result));
}
END_TEST

START_TEST(s21_determinant_test_6) {
  matrix_t A = {NULL, 0, 0};
  double result = 0;
  double my_res = 0;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  ck_assert_int_eq(OK, s21_determinant(&A, &result));
  ck_assert_int_eq(my_res, result);
  s21_remove_matrix(&A);
}
END_TEST

// test s21_calc_complements
START_TEST(s21_calc_complements_test_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &R);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  R.matrix[0][0] = 0;
  R.matrix[0][1] = 10;
  R.matrix[0][2] = -20;
  R.matrix[1][0] = 4;
  R.matrix[1][1] = -14;
  R.matrix[1][2] = 8;
  R.matrix[2][0] = -8;
  R.matrix[2][1] = -2;
  R.matrix[2][2] = 4;

  ck_assert_int_eq(OK, s21_calc_complements(&A, &result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_test_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &R);
  A.matrix[0][0] = 37.33;
  A.matrix[0][1] = -4;
  A.matrix[0][2] = -373.4;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3673.4;
  A.matrix[1][2] = -637.4;
  A.matrix[2][0] = 89.8;
  A.matrix[2][1] = -6737.5;
  A.matrix[2][2] = 0;

  R.matrix[0][0] = -4294482.5;
  R.matrix[0][1] = -57238.52;
  R.matrix[0][2] = -329871.32;
  R.matrix[1][0] = 2515782.5;
  R.matrix[1][1] = 33531.32;
  R.matrix[1][2] = 251151.675;
  R.matrix[2][0] = 1374197.16;
  R.matrix[2][1] = 23794.142;
  R.matrix[2][2] = 137128.022;

  ck_assert_int_eq(OK, s21_calc_complements(&A, &result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_test_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 5, &A);

  ck_assert_int_eq(CALCULATION_ERROR, s21_calc_complements(&A, &result));
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_test_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  ck_assert_int_eq(INCORRECT_MATRIX, s21_calc_complements(&A, &result));
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_test_5) {
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(INCORRECT_MATRIX, s21_calc_complements(NULL, &result));
}
END_TEST

// test s21_inverse_matrix
START_TEST(s21_inverse_matrix_test_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &R);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  R.matrix[0][0] = 1;
  R.matrix[0][1] = -1;
  R.matrix[0][2] = 1;
  R.matrix[1][0] = -38;
  R.matrix[1][1] = 41;
  R.matrix[1][2] = -34;
  R.matrix[2][0] = 27;
  R.matrix[2][1] = -29;
  R.matrix[2][2] = 24;

  ck_assert_int_eq(OK, s21_inverse_matrix(&A, &result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &R);
  A.matrix[0][0] = -34, 435;
  A.matrix[0][1] = 95, 45;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 6, 54;
  A.matrix[1][1] = 8, 6;
  A.matrix[1][2] = 9.45;
  A.matrix[2][0] = -78, 4;
  A.matrix[2][1] = 35, 4;
  A.matrix[2][2] = 342, 55;

  R.matrix[0][0] = -0.0069366937;
  R.matrix[0][1] = 0.0937005217;
  R.matrix[0][2] = -0.0025890934;
  R.matrix[1][0] = 0.0080437096;
  R.matrix[1][1] = 0.0335349236;
  R.matrix[1][2] = -0.0009266229;
  R.matrix[2][0] = -0.0024052396;
  R.matrix[2][1] = 0.0179383578;
  R.matrix[2][2] = 0.0024283115;

  ck_assert_int_eq(OK, s21_inverse_matrix(&A, &result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  ck_assert_int_eq(CALCULATION_ERROR, s21_inverse_matrix(&A, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_test_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  s21_create_matrix(3, 5, &A);

  ck_assert_int_eq(CALCULATION_ERROR, s21_inverse_matrix(&A, &result));
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_test_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};

  ck_assert_int_eq(INCORRECT_MATRIX, s21_inverse_matrix(&A, &result));
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_test_6) {
  matrix_t result = {NULL, 0, 0};
  ck_assert_int_eq(INCORRECT_MATRIX, s21_inverse_matrix(NULL, &result));
}
END_TEST

START_TEST(s21_inverse_matrix_test_7) {
  matrix_t A = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  matrix_t R = {NULL, 0, 0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &R);
  A.matrix[0][0] = 2;
  R.matrix[0][0] = 0.5;

  ck_assert_int_eq(OK, s21_inverse_matrix(&A, &result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &R));
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_create_matrix_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("1) s21_create_matrix");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_create_matrix_test_1);
  tcase_add_test(test_core, s21_create_matrix_test_2);
  tcase_add_test(test_core, s21_create_matrix_test_3);
  tcase_add_test(test_core, s21_create_matrix_test_4);
  tcase_add_test(test_core, s21_create_matrix_test_5);
  tcase_add_test(test_core, s21_create_matrix_test_6);
  tcase_add_test(test_core, s21_create_matrix_test_7);
  tcase_add_test(test_core, s21_create_matrix_test_8);
  tcase_add_test(test_core, s21_create_matrix_test_9);
  tcase_add_test(test_core, s21_create_matrix_test_10);
  tcase_add_test(test_core, s21_create_matrix_test_11);
  tcase_add_test(test_core, s21_create_matrix_test_12);
  tcase_add_test(test_core, s21_create_matrix_test_13);
  tcase_add_test(test_core, s21_create_matrix_test_14);
  tcase_add_test(test_core, s21_create_matrix_test_15);
  suite_add_tcase(selection, test_core);
  return selection;
}

Suite *s21_remove_matrix_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("2) s21_remove_matrix");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_remove_matrix_test_1);
  tcase_add_test(test_core, s21_remove_matrix_test_2);
  tcase_add_test(test_core, s21_remove_matrix_test_3);
  tcase_add_test(test_core, s21_remove_matrix_test_4);
  tcase_add_test(test_core, s21_remove_matrix_test_5);
  suite_add_tcase(selection, test_core);
  return selection;
}

Suite *s21_eq_matrix_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("3) s21_eq_matrix");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_eq_matrix_test_1);
  tcase_add_test(test_core, s21_eq_matrix_test_2);
  tcase_add_test(test_core, s21_eq_matrix_test_3);
  tcase_add_test(test_core, s21_eq_matrix_test_4);
  tcase_add_test(test_core, s21_eq_matrix_test_5);
  tcase_add_test(test_core, s21_eq_matrix_test_6);
  tcase_add_test(test_core, s21_eq_matrix_test_7);
  tcase_add_test(test_core, s21_eq_matrix_test_8);
  tcase_add_test(test_core, s21_eq_matrix_test_9);
  tcase_add_test(test_core, s21_eq_matrix_test_10);
  tcase_add_test(test_core, s21_eq_matrix_test_11);
  tcase_add_test(test_core, s21_eq_matrix_test_12);
  tcase_add_test(test_core, s21_eq_matrix_test_13);
  suite_add_tcase(selection, test_core);
  return selection;
}

Suite *s21_sum_matrix_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("4) s21_sum_matrix");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_sum_matrix_test_1);
  tcase_add_test(test_core, s21_sum_matrix_test_2);
  tcase_add_test(test_core, s21_sum_matrix_test_3);
  tcase_add_test(test_core, s21_sum_matrix_test_4);
  tcase_add_test(test_core, s21_sum_matrix_test_5);
  tcase_add_test(test_core, s21_sum_matrix_test_6);
  tcase_add_test(test_core, s21_sum_matrix_test_7);
  tcase_add_test(test_core, s21_sum_matrix_test_8);
  suite_add_tcase(selection, test_core);
  return selection;
}

Suite *s21_sub_matrix_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("5) s21_sub_matrix");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_sub_matrix_test_1);
  tcase_add_test(test_core, s21_sub_matrix_test_2);
  tcase_add_test(test_core, s21_sub_matrix_test_3);
  tcase_add_test(test_core, s21_sub_matrix_test_4);
  tcase_add_test(test_core, s21_sub_matrix_test_5);
  tcase_add_test(test_core, s21_sub_matrix_test_6);
  tcase_add_test(test_core, s21_sub_matrix_test_7);
  suite_add_tcase(selection, test_core);
  return selection;
}

Suite *s21_mult_number_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("6) s21_mult_number");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_mult_number_test_1);
  tcase_add_test(test_core, s21_mult_number_test_2);
  tcase_add_test(test_core, s21_mult_number_test_3);
  tcase_add_test(test_core, s21_mult_number_test_4);
  tcase_add_test(test_core, s21_mult_number_test_5);
  suite_add_tcase(selection, test_core);
  return selection;
}

Suite *s21_mult_matrix_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("7) s21_mult_matrix");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_mult_matrix_test_1);
  tcase_add_test(test_core, s21_mult_matrix_test_2);
  tcase_add_test(test_core, s21_mult_matrix_test_3);
  tcase_add_test(test_core, s21_mult_matrix_test_4);
  tcase_add_test(test_core, s21_mult_matrix_test_5);
  suite_add_tcase(selection, test_core);
  return selection;
}

Suite *s21_transpose_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("8) s21_transpose");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_transpose_test_1);
  tcase_add_test(test_core, s21_transpose_test_2);
  tcase_add_test(test_core, s21_transpose_test_3);
  tcase_add_test(test_core, s21_transpose_test_4);
  tcase_add_test(test_core, s21_transpose_test_5);
  suite_add_tcase(selection, test_core);
  return selection;
}

Suite *s21_determinant_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("9) s21_determinant");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_determinant_test_1);
  tcase_add_test(test_core, s21_determinant_test_2);
  tcase_add_test(test_core, s21_determinant_test_3);
  tcase_add_test(test_core, s21_determinant_test_4);
  tcase_add_test(test_core, s21_determinant_test_5);
  suite_add_tcase(selection, test_core);
  return selection;
}

Suite *s21_calc_complements_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("10) s21_calc_complements");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_calc_complements_test_1);
  tcase_add_test(test_core, s21_calc_complements_test_2);
  tcase_add_test(test_core, s21_calc_complements_test_3);
  tcase_add_test(test_core, s21_calc_complements_test_4);
  tcase_add_test(test_core, s21_calc_complements_test_5);
  suite_add_tcase(selection, test_core);
  return selection;
}

Suite *s21_inverse_matrix_suite() {
  Suite *selection;
  TCase *test_core;
  selection = suite_create("11) s21_inverse_matrix");
  test_core = tcase_create("core");
  tcase_add_test(test_core, s21_inverse_matrix_test_1);
  tcase_add_test(test_core, s21_inverse_matrix_test_2);
  tcase_add_test(test_core, s21_inverse_matrix_test_3);
  tcase_add_test(test_core, s21_inverse_matrix_test_4);
  tcase_add_test(test_core, s21_inverse_matrix_test_5);
  tcase_add_test(test_core, s21_inverse_matrix_test_6);
  tcase_add_test(test_core, s21_inverse_matrix_test_7);
  suite_add_tcase(selection, test_core);
  return selection;
}

void case_tests(Suite *selection, int *fail) {
  SRunner *runner = srunner_create(selection);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main() {
  int fail = 0;
  case_tests(s21_create_matrix_suite(), &fail);
  case_tests(s21_remove_matrix_suite(), &fail);
  case_tests(s21_eq_matrix_suite(), &fail);
  case_tests(s21_sum_matrix_suite(), &fail);
  case_tests(s21_sub_matrix_suite(), &fail);
  case_tests(s21_mult_number_suite(), &fail);
  case_tests(s21_mult_matrix_suite(), &fail);
  case_tests(s21_transpose_suite(), &fail);
  case_tests(s21_determinant_suite(), &fail);
  case_tests(s21_calc_complements_suite(), &fail);
  case_tests(s21_inverse_matrix_suite(), &fail);
  return 0;
}