#include "s21_matrix.h"

int check_for_single(matrix_t *A) {
  if (!A) return 0;
  if (A->columns <= 0 || A->rows <= 0) return 0;
  return 1;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = ERROR_COUNT;
  if (check_for_single(A) && check_for_single(B) && result) {
    if (A->columns == B->rows) {
      status = s21_create_matrix(A->rows, B->columns, result);
      if (status == OK) {
        for (int i = 0; i < A->rows; ++i) {
          for (int j = 0; j < B->columns; ++j) {
            result->matrix[i][j] = 0;
            for (int k = 0; k < A->columns; ++k) {
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
          }
        }
      }
    } else {
      status = ERROR_COUNT;
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}