library("Rcpp")
library("microbenchmark")

cppFunction("
     double gammacpp(double x) {
         return(std::tgamma(x));
     }
")

x <- max(0, rnorm(1, 50, 25))
microbenchmark(gamma(x), gammacpp(x))
