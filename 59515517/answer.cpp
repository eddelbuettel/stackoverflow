#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::mat testfun(arma::mat x) {
  arma::mat y(x.n_rows, x.n_cols);
  y = x * 2;
  std::cout << x; // x is unmodified
  y = 2 * x;      // contrast with x * 2
  std::cout << x; // x is now modified
  return x;
}

/*** R
print(x <- matrix(2, nrow = 2, ncol = 2))
print(y <- testfun(x = x))
print(x)
*/
