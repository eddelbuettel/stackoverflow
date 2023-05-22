#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;

// [[Rcpp::export]]
void test_svd(mat X) {
    mat U;
    vec s;
    mat V;
    Rprintf("Program starting \n");
    try {
        Rprintf("... attempting to find the svd with the dc method \n");
        svd(U, s, V, X, "dc");
    }
    catch (...) {
        Rprintf("... that failed. \n");
    }
}

/*** R
load("bad_svd.RData")
test_svd(draw_cov)
*/
