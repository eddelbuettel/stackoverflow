
library(Rcpp)
cppFunction("std::string cc(std::string a, std::string b) { return a+b; }")
`%+%` <- function(a,b) cc(a,b)

cc("Hello", "World")

"hello" %+% "world"


`%op%` <- cppFunction("Eigen::MatrixXd op(Eigen::VectorXd x, Eigen::VectorXd y) { Eigen::MatrixXd op = x * y.transpose(); return op; }", depends="RcppEigen")

as.numeric(1:3) %op% as.numeric(3:1)

library(Rcpp)
cppFunction("arma::mat op(arma::colvec x, arma::colvec y) { arma::mat op = x * y.t(); return op; }", depends="RcppArmadillo")
