#include <Rcpp.h>
#include <RcppEigen.h>
#include <omp.h>
using namespace Rcpp;

// [[Rcpp::export]]
double eigen_det_cpp(const Eigen::Map<Eigen::MatrixXd> X, int n_cores) {
  Eigen::setNbThreads(n_cores);
  return X.determinant();
}
