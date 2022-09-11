#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

#include <Ziggurat.h>
// [[Rcpp::depends(RcppZiggurat)]]

static Ziggurat::Ziggurat::Ziggurat zigg;

// [[Rcpp::export]]
arma::rowvec zzrnorm_ss(int n, unsigned long int set_seed) {
  zigg.setSeed(set_seed);
  arma::rowvec x(n);
  for (int i=0; i<n; i++) {
    x(i) = zigg.norm();
  }
  return x;
}

/*** R
RcppZiggurat::zsetseed(1)
v1 <- RcppZiggurat::zrnorm(3)
RcppZiggurat::zsetseed(1)
v2 <- RcppZiggurat::zrnorm(3)
v3 <- zzrnorm_ss(3, 1)
v4 <- zzrnorm_ss(3, 1)
rbind(v1, v2, v3, v4)
*/
