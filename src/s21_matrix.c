#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = OK;

  if (rows > 0 && columns > 0) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix) {
      int i = 0;
      for (; i < rows && status == OK; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (!result->matrix[i]) {
          for (int j = 0; j < i; j++) free(result->matrix[j]);
          free(result->matrix);
          status = ALLOC_ERROR;
        }
      }
    } else
      status = ALLOC_ERROR;
  } else
    status = INCORRECT_MATRIX;

  return status;
}

void s21_remove_matrix(matrix_t *A) {
  if (A && A->matrix) {
    for (int i = 0; i < A->rows; i++)
      if (A->matrix[i]) free(A->matrix[i]);
    free(A->matrix);

    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}

int two_matrix_condition(matrix_t *A, matrix_t *B, int mode) {
  int status = OK;

  if (!(A && B))
    status = INCORRECT_MATRIX;
  else if (!(A->matrix && B->matrix))
    status = INCORRECT_MATRIX;
  else if (!(A->rows > 0 && A->columns > 0 && B->rows > 0 && B->columns > 0))
    status = INCORRECT_MATRIX;
  else if (mode == SUM_SUB_EQ_MODE &&
           !(A->columns == B->columns && A->rows == B->rows))
    status = CALCULATION_ERROR;
  else if (mode == MULT_MODE && !(A->columns == B->rows))
    status = CALCULATION_ERROR;

  return status;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = SUCCESS;

  if (two_matrix_condition(A, B, SUM_SUB_EQ_MODE) == OK) {
    int rows = A->rows;
    int columns = A->columns;

    for (int i = 0; i < rows && status; i++) {
      for (int j = 0; j < columns && status; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= EPSILON)
          status = FAILURE;
      }
    }
  } else
    status = FAILURE;

  return status;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = two_matrix_condition(A, B, SUM_SUB_EQ_MODE);

  if (status == OK) {
    int rows = A->rows;
    int columns = A->columns;
    status = s21_create_matrix(rows, columns, result);

    if (status == OK)
      for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
  }

  return status;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = two_matrix_condition(A, B, SUM_SUB_EQ_MODE);

  if (status == OK) {
    int rows = A->rows;
    int columns = A->columns;
    status = s21_create_matrix(rows, columns, result);

    if (status == OK)
      for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
  }

  return status;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = OK;

  if (A && A->matrix && A->rows > 0 && A->columns > 0) {
    int rows = A->rows;
    int columns = A->columns;
    status = s21_create_matrix(rows, columns, result);

    if (status == OK)
      for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
          result->matrix[i][j] = A->matrix[i][j] * number;
  } else
    status = INCORRECT_MATRIX;

  return status;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = two_matrix_condition(A, B, MULT_MODE);
  if (status == OK) {
    status = s21_create_matrix(A->rows, B->columns, result);
    if (status == OK) {
      for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < B->columns; j++)
          for (int k = 0; k < B->rows; k++)
            result->matrix[i][j] += B->matrix[k][j] * A->matrix[i][k];
    }
  }

  return status;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = OK;

  if (A && A->matrix && A->rows > 0 && A->columns > 0) {
    int rows = A->columns;
    int columns = A->rows;
    status = s21_create_matrix(rows, columns, result);

    if (status == OK) {
      for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
          result->matrix[i][j] = A->matrix[j][i];
    }
  } else
    status = INCORRECT_MATRIX;

  return status;
}

double calc_minor(double **matrix, int dimension, int cut_row, int cut_colown) {
  double res = 0;
  matrix_t minor = {NULL, 0, 0};
  if (dimension > 1) {
    if (s21_create_matrix(dimension - 1, dimension - 1, &minor) == OK) {
      for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
          if (i == cut_row || j == cut_colown)
            continue;
          else if (i > cut_row && j > cut_colown)
            minor.matrix[i - 1][j - 1] = matrix[i][j];
          else if (i > cut_row)
            minor.matrix[i - 1][j] = matrix[i][j];
          else if (j > cut_colown)
            minor.matrix[i][j - 1] = matrix[i][j];
          else
            minor.matrix[i][j] = matrix[i][j];
        }
      }

      res = calc_determinant(minor.matrix, dimension - 1);
      s21_remove_matrix(&minor);
    }
  } else if (dimension == 1)
    res = 1;

  return res;
}

double calc_determinant(double **matrix, int dimension) {
  double res = 0;
  if (dimension == 1)
    res = matrix[0][0];
  else {
    for (int i = 0; i < dimension; i++) {
      int sign = i % 2 == 0 ? 1 : -1;
      res += matrix[0][i] * sign * calc_minor(matrix, dimension, 0, i);
    }
  }
  return res;
}

int s21_determinant(matrix_t *A, double *result) {
  *result = 0;
  int status = OK;

  if (A && A->matrix && A->rows > 0 && A->columns > 0) {
    if (A->columns == A->rows) {
      int dimension = A->columns;
      *result = calc_determinant(A->matrix, dimension);
    } else
      status = CALCULATION_ERROR;
  } else
    status = INCORRECT_MATRIX;

  return status;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = OK;

  if (A && A->matrix && A->rows > 0 && A->columns > 0) {
    if (A->rows == A->columns) {
      int dimension = A->rows;
      status = s21_create_matrix(dimension, dimension, result);
      if (status == OK) {
        for (int i = 0; i < dimension; i++) {
          for (int j = 0; j < dimension; j++) {
            int sign = (i + j) % 2 == 0 ? 1 : -1;
            result->matrix[i][j] =
                sign * calc_minor(A->matrix, dimension, i, j);
          }
        }
      }
    } else
      status = CALCULATION_ERROR;
  } else
    status = INCORRECT_MATRIX;

  return status;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = OK;

  if (A && A->matrix && A->rows > 0 && A->columns > 0) {
    if (A->rows == A->columns) {
      double det_A = 0;
      status = s21_determinant(A, &det_A);
      if (det_A != 0) {
        matrix_t buffer_1 = {NULL, 0, 0};
        matrix_t buffer_2 = {NULL, 0, 0};
        if (status == OK) status = s21_calc_complements(A, &buffer_1);
        if (status == OK) status = s21_transpose(&buffer_1, &buffer_2);
        if (status == OK)
          status = s21_mult_number(&buffer_2, 1 / det_A, result);
        s21_remove_matrix(&buffer_1);
        s21_remove_matrix(&buffer_2);
      } else
        status = CALCULATION_ERROR;
    } else
      status = CALCULATION_ERROR;
  } else
    status = INCORRECT_MATRIX;

  return status;
}