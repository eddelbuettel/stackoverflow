
#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
double call_cond(arma::mat X) {
    double val = arma::cond(X);
    return val;
}

/*** R
load("bad_svd.RData")
call_cond(draw_cov)
*/
