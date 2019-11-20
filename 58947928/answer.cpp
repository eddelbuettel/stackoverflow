#include <RcppArmadillo.h>      // also pulls in Rcpp.h amd cmath

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::vec polynomial_kernel(arma::vec x, arma::mat Y,
                            double scale = 1, double offset = 1, int d=1) {

  int n = Y.n_rows;
  arma::vec kernel(n);

  for (int j = 0; j < n; j++){
    arma::rowvec v = Y.row(j);
    double crossProd = arma::as_scalar(v * x);
    kernel[j] = std::pow((scale*crossProd+offset),2);
  }
  return kernel;
}
