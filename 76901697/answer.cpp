
#include <Rcpp/Rcpp>

// [[Rcpp::export]]
Rcpp::NumericVector myrep(Rcpp::NumericVector x, int n) {
    return Rcpp::rep(x, n);
}

/*** R
x <- c(1, 2, 3, 4)
n <- 3
myrep(x, n)
*/
