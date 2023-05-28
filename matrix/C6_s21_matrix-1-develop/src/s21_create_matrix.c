#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = OK;
  if (rows > 0 && columns > 0 && result) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = calloc(rows, sizeof(double *));
    if (!result->matrix) return INCORRECT_MATRIX;
    for (int i = 0; i < rows; ++i) {
      result->matrix[i] = calloc(columns, sizeof(double));
      if (!result->matrix[i]) return INCORRECT_MATRIX;
    }
  } else {
    return INCORRECT_MATRIX;
  }
  return status;
}