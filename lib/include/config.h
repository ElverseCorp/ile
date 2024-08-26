
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
#   define ILE_LOG(...) fprintf(stdout, __VA_ARGS__)
#   define ILE_LOG_FILE(file, ...) fprintf(file, __VA_ARGS__)
#   define ILE_LOG_FILE_INIT
#   define ILE_LOG_FILE_DEINIT
#   define ILE_ASSERT(condition, ...)) if (condition) { fprintf(stdout, __VA_ARGS__); exit(1); }

#else 
#   define ILE_LOG(message, ...)
#   define ILE_ASSERT(condition, log)
#   define ILE_LOG_FILE(file, message, ...) fprintf(file, message, __VA_ARGS__)
#endif

#endif // ILE_SHARE_LIBRARY_CONFIG_H_