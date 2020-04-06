
// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>

using namespace Rcpp;

// [[Rcpp::export]]
NumericVector timesTwo(NumericVector x) {
  return x * 2;
}

// [[Rcpp::export]]
arma::vec check1(arma::vec x1, arma::vec x2, int rep){
  int n = x1.size();
  arma::vec y(n);
  y.fill(0);
  for(int i = 0; i < rep; i ++){
    y += x1 * arma::dot(x1, x2);
  }
  return y;
}

// [[Rcpp::export]]
arma::fvec check2(arma::fvec x1, arma::fvec x2, int rep){
  int n = x1.size();
  arma::fvec y(n);
  y.fill(0);
  for(int i = 0; i < rep; i ++){
    y += x1 * arma::dot(x1, x2);
  }
  return y;
}

// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically
// run after the compilation.
//

/*** R
timesTwo(42)
n = 100000
x1 = rnorm(n)
x2 = rnorm(n)
rep = 1000
system.time(y1 <- check1(x1, x2, rep))
system.time(y2 <- check2(x1, x2, rep))
head(y1)
head(y2)
*/
