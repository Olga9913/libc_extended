#include "s21_matrix.h"

double determinant_recursive(matrix_t *A);

int s21_determinant(matrix_t *A, double *result) {
  int status = OK;
  if (check_for_single(A) && A->columns == A->rows && result) {
    *result = determinant_recursive(A);
  } else if (A->columns != A->rows || !result) {
    status = ERROR_COUNT;
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}

double determinant_recursive(matrix_t *A) {
  if (A->columns == 1) return A->matrix[0][0];
  if (A->columns == 2)
    return (A->matrix[0][0] * A->matrix[1][1] -
            A->matrix[0][1] * A->matrix[1][0]);
  double det = 0;
  matrix_t temp;
  s21_create_matrix((A->columns - 1), (A->columns - 1), &temp);
  for (int k = 0; k < A->columns; k++) {
    int i = 0, j = 0;
    for (int row = 1; row < A->columns; row++) {
      for (int col = 0; col < A->columns; col++) {
        if (col != k) {
          temp.matrix[i][j] = A->matrix[row][col];
          j++;
          if (j == A->columns - 1) {
            i++;
            j = 0;
          }
        }
      }
    }
    int sign = (k % 2 == 0) ? 1 : -1;
    det += sign * A->matrix[0][k] * determinant_recursive(&temp);
  }
  s21_remove_matrix(&temp);
  return det;
}