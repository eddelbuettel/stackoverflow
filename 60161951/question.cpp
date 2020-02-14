#include <Rcpp.h>

// [[Rcpp::export]]
int foo1(Rcpp::IntegerVector res) {
  int output = res[0];
  return output;
}


// [[Rcpp::export]]
int foo(Rcpp::IntegerMatrix res) {
  int n = res.nrow();
  int output = 0;               // need to init

  for (int r = 0; r < n; r++) {
    Rcpp::IntegerVector temp_res = res( r, Rcpp::_);
    output = output + temp_res[0];
  }
  return output;
}

/*** R
M <- matrix(seq(1,9), 3, 3)
foo(M)
*/
