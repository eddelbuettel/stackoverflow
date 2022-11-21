#include <cmath>
#include <Rcpp.h>
#include <RcppEigen.h>
#include <stdio.h>
#include <R.h>
#include <Rmath.h>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <Eigen/OrderingMethods>
#include <Eigen/SparseCholesky>

using namespace Eigen;
using namespace Rcpp;
using namespace std;

// [[Rcpp::depends(RcppEigen)]]
//' Inverts matrices inside cpp
//' @param matrix Matrix to be inverted
//' @export
// [[Rcpp::export]]
MatrixXd cpp_sparse_solver(Eigen::MatrixXd<double> matrix){
  // START
  // Declaring objects
  int n = matrix.rows();
  MatrixXd I = Matrix<double, n, n>::Identity();
  matrix_s = matrix.sparseView();
  SimplicialLLT<Eigen::SparseMatrix<double>, Lower, NaturalOrdering<int>> solver;
  matrix_s.makeCompressed();
  solver.compute(matrix_s);
  MatrixXd Ainv = solver.solve(I);
  return Ainv;
}
