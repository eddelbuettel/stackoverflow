#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::ivec fun() {
  arma::ivec v(5, arma::fill::ones);

  for (int k=0; k<3; k++) {
    v = arma::cumsum(v);
  }

  return(v);
}

/*** R
fun()
*/
