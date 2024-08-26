
#include <solver/qmath.h>

/*************************************************************
 * Private
 ************************************************************/

static qmath_value_t discriminant(qmath_equation_t equation) {
    return (equation.b * equation.b) - (4.0L * equation.a * equation.c);
}

static inline void solve_linear_eq(qmath_roots_t* roots, qmath_equation_t equation) {
    qmath_value_t x12 = sqrtl(-(equation.c / equation.a));
    roots->x1 = x12;
    roots->x2 = -x12;
}

static void solve_complete_eq(qmath_roots_t* roots, qmath_equation_t equation) {
    qmath_value_t D = discriminant(equation);
    
    if (D >= 0.0L) {
        qmath_value_t sqrtD = sqrtl(D);
        if (equation.b < 0.0L)
            sqrtD = - sqrtD;
        roots->x1 = (-equation.b + sqrtD) / (2.0L * equation.a);
        if (fabsl(D) < QMATH_EPSILON) {
            roots->x2 = NAN;
        } else {
            roots->x2 = (2.0L * equation.c) / (-equation.b + sqrtD);
        }
    }
}

/*************************************************************
 * Public
 ************************************************************/

qmath_roots_t qmath_solve(qmath_equation_t equation) {
    
    qmath_roots_t result = {NAN, NAN};

    if (equation.c == 0.0L) {
        if (equation.b == 0.0L) {
            result.x1 = 0.0L;
            // result.x2 = NAN;
        } else {
            result.x1 = 0.0L;
            result.x2 = -(equation.b / equation.a);
        }
    } else {
        if (equation.b == 0.0L) {
            if (equation.a == 0.0L) {
                result.x1 = INFINITY;
                // result.x2 = NAN;
            } else {
                solve_linear_eq(&result, equation);
            }
        } else {
            solve_complete_eq(&result, equation);
        }
    }
    return result;
}

