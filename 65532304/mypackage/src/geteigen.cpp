#include <RcppArmadillo.h>

// [[Rcpp::export]]
arma::vec getEigenValue(arma::mat M) {
  arma::vec eigval;
  arma::mat eigvec;

  eig_sym(eigval, eigvec, M);
  return eigval;
}
