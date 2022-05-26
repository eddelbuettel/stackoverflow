#include <Rcpp.h>

// [[Rcpp::export]]
double gammaStd(double x) { return (std::tgamma(x)); }

// [[Rcpp::export]]
Rcpp::NumericVector gamma_R(Rcpp::NumericVector x) { return (Rcpp::gamma(x)); }

/*** R
set.seed(123)
x <- max(0, rnorm(1, 50, 25))
res <- microbenchmark::microbenchmark(R = gamma(x), Cpp = gammaStd(x), Sugar = gamma_R(x) )
res
*/
