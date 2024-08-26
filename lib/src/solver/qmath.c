
#include <solver/qmath.h>
#include <config.h>

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
    ILE_LOG("[qmath.c](solve_complete_eq()): Discriminant = %Lf\n", D);
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
    ILE_LOG_STDOUT_INIT();
    qmath_roots_t result = {NAN, NAN};

    if (equation.c == 0.0L) {
        if (equation.b == 0.0L) {
            if (equation.a == 0.0L) {
                ILE_LOG("[qmath.c](qmath_solve): It has infinity roots.\n");
                result.x1 = INFINITY;
                // result.x2 = NAN;
            } else {
                ILE_LOG("[qmath.c](qmath_solve): It has one root.\n");
                result.x1 = 0.0L;
                // result.x2 = NAN;
            }
        } else {
            ILE_LOG("[qmath.c](qmath_solve): It has two roots.\n");
            result.x1 = 0.0L;
            result.x2 = -(equation.b / equation.a);
        }
    } else {
        if (equation.b == 0.0L) {
            ILE_LOG("[qmath.c](qmath_solve): It is linear equation.\n");
            solve_linear_eq(&result, equation);
        } else {
            ILE_LOG("[qmath.c](qmath_solve): It is complete equation.\n");
            solve_complete_eq(&result, equation);
        }
    }
    ILE_LOG("[qmath.c]: Roots = (%Lf, %Lf) \n", result.x1, result.x2);
    ILE_LOG_DEINIT();
    return result;
}

