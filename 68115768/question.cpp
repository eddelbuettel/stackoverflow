
#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]
using namespace Rcpp;
using namespace arma;
// [[Rcpp::export]]
double getLongit(vec& b, const colvec& Y, const mat& X, const mat& Z, const vec& beta, const mat& V, int mi){
    colvec resid = Y - X * beta - Z * b;
    // Rcpp::Rcout << "resid: " << resid << std::endl;
    // Rcpp::Rcout << "RTVR: " << resid.t() * V.i() * resid << std::endl;
    return as_scalar(-mi/2 * log(2 * M_PI) - 1/2 * log(det(V)) -1/2 * resid.t() * V.i() * resid);
}

/*** R
RgetLL <- function(Y, X, Z, V, b, beta, mi) {
  -mi/2 * log(2*pi) - 1/2 * log(det(V)) - 1/2 * crossprod(Y - X %*% beta - Z %*% b, solve(V) %*% (Y - X %*% beta - Z %*% b))
}

set.seed(100)
Y <- rnorm(8)
mi <- length(Y)
Z <- cbind(1, 0:7)
b <- rnorm(2)
X <- cbind(1, rnorm(8), rbinom(8, 1, 0.5))
beta <- c(10, 5, -2)
V <- diag(8)

RgetLL(Y, X, Z, V, b, beta, mi)
getLongit(b, Y, X, Z, beta, V, mi)
*/
