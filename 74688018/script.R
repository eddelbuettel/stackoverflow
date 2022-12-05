library(examplePackage)

Rcpp::sourceCpp('src/example.cpp')
exampleOutside <- function(mat, iters) {
  example_cpp(mat, iters)
}

set.seed(42)
mat <- replicate(n=1000, sample(1:10))

for(iters in c(1e4, 1e5, 1e6)) {
  res <- microbenchmark::microbenchmark(
    example(mat, iters),
    exampleOutside(mat, iters),
    times=10
  )
  print(iters)
  print(res)
}
