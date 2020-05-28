#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector triple_balance(const NumericVector & balance) {
    return balance * 3;
}

// [[Rcpp::export]]
double triple_balance_orig(const double& balance) {

  if(R_IsNA(balance)) {
    stop("balance is NA, please provide a numeric value");
  } else {
     double result = balance*3;
    return result;
  }
}
