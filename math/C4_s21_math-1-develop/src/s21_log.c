#include "s21_math.h"

long double s21_log(double x) {
    if (x < 0 || x == -s21_INF || x != x) {
        return s21_NAN;
    } else if (x == 0) {
        return -s21_INF;
    } else if (x == s21_INF) {
        return s21_INF;
    } else if (x == 1) {
        return 0;
    }
    double N, P, A;
    P = x;
    N = 0.0;
    while (P >= s21_e) {
        P /= s21_e;
        N++;
    }
    N += (P / s21_e);
    P = x;
    int j = 0;
    do {
        double L, R;
        A = N;
        L = (P / (s21_exp(N - 1.0)));
        R = ((N - 1.0) * s21_e);
        N = ((L + R) / s21_e);
        j++;
    } while (N != A && j < 620);
    return N;
}
