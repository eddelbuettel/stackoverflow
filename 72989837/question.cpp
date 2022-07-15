#include <cmath>
#include <math.h>
#include <Rcpp.h>

// [[Rcpp::plugins("cpp17")]]
// [[Rcpp::export]]
double rcpp_hello_world(Rcpp::NumericVector x) {

  double z;
  z = std::cyl_bessel_i(0, x[0]);
  return z ;
}
