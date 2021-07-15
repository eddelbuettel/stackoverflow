
// does not actually work

#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::mat mydot(const arma::mat & M, const arma::colvec & x) {
    arma::mat res = M % x;
    return res;
}

/*** R
A <- matrix(c(1,2,3,4,5,6), nrow=2)
b <- c(1,3)
show(A * b)
mydot(A, b)
*/
