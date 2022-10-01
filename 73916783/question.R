library(Rcpp)
sourceCpp(code='
// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>

double KS(arma::colvec x, arma::colvec y) {
  int n = x.n_rows;
  arma::colvec w = join_cols(x, y);
  arma::uvec z = arma::sort_index(w);
  w.fill(-1); w.elem( find(z <= n-1) ).ones();
  return max(abs(cumsum(w)))/n;
}
// [[Rcpp::export]]
Rcpp::NumericVector K_S(arma::mat mt) {
  int n = mt.n_cols;
  int m = 1;
  Rcpp::NumericVector results(n);
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++){
      arma::colvec x=mt.col(i);
      arma::colvec y=mt.col(j);
      results[m] = KS(x, y);
      m ++;
    }
  }
  return results;
}
')

set.seed(1)
mt <- matrix(rnorm(400*5), ncol=5)
result <- K_S(t(mt))
