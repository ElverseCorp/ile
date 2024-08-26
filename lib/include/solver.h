
#ifndef ILE_SHARE_LIBRARY_SOLVER_H_
#define ILE_SHARE_LIBRARY_SOLVER_H_

/**************************************************************************//**
 * @file     solver.h
 * @brief    Project L - Ile application. Share library main header.
 * @version  V0.0.1
 * @date     24. Aug 2024
 * @author   Matvey Rybalkin
******************************************************************************/

/* PUBLIC HEADER */

/* Check C standard */
#if __STDC_VERSION__ >= 201112L 

// For DLL
#ifdef WIN32
#define ILE_API __declspec(dllexport)
#endif


/// @brief Ile library solution formatted text. (UTF-8 encode)
typedef unsigned char* ile_text_t;


#include "solver/qmath.h"

/**
 * @brief Solve quardratic equation and returns formatted text.
 * 
 *  Text can be used as step-by-step explanation of the solution.
 * 
 * @param[in] text text of the quadratic equation
 * @returns pointer of the formatted text solution
 */
extern ILE_API qmath_roots_t ile_qe_solve(qmath_equation_t factors);

#else 
#error "[Ile][lib]: Solver libraries require at least C 2011 standard"
#endif

#endif // ILE_SHARE_LIBRARY_SOLVER_H_