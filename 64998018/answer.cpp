
#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::mat subsetOfMatrix(arma::mat X, arma::uvec v) {
  return X.cols(v);
}

/*** R
M <- matrix(1:16,4,4)
subsetOfMatrix(M, c(0L, 2L))
*/
