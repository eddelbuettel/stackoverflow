#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix testfun(NumericMatrix x) {
  NumericMatrix y(x.rows(), x.cols());
  y = x * 2;
  std::cout << x; // x is unmodified
  y = 2 * x;      // contrast with x * 2
  std::cout << x; // x is now modified
  return x;
}

/*** R
print(x <- matrix(2, nrow = 2, ncol = 2))
print(y <- testfun(x = x))
print(x)
*/
