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
std::vector<double> K_S(arma::mat mt) {
  int n = mt.n_cols;
  std::vector<double> res;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++){
      arma::colvec x=mt.col(i);
      arma::colvec y=mt.col(j);
      res.push_back(KS(x, y));
    }
  }
  return res;
}

/*** R
set.seed(1)
mt <- matrix(rnorm(400*5), ncol=5)
result <- K_S(mt)
result
*/
