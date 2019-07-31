
#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::mat submatrix(arma::mat A, arma::uvec rowid, int k){
  for (arma::uword j = 0; j < A.n_rows; j++) {
    A.row(j) = arma::randu(A.n_rows).t();
  }
  return A;
}

/*** R
M <- matrix(1:16,4,4)
submatrix(M, 1, 1)
*/
