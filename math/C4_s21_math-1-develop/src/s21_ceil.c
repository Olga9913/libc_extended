#include "s21_math.h"

long double s21_ceil(double x) {
    long double result = (long double)x;
    if (((x - (long long)x) != 0) && (x > 0)) {
        result = (long double)((long long)(x + 1));
    } else if ((x - (long long)x) != 0) {
        result = (long double)((long long)x);
    }
    return result;
}
