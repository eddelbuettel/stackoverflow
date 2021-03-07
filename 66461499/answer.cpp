#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::vec SimulBetaBin(int K, arma::vec N) {
  arma::vec D;
  Rcpp::Environment pkg = Rcpp::Environment::namespace_env("extraDistr");
  Rcpp::Function f = pkg["rbbinom"];

  for (int i=0; i<K; ++i) {
    SEXP val = f(1, N[i],  1,  1);
    D[i] = Rcpp::as<double>(val);
  }

  return  D;
}
