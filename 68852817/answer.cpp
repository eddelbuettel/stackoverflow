
#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::NumericVector mypow(Rcpp::NumericVector x, double expo) {
    return Rcpp::pow(x, expo);
}

/*** R
v <- c(2, 3, 4, 1.2e12, -1.2e12)
mypow(v, 2)
mypow(v, 0.5)
*/
