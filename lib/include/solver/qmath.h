
#ifndef ILE_SHARE_LIBRARY_QMATH_H_
#define ILE_SHARE_LIBRARY_QMATH_H_

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

/// @brief Quadratic equation roots type.
typedef struct {
    qmath_value_t x1, x2;
} qmath_roots_t;

/// @brief Quadratic equation type.
typedef struct {
    qmath_value_t a, b, c;
} qmath_equation_t;

/**
 * @brief Solve quadratic equation.
 * 
 * If there are two roots, then two fields of the structure
 * contain values ​​different from `NAN`, if there is one root,
 * then only the first contains the correct value, if there are
 * no roots, then both `NAN` values ​​are returned.
 *
 * `equation` argument contains:
 *      `.a`, `.b`, `.c` fields of the equation in format:
 *      `ax^2 + bx + c = 0`
 * 
 * @param[out] equation quadratic equation struct.
 * @return Roots of the equation.
 */
extern qmath_roots_t qmath_solve(qmath_equation_t equation);

#endif // ILE_QMATH_H_