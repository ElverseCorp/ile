
#ifndef ILE_SHARE_LIBRARY_CONFIG_H_
#define ILE_SHARE_LIBRARY_CONFIG_H_

/**************************************************************************//**
 * @file     config.h
 * @brief    Project L - Ile application. Solver main header.
 * @version  V0.0.1
 * @date     24. Aug 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#ifdef DEBUG

#   include <stdio.h>
#   include <stdlib.h>

    /* ---------- LOGS ---------- */

// Files
    extern FILE* _ile_log_file;
#   define ILE_LOG_STDOUT_INIT() _ile_log_file = stdout
#   define ILE_LOG_FILE_INIT(filename) _ile_log_file = fopen(filename, "w")
#   define ILE_LOG_DEINIT() if (_ile_log_file != stdout) { fclose(_ile_log_file); }

#   define ILE_LOG(...) fprintf(_ile_log_file, __VA_ARGS__)

    /* ---------- ASSERTS ---------- */

#   define ILE_ASSERT(condition, ...)) if (condition) { fprintf(stdout, __VA_ARGS__); exit(1); }

#else 
#   define ILE_LOG(...)
#   define ILE_LOG_FILE_INIT()
#   define ILE_LOG_FILE_DEINIT()
#   define ILE_LOG_FILE(file, ...)
#   define ILE_ASSERT(condition, ...)
#endif

#endif // ILE_SHARE_LIBRARY_CONFIG_H_