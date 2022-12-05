
## -- we do not load the package to be more careful about the search path
##library(examplePackage)

#Rcpp::sourceCpp('src/example.cpp')
#exampleOutside <- function(mat, iters) {
#  example_cpp(mat, iters)
#}
## -- we source a _modified_ version and call it _directly_
Rcpp::sourceCpp("exampleOutside.cpp")

set.seed(42)
## -- do NOT call replicate, it is a loop
##    this may set you up for a lazy evaluation suprise
#mat <- replicate(n=1000, sample(1:10))
mat <- matrix(sample(1:10, 100, replace=TRUE), 10, 10)

## for(iters in c(1e4, 1e5, 1e6)) {
##   res <- microbenchmark::microbenchmark(
##     example(mat, iters),
##     exampleOutside(mat, iters),
##     times=10
##   )
##   print(iters)
##   print(res)
## }

rbenchmark::benchmark(inPkg = examplePackage::example_cpp(mat, 10),
                      outsidePkg = exampleOutside(mat, 10),
                      replications = 10, relative = TRUE)[,1:4]
