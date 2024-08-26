#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include <util/transform.h>
#include <config.h>

/*************************************************************
 * Public
 ************************************************************/


void ile_t_str_ldouble(long double* dest, const char* str) {
    ILE_LOG_STDOUT_INIT();
    ILE_LOG("Begin converting...");
    size_t i_int = 0, i_fract = 0;
    size_t* i_current = &i_int;
    size_t i = 0;

    (*dest) = 0.0L;

    /* Lex */
    do {
        if (str[i] == '.') {
            i_current = &i_fract;
            ++i;
        }
        ++(*i_current); ++i;
    } while(str[i] != '\0');

    /* Fill */
    i = 0;
    while (i_int) {
        ILE_LOG("INT[%lld] =  %Lf\n", i, (str[i] - '0') * powl(10, i_int));
        (*dest) += (str[i] - '0') * powl(10, i_int);
        ILE_LOG("Current ans: %Lf\n", (*dest));
        --i_int; ++i;
    }
    if (i_fract) {
        i += i_fract;
        // i_fract = num of fracts, i = index
        while (i_fract) {
            ILE_LOG("FRACT[%lld] =  %Lf\n", i, (str[i] - '0') * powl(0.1, i_fract));
            (*dest) += (str[i] - '0') * powl(0.1, i_fract);
            ILE_LOG("Current ans: %Lf\n", (*dest));
            --i_fract; --i;
        }
    }
    ILE_LOG("ANS = %Lf\n", (*dest));
}