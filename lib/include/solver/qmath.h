
#ifndef ILE_QMATH_H_
#define ILE_QMATH_H_

/**************************************************************************//**
 * @file     lexer.h
 * @brief    Project L - Ile application. Solver. Math part of the app.
 * @version  V0.0.1
 * @date     24. Aug 2024
 * @author   Matvey Rybalkin
******************************************************************************/

/* PRIVATE HEADER */

/* Standard header files */
#include <stdint.h>
#include <float.h>
#include <math.h>

/* Public functiions and types */

/* Check long double type */
typedef long double qmath_value_t;

#define QMATH_EPSILON LDBL_EPSILON

/// @brief Type of solved quadratic equation.
typedef enum {
    ILE_QMATH_NO_ROOTS = 0,
    ILE_QMATH_1_ROOT = 1,
    ILE_QMATH_2_ROOTS = 2,
} qmath_num_roots_t;

/// @brief Quadratic equation 
typedef struct {
    qmath_value_t x1, x2;
} qmath_roots_t;

/// @brief Quadratic equation factors.
typedef struct {
    qmath_value_t a, b, c;
} qmath_factors_t;

/**
 * @brief Solve quadratic equation based on input attributes.
 * 
 * If there are two roots, then two fields of the structure
 * contain values ​​different from `NAN`, if there is one root,
 * then only the first contains the correct value, if there are
 * no roots, then both `NAN` values ​​are returned. If there are an
 * infinite number of roots, then both values ​​will be equal to `INF`.
 * 
 * @param[out] factors factors of the quadratic equation
 * @return structure of roots 
 */
extern qmath_roots_t qmath_solve(qmath_factors_t factors);

#endif // ILE_QMATH_H_