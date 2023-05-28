#include "s21_math.h"

long double s21_cos(double x) {
    long double res;

    if (x != x || x == s21_INF || x == -s21_INF)
        return s21_NAN;

    // int sign = 1;
    x = s21_fmod(x, 2 * s21_PI);
    while (x > s21_PI) {
        x = x - 2 * s21_PI;
    }
    while (x < -s21_PI) {
        x = x + 2 * s21_PI;
    }
    res = 1;
    int z_flag = 0;
    if (x == s21_PI/2 || x == -s21_PI/2) {
        z_flag = 1;
        res = 0;
    }
    int k = 1;
    long double temp = 1;
    while (s21_fabs(temp) > s21_EPS && z_flag == 0) {
        temp = (-temp * x * x) / ((2.0 * k - 1) * (2.0 * k));
        res = res + temp;
        k++;
    }
    return res;
}
