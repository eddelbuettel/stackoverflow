#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::mat hh(int n, int m) {
  arma::mat Z = arma::mat(n,m,arma::fill::randu);
  return Z;
}

/*** R
hh(2, 2)
*/
