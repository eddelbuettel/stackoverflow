#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::mat matrix2vector(arma::mat m, const bool byrow=false){
  if (byrow) {
    return m.as_row();
  } else {
    return m.as_col();
  }
}

/*** R
m <- matrix(1:15,5,3)
print(matrix2vector(m, byrow = TRUE))
print(matrix2vector(m, byrow = FALSE))
*/
