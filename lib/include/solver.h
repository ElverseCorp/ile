
#ifndef ILE_SOLVER_H_
#define ILE_SOLVER_H_

/**************************************************************************//**
 * @file     solver.h
 * @brief    Project L - Ile application. Solver main header.
 * @version  V0.0.1
 * @date     24. Aug 2024
 * @author   Matvey Rybalkin
******************************************************************************/

/* PUBLIC HEADER */

/* Check C standard */
#if __STDC_VERSION__ >= 201112L 

/* Types */

/// @brief Ile library solution formatted text.
typedef unsigned char* ile_text_t;

/* Functions */

/**
 * @brief Solve quardratic equation and returns formatted text.
 * 
 *  Text can be used as step-by-step explanation of the solution.
 * 
 * @param[in] text text of the quadratic equation
 * @returns pointer of the formatted text solution
 */
extern ILE_API ile_text_t ile_qe_solve(ile_text_t text);


#else 
#error "[Ile][lib]: Solver libraries require at least C 2011 standard"
#endif

#endif // ILE_SOLVER_H_