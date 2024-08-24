
#ifndef LEXER_H_
#define LEXER_H_

/**************************************************************************//**
 * @file     lexer.h
 * @brief    Project L - Ile application. Solver. Lexer functions.
 * @version  V0.0.1
 * @date     22. Aug 2024
 * @author   Matvey Rybalkin
******************************************************************************/

/* Include enums and defines */
#include "lexer.enum.h"

/* Public functions */

typedef enum {
    ILE_LEXER_OK,
    ILE_LEXER_INVALID_CHARACTER,
    ILE_LEXER_INVALID_ID_NAME,
} ile_lexer_status_t;

/** 
 * @brief Recognize line of expression and returns buffer of tokens
 * 
 * @param[in] str string for recognition
 * @param[out] buffer recognized tokens buffer
 */
extern ile_lexer_status_t ile_token_get(char* str, ile_token_t** buffer);

#endif // LEXER_H_