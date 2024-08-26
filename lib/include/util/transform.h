#ifndef ILE_SHARE_LIBRARY_UTIL_TRANSFORM_H_
#define ILE_SHARE_LIBRARY_UTIL_TRANSFORM_H_

/**************************************************************************//**
 * @file     solver.h
 * @brief    Project L - Ile application. Share library main.
 * @version  V0.0.1
 * @date     24. Aug 2024
 * @author   Matvey Rybalkin
******************************************************************************/

/* PRIVATE HEADER */

/**
 * @brief Transforms string to long double type.
 * 
 * This function is unsafe and requires not `NULL` args!
 * 
 * @param[out] dest number destination adress.
 * @param[in] str input string with the number.
 */
extern void ile_t_str_ldouble(long double* dest, const char* str);

#endif // ILE_SHARE_LIBRARY_UTIL_TRANSFORM_H_