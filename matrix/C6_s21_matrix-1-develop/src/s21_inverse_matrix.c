#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (s21_is_valid_matrix(A) && s21_is_ptr(result)) {
    if (s21_is_square_matrix(A)) {
      double determinant = 0;
      s21_determinant(A, &determinant);
      if (determinant != 0) {
        if (A->columns == 1) {
          if (!s21_create_matrix(A->rows, A->columns, result)) {
            result->matrix[0][0] = 1 / A->matrix[0][0];
          } else {
            status = INCORRECT_MATRIX;
          }
        } else {
          matrix_t complements = {0};
          matrix_t complements_transpose = {0};
          s21_calc_complements(A, &complements);
          s21_transpose(&complements, &complements_transpose);
          s21_mult_number(&complements_transpose, 1 / determinant, result);
          s21_remove_matrix(&complements);
          s21_remove_matrix(&complements_transpose);
        }
      } else {
        status = ERROR_COUNT;
      }
    } else {
      status = ERROR_COUNT;
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}

int s21_is_valid_matrix(matrix_t *A) {
  return s21_is_ptr(A) && A->matrix != NULL && (A->columns > 0 && A->rows > 0);
}

int s21_is_ptr(const matrix_t *A) { return A != NULL; }

int s21_is_square_matrix(matrix_t *A) { return A->rows == A->columns; }