#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
double meanC(NumericVector x) {
  int n = x.size();
  double total = 0;

  for(int i = 0; i < n; ++i) {
    total += x[i];
  }
  return total / n;
}

// [[Rcpp::export]]
double meanS(const Rcpp::NumericVector& x) {
  return Rcpp::mean(x);
}

/*** R
library(microbenchmark)
x <- runif(5e5)
microbenchmark(mean(x), meanC(x), meanS(x)
)
*/
