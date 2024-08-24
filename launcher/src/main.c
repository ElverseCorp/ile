#include <solver.h>
#include <stdio.h>

int main() {
    qmath_value_t a = 4.0L, b = -20.0L, c = 25.0L;
    qmath_factors_t factors = {
        .a = a,
        .b = b,
        .c = c
    };
    qmath_roots_t roots = ile_qe_solve(factors);
    printf("%Lf %Lf", roots.x1, roots.x2);
    return 0;
}