library(parallelDist)
library(RcppArmadillo)
library(RcppXPtrUtils)

euclideanFuncPtr <- cppXPtr("double customDist(const arma::mat &A, const arma::mat &B) {return sqrt(arma::accu(arma::square(A - B))); }",depends = c("RcppArmadillo"))

# distance matrix for user-defined euclidean distance function
# (note that method is set to "custom")
x <- matrix(1:16,ncol=2)
parDist(x, method="custom", func = euclideanFuncPtr)

overlap <- cppXPtr("double customDist(const arma::mat &A, const arma::mat &B) {  arma::accu(pmin(A,B)) / arma::accu(pmax(A,B)); }",depends = c("RcppArmadillo"))
