/* Include specific libraries */
#include <solver.h>
#include "solver/qmath.h"

/*************************************************************
 * Public
 ************************************************************/

ILE_API qmath_roots_t ile_qe_solve(qmath_equation_t factors) {
    return qmath_solve(factors);
}