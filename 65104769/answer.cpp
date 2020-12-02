// [[Rcpp::depends(RcppArmadillo)]]
#include "RcppArmadillo.h"

// [[Rcpp::export]]
bool array_norm (arma::cube & x) {
    auto out = x.each_slice([](arma::mat& x0) {return arma::norm(x0, "fro") ;}) ;
    out.print("out");
    return true;
}

/*** R
set.seed(2020)
x <- array(rnorm(3*4*5), 3:5)
array_norm2(x)
*/
