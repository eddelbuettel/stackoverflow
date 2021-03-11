#include <R.h>
#include <Rinternals.h>  // for R_xlen_t

R_xlen_t minimal(SEXP x) {
    if (STRING_NO_NA(x))
        return 0;
    const R_xlen_t nx = Rf_xlength(x);
    for (R_xlen_t i = 0; i < nx; i++) {
        if (STRING_ELT(x, i) == NA_STRING)
            return i + 1;
    }
    return 0;
}
