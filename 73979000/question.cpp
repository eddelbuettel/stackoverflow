#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace Rcpp;
using namespace arma;


// quantile function
// [[Rcpp::export]]
vec quantile_f(vec V, vec P) {
  vec Q = quantile(V, P);
  NumericVector Q_output = as<NumericVector>(wrap(Q));
  return (Q_output);
}

/*** R
set.seed(123)
quantile_f(rnorm(1000), c(0, 0.25, 0.5, 0.75, 1.0))
*/
