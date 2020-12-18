// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>

// [[Rcpp::export]]
arma::vec testCpp(const int s, const int e, const int n) {
    arma::vec lambda = arma::exp2(arma::linspace(s, e, n));
    return lambda;
}

/*** R
testCpp(1,9, 9)
*/
