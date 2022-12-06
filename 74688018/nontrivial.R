
Rcpp::sourceCpp("nontrivial.cpp")
N <- 1e7
stopifnot(nontrivial(N) == examplePackage::nontrivial(N))
rbenchmark::benchmark(inside = examplePackage::nontrivial(N),
                      outside = nontrivial(N),
                      replications = 100)[,1:4]
