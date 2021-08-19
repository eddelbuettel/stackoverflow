
#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::NumericVector mypow(Rcpp::NumericVector x, double expo) {
    return Rcpp::pow(x, expo);
}

/*** R
v <- c(2,3,4)
mypow(v, 2)
mypow(v, 0.5)
*/
