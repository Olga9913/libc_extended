#include "s21_math.h"

long double s21_exp(double x) {
    if (x != x) {
        return s21_NAN;
    } else if (x == s21_INF) {
        return s21_INF;
    } else if (x == -s21_INF) {
        return 0;
    }
    int flag = 0;
    if (x < 0) {
        x *= -1;
        flag = 1;
    }
    long double add_value = (long double)x, series = 1, i = 1, p = 1;
    while (s21_fabs(i / series) > 1e-100) {
        i = (i * add_value) / p;
        series += i;
        p++;
    }
    if (flag == 1) {
        if (series > s21_DBL_MAX) {
            series = 0;
        } else {
            series = 1. / series;
        }
    }
    if (series > s21_DBL_MAX) {
        return s21_INF;
    }
    return series;
}
