
#include <RcppEigen.h>

using namespace Rcpp;

// [[Rcpp::depends(RcppEigen)]]


// 1) Non-pivoted QR decomposition:
// [[Rcpp::export]]
List HHqr(NumericMatrix AA) {
  using Eigen::Map;
  using Eigen::MatrixXd;
  using Eigen::HouseholderQR;
  const Map<MatrixXd> X(as<Map<MatrixXd> >(AA)); // mapping AA to X
  int m(X.rows());
  MatrixXd Q(m,m);
  MatrixXd R(X);
  HouseholderQR<MatrixXd> qr(X);
  Q = qr.householderQ();
  R = qr.matrixQR().triangularView<Eigen::Upper>();
  return List::create(Named("Q") = Q,
                      Named("R") = R);
}

//HHqr<-cxxfunction(signature(AA="matrix"),body=src,plugin = "RcppEigen")

// # 2) Column-pivoted QR decomposition:
// [[Rcpp::export]]
List CPHHqr(NumericMatrix AA) {
  using Eigen::Map;
  using Eigen::MatrixXd;
  using Eigen::ColPivHouseholderQR;
  const Map<MatrixXd> X(as<Map<MatrixXd> >(AA)); // mapping AA to X
  int m(X.rows());
  int n(X.cols());
  MatrixXd Q(m,m),P(n,n);
  MatrixXd R(X);
  ColPivHouseholderQR<MatrixXd> qr(X);
  P = qr.colsPermutation();
  Q = qr.householderQ();
  R = qr.matrixQR().triangularView<Eigen::Upper>();
  return List::create(Named("Q") = Q,
                      Named("R") = R,
                      Named("P") = P,
                      Named("Rank") = qr.rank());
}

//CPHHqr<-cxxfunction(signature(AA="matrix"),body=src,plugin = "RcppEigen")

//# 3) Full-pivoted QR decomposition:
// [[Rcpp::export]]
List FPHHqr(NumericMatrix AA) {
  using Eigen::Map;
  using Eigen::MatrixXd;
  using Eigen::FullPivHouseholderQR;
  const Map<MatrixXd> X(as<Map<MatrixXd> >(AA)); // mapping AA to X
  int m(X.rows());
  int n(X.cols());
  MatrixXd Q(m,m),P(n,n);
  MatrixXd R(X);
  FullPivHouseholderQR<MatrixXd> qr(X);
  P = qr.colsPermutation();
  Q = qr.matrixQ();
  R = qr.matrixQR().triangularView<Eigen::Upper>();
  return List::create(Named("Q") = Q,
                      Named("R") = R,
                      Named("P") = P,
                      Named("Rank") = qr.rank());
}
//FPHHqr<-cxxfunction(signature(AA="matrix"),body=src,plugin = "RcppEigen")

/*** R
library(fBasics)
X <- hilbert(500)   # test matrix
library(microbenchmark)
microbenchmark(HHqr(X),
               CPHHqr(X),
               FPHHqr(X))
*/
