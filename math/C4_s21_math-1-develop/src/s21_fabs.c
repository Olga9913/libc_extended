#include "s21_math.h"

long double s21_fabs(double x) {
    if (x != x) {
        return s21_NAN;
    } else if (x == s21_NEGZERO) {
        return 0;
    } else if (x == s21_INF || x == -s21_INF) {
        return s21_INF;
    }
    return x < 0 ? -x : x;
}
