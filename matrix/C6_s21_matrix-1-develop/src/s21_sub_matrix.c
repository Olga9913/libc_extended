#include "s21_matrix.h"

int check_for_arithmetic(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A->columns != B->columns) return 0;
  if (A->rows != B->rows) return 0;
  if (A->rows <= 0 || B->rows <= 0) return 0;
  if (A->columns <= 0 || B->columns <= 0) return 0;
  if (!A || !B || !result) return 0;
  return 1;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = ERROR_COUNT;
  int return_code = check_for_arithmetic(A, B, result);
  if (return_code) {
    status = s21_create_matrix(A->rows, A->columns, result);
    if (status == OK) {
      for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    }
  }
  return status;
}