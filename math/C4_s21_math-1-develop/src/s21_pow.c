#include "s21_math.h"

long double s21_pow(double base, double exp) {
    if (base == 1 || exp == 0 || (base == -1 && (exp == -s21_INF || exp == s21_INF))) {
        return 1;
    } else if ((s21_fabs(base) < 1 && exp == -s21_INF) || (s21_fabs(base) > 1 && exp == s21_INF) ||
            (base == -s21_INF && ((exp > 0 && (int)exp % 2 == 0) || exp == s21_INF)) ||
            (base == s21_INF && exp > 0)) {
        return s21_INF;
    } else if ((base < 0 && (int)exp - exp != 0) || (base != base && exp != exp)) {
        return s21_NAN;
    } else if ((base == 0 && exp > 0) || (s21_fabs(base) > 1 && exp == -s21_INF) ||
            (s21_fabs(base) < 1 && exp == s21_INF) ||
            (base == s21_NEGZERO && (exp > 0 && (int)exp % 2 == 0)) ||
            (base == -s21_INF && (exp < 0 && (int)exp % 2 == 0)) || (base == s21_INF && exp < 0)) {
        return 0;
    } else if ((base == s21_NEGZERO && (exp > 0 && (int)exp % 2 != 0)) ||
            (base == -s21_INF && (exp < 0 && (int)exp % 2 != 0))) {
        return s21_NEGZERO;
    } else if (base == -s21_INF && (exp > 0 && (int)exp % 2 != 0)) {
        return -s21_INF;
    }
    int flag = 0;
    if (base < 0) {
        if ((int)exp % 2 != 0) {
            flag = 1;
        }
        base = s21_fabs(base);
    }
    return flag ? -s21_exp(exp * s21_log(base)) : s21_exp(exp * s21_log(base));
}
