
// small variation on snippet in tidyCpp package...

#include <tidyCpp>

// We use Rcpp here because it has cppFunction() and sourceCpp().
// We do not use any Rcpp headers.

// [[Rcpp::depends(tidyCpp)]]

// [[Rcpp::export]]
bool asLogical(SEXP x) {
    return R::asLogical(x);
}

/*** R
asLogical(TRUE)
asLogical(FALSE)
asLogical(42) # not zero so ...
*/
