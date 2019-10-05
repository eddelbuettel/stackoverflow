#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
void incRow(arma::mat& M) {
  M.row(0) = M.row(0) + 1;
}

// [[Rcpp::export]]
void incRow2(Rcpp::NumericMatrix M) {
  M(0,Rcpp::_) = M(0,Rcpp::_) + 1;
}


/*** R
A <- diag(c(1.0, 2.0, 3.0))
incRow(A)
A
incRow2(A)
A
*/
