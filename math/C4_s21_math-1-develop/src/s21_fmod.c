#include "s21_math.h"

long double s21_fmod(double x, double y) {
    if (x != x || x == s21_INF || y != y || y == 0) {
        return s21_NAN;
    } else if (x == 0) {
        return 0;
    } else if (x == s21_NEGZERO || (x < 0 && s21_fabs(x) == s21_fabs(y))) {
        return s21_NEGZERO;
    }
    return x - (int)(x / y) * y;
}
