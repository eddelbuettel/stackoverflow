#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::LogicalVector is_equal_c(Rcpp::IntegerVector x, Rcpp::IntegerVector y) {
  return x == y;
}

/*** R
library(microbenchmark)

set.seed(100)
x <- sample(0:1, 1000000, replace = TRUE)
y <- sample(0:1, 1000000, replace = TRUE)

is_equal_R <- function(x, y) {
  return(x==y)
}
mbm <- microbenchmark(c = is_equal_c(x,y),
                      R = is_equal_R(x,y))
mbm
*/
