
library(doParallel) 		# Library

ncores <- 5				    # Simulation parameters
n_sim <- 5
registerDoParallel(ncores)

Rcpp::sourceCpp(code='
  #include <Rcpp.h>

  // [[Rcpp::export]]
  int fibonacci(const int x) {
    if (x == 0) return(0);
    if (x == 1) return(1);
    return (fibonacci(x - 1)) + fibonacci(x - 2);
  }'
  )

cat("Fib(10) is ", fibonacci(10), "\n")
