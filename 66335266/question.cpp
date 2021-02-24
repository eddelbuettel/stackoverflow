// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>

//using namespace arma;

// [[Rcpp::export]]
double arma_abs(const double &x, const double &y, const double &z) {
  auto val = (x >= y) - z;
  Rcpp::Rcout << "val " << val << std::endl;
  Rcpp::Rcout << "int(val) " << int(val) << std::endl;
  return 2 * ::abs((x >= y) - z);
}

// [[Rcpp::export]]
double std_abs(const double &x, const double &y, const double &z) {
    return 2 * std::abs((x >= y) - z);
}

/*** R

r_abs <- function(x,y,z){
    2 * abs((x >= y) - z)
}

x <- 1
y <- 2
z <- 0.5

r_abs(x,y,z)           # 1
arma_abs(x, y, z)      # 0
std_abs(x, y, z)       # 1
*/
