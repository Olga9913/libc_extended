#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = ERROR_COUNT;
  if (check_for_single(A) && result) {
    status = s21_create_matrix(A->columns, A->rows, result);
    if (status == OK) {
      for (int i = 0; i < result->rows; ++i) {
        for (int j = 0; j < result->columns; ++j) {
          result->matrix[i][j] = A->matrix[j][i];
        }
      }
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}