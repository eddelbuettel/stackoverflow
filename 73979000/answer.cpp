
#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::vec quantile_f(arma::vec V, arma::vec P) {
    return arma::quantile(V, P);
}

/*** R
set.seed(123)
quantile_f(rnorm(1000), c(0, 0.25, 0.5, 0.75, 1.0))
*/
