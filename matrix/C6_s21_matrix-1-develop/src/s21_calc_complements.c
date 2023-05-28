#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (check_for_single(A) && A->columns == A->rows && result) {
    status = s21_create_matrix(A->columns, A->columns, result);
    if (status == OK) {
      matrix_t submatrix;
      s21_create_matrix((A->columns - 1), (A->columns - 1), &submatrix);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          int sign = ((i + j) % 2 == 0) ? 1 : -1;
          int sub_i = 0, sub_j = 0;
          for (int row = 0; row < A->rows; row++) {
            if (row == i) continue;
            sub_j = 0;
            for (int col = 0; col < A->columns; col++) {
              if (col == j) continue;
              submatrix.matrix[sub_i][sub_j] = A->matrix[row][col];
              sub_j++;
            }
            sub_i++;
          }
          double det;
          status = s21_determinant(&submatrix, &det);
          if (status == OK) {
            result->matrix[i][j] = sign * det;
          }
        }
      }
      s21_remove_matrix(&submatrix);
    }
  } else if (A->columns != A->rows || !result) {
    status = ERROR_COUNT;
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}