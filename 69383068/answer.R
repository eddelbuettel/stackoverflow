
fibR <- function(n) {
    if (n < 2)
        n
    else
        fibR(n - 1) + fibR(n - 2)
}

library(Rcpp)
Rcpp::cppFunction('int fibRcpp(int x) {
   if ((x < 2))
       return(x);
   else
       return(fibRcpp(x-1) + fibRcpp(x-2));
}')

library(rbenchmark)
benchmark(fibRcpp(30), fibR(30))[,1:3]
