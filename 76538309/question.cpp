#include <RcppArmadillo.h>
#include <RcppEigen.h>
using namespace Rcpp;

// [[Rcpp::export]]
Rcpp::NumericMatrix extractColumns(Rcpp::NumericMatrix A, Rcpp::IntegerVector indices) {
  int n = indices.size();
  int m = A.nrow();
  NumericMatrix B(m, n);
  for(int i = 0; i < n; i++) {
    B(_, i) = A(_, indices(i));
  }
  return B;
}

// [[Rcpp::export]]
NumericMatrix extractColumns1(NumericMatrix A, IntegerVector indices) {
  int n = indices.size();
  int m = A.nrow();
  NumericMatrix B(m, n);
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      B(i, j) = A(i, indices(j));
    }
  }
  return B;
}

// [[Rcpp::depends(RcppEigen)]]

// [[Rcpp::export]]
Eigen::MatrixXd extractColumns2(Eigen::MatrixXd A, Rcpp::IntegerVector indices) {
  int m = A.rows();
  int n = indices.size();
  Eigen::MatrixXd B(m, n);
  for(int i = 0; i < n; i++) {
    B.col(i) = A.col(indices(i));
  }
  return B;
}

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::mat extractColumns3(arma::mat A, arma::uvec v) {
    return A.cols(v);
}


/*** R
library(microbenchmark)
A <- matrix(rgamma(100000L, 5, 1), nrow = 2L, ncol = 50000L)
indices <- 2000L:40000L
microbenchmark(
  R         = A[, indices],
  RcppBasic = extractColumns(A, indices - 1L),
  RcppImprv = extractColumns1(A, indices - 1L),
  RcppEigen = extractColumns2(A, indices - 1L),
  RcppArma  = extractColumns3(A, indices - 1L),
  collapse  = collapse::ss(A, 1:2, indices),
  times = 25L
)

A <- matrix(rgamma(100000L, 5, 1), nrow = 200L, ncol = 500L)
indices <- 200L:400L
microbenchmark(
  R         = A[, indices],
  RcppBasic = extractColumns(A, indices - 1L),
  RcppImprv = extractColumns1(A, indices - 1L),
  RcppEigen = extractColumns2(A, indices - 1L),
  RcppArma  = extractColumns3(A, indices - 1L),
  collapse  = collapse::ss(A, 1:200, indices),
  times = 25L
)

all.equal(A[, indices], extractColumns(A, indices - 1L))
all.equal(A[, indices], extractColumns1(A, indices - 1L))
all.equal(A[, indices], extractColumns2(A, indices - 1L))
all.equal(A[, indices], extractColumns3(A, indices - 1L))
all.equal(A[, indices], collapse::ss(A, 1:200, indices))

*/
