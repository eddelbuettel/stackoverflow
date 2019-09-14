#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;

// [[Rcpp::export]]
arma::mat mvrnormArma(int n, arma::vec mu, arma::mat sigma) {
   int ncols = sigma.n_cols;
   arma::mat Y = arma::randn(n, ncols);
   return arma::repmat(mu, 1, n).t() + Y * arma::chol(sigma);
}

/*** R
#mvrnormArma(n = 10000, mu = c(0, 0), Sigma = matrix(c(1,0,0,1), 2, 2))
set.seed(123)  # make it reproducible
mvrnormArma(n = 10, mu = c(0, 0), sigma = matrix(c(1,0,0,1), 2, 2))
*/
