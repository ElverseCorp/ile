/* Include specific libraries */
#include <solver.h>
#include "solver/qmath.h"

/*************************************************************
 * Public
 ************************************************************/

ILE_API qmath_roots_t ile_qe_solve(qmath_equation_t factors) {
    long double result;
    ile_t_str_ldouble(&result, "123.123456789");
    return qmath_solve(factors);
}