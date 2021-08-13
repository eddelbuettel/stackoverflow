
#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
double mycorr(const arma::vec & x, const arma::vec & y) {
    return arma::as_scalar(arma::cor(x, y));
}

/*** R
set.seed(123)
x <- rnorm(100)
y <- rnorm(100)
cor(x,y)
mycorr(x,y)
*/
