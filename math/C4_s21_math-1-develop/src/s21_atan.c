#include "s21_math.h"

long double atan_taylor(double x) {
    long double res = x;
    long double temp = x;
    for (int i = 1; s21_fabs(temp) > s21_EPS; i++) {
        temp = -1 * temp * x * x * (2 * i - 1) / (2 * i + 1);
        res = res + temp;
        }
    return res;
}

long double s21_atan(double x) {
    long double res = x;
    if (x < 1.0 && x > -1.0) {
        res = atan_taylor(x);
    } else if (x == 1) {
        res = s21_PI / 4;
    } else if (x == -1) {
        res = - s21_PI / 4;
    } else if (x > 1) {
        res = s21_PI/2 - atan_taylor(1/x);
    } else if (x < - 1) {
        res = - s21_PI/2 - atan_taylor(1/x);
    }
    return res;
}
