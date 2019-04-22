#include <Rcpp.h>
#include <RcppEigen.h>

// [[Rcpp::depends(RcppEigen)]]

// [[Rcpp::export]]
Eigen::MatrixXd myfun(Eigen::Map<Eigen::MatrixXd> a,
                      Eigen::Map<Eigen::MatrixXd> b) {
  Eigen::MatrixXd res = a * b;
  return res;
}

/*** R
myfun(matrix(2,2,2), matrix(3,2,2))
myfun(matrix(as.numeric(1:4),2,2), matrix(as.numeric(4:1),2,2))
*/
