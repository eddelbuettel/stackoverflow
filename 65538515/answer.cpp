
#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::NumericMatrix makeMatrix(Rcpp::NumericVector a, Rcpp::NumericVector b) {
  return Rcpp::cbind(a, b);
}

/*** R
a <- c(1,2,3)
b <- c(3,2,1)
makeMatrix(a,b)
*/
