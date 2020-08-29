
#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::vec foo(Rcpp::NumericVector x) {
  Rcpp::NumericVector y = Rcpp::qnorm(x, 0, 1, true, false);
  int n = y.size();
  arma::mat M(n,n);
  M.fill(1.0);                  // nonsense content, we don't care
  arma::vec v(y);               // instantiate Arma vec from Rcpp vec
  arma::vec res = M * v;
  return res;
}

/*** R
foo(c(0.95, 0.975))
*/
