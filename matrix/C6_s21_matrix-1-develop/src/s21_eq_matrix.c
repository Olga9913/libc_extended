#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (!A || !B || !A->matrix || !B->matrix) return FAILURE;
  if (A->columns == B->columns && A->rows == B->rows) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double compare = A->matrix[i][j] - B->matrix[i][j];
        compare = fabs(compare);
        if (compare <= pow(10, -8))
          return SUCCESS;
        else
          return FAILURE;
      }
    }
  } else {
    return FAILURE;
  }
  return SUCCESS;
}