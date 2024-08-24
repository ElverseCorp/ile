/* Include specific libraries */
#include <solver.h>
#include "solver/qmath.h"

/* Public functions */

ILE_API qmath_roots_t ile_qe_solve(qmath_factors_t factors) {
    return qmath_solve(factors);
}