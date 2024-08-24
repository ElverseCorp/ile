/* Include specific libraries */
#include <solver/qmath.h>

/* Private functions and variables  */

/* Local static variable  */
static qmath_roots_t roots = {NAN, NAN};

static qmath_value_t discriminant(qmath_factors_t factors) {
    return (factors.b * factors.b) - (4 * factors.a * factors.c);
}

/* for the best accuracy I'll use two fomulas */

/*
    x = (-b +- sqrt(D)) / 2a
    x = 2c / (-b -+ sqrt(D))
*/

/* Unsafe functions */
static void get_x12_pos(qmath_factors_t factors, qmath_value_t D) {
    qmath_value_t sqrtD = sqrtl(D);
    roots.x1 = (-factors.b - sqrtD) / (2 * factors.a);
    roots.x2 = (2 * factors.c) / (-factors.b + sqrtD);
}

static void get_x12_neg(qmath_factors_t factors, qmath_value_t D) {
    qmath_value_t sqrtD = sqrtl(D);
    roots.x1 = (-factors.b + sqrtD) / (2 * factors.a);
    roots.x2 = (2 * factors.c) / (-factors.b - sqrtD);
}


/* Function declaration */

/* Fast but takes memory... */
qmath_roots_t qmath_solve(qmath_factors_t factors) {

    if (factors.c == 0.0L) {
        if (factors.b == 0.0L) {
            roots.x1 = 0;
            roots.x2 = NAN;
        } else {
            roots.x1 = 0;
            roots.x2 = -(factors.b / factors.a);
        }
    } else {
        if (factors.b == 0.0L) {
            qmath_value_t x12 = sqrtl(-(factors.c / factors.a));
            roots.x1 = x12;
            roots.x2 = -x12;
        } else {
            qmath_value_t D = discriminant(factors);
            
            if (factors.b < 0) {
                get_x12_neg(factors, D);
            } else {
                get_x12_pos(factors, D);
            }
        }
    }
    return roots;
}

