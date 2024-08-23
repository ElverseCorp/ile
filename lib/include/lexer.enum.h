
#ifndef LEXER_ENUM_H_
#define LEXER_ENUM_H_

/**************************************************************************//**
 * @file     lexer.enum.h
 * @brief    Project L - Ile application. Solver. Lexer enums.
 * @version  V0.0.1
 * @date     22. Aug 2024
 * @author   Matvey Rybalkin
******************************************************************************/

/* Tokens */

typedef enum {

    /* Operators */
    ILE_TOKEN_EQ,        // =
    ILE_TOKEN_PLUS,      // +
    ILE_TOKEN_MINUS,     // -
    ILE_TOKEN_MUL,       // *
    ILE_TOKEN_DIV,       // /
    ILE_TOKEN_COLON,     // :

    /* Numbers */
    ILE_TOKEN_FACTOR,   // kx^a <- contains only k value
    ILE_TOKEN_POWER,    // kx^a <- contains only a value

    ILE_TOKEN_INVALID = 0xFF, // for errors 
} ile_token_type_t;


/* Types */

/// @brief  Token type
typedef struct {
    ile_token_type_t type;  // type of token
    char* value;            // value
} ile_token_t;

#define ILE_INIT_TOKEN() {ILE_TOKEN_INVALID, NULL}

/// @brief Symbol table identifier
typedef char* ile_st_id_t;

#endif // LEXER_ENUM_H_