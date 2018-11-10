
// [[Rcpp::depends(RcppArmadillo)]]

#include <RcppArmadillo.h>

// [[Rcpp::export]]
double pij_cpp(const arma::vec & v) {
  arma::mat m = v * v.t();
  m.diag().zeros();
  double s = arma::as_scalar(arma::accu(m));
  return(s);
}

/*** R
library(rbenchmark)
set.seed(123)

pij <- function(vec){
  out <- vec %*% t(vec)
  diag(out) <- NA
  out <- sum(out, na.rm = T)
}
  
x <- rnorm(1000)

## make sure they are the same
all.equal(pij(x), pij_cpp(x))

## benchmark
benchmark(R=pij(x), Cpp=pij_cpp(x))
*/
