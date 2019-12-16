
#include <RcppArmadillo.h>
#include <RcppArmadilloExtensions/sample.h>

// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;

// [[Rcpp::export]]
IntegerVector sample_matrix(NumericMatrix x, IntegerVector choice_set) {
  int n = x.nrow();
  IntegerVector result(n);
  for ( int i = 0; i < n; ++i ) {
    Rcpp::NumericVector z(x(i, _));
    result[i] = RcppArmadillo::sample(choice_set, 1, false, z)[0];
  }
  return result;
}
