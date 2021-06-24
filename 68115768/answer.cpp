
#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]
using namespace arma;

// [[Rcpp::export]]
double getLL_Cpp(vec& b, const colvec& Y, const mat& X,
                 const mat& Z, const vec& beta, const mat& V, int mi){
    colvec resid = Y - X * beta - Z * b;
    return as_scalar(-mi/2.0 * log(2.0 * M_PI) -
                     0.5 * log(det(V)) - 0.5 * resid.t() * V.i() * resid);
}

/*** R
getLL_R <- function(Y, X, Z, V, b, beta, mi) {
    resid <- Y - X %*% beta - Z %*% b
    -mi/2 * log(2*pi) - 1/2 * log(det(V)) -
          1/2 * crossprod(resid, solve(V) %*% resid)
}

set.seed(100)
Y <- rnorm(8)
mi <- length(Y)
Z <- cbind(1, 0:7)
b <- rnorm(2)
X <- cbind(1, rnorm(8), rbinom(8, 1, 0.5))
beta <- c(10, 5, -2)
V <- diag(8)

getLL_R(Y, X, Z, V, b, beta, mi)
getLL_Cpp(b, Y, X, Z, beta, V, mi)
*/
