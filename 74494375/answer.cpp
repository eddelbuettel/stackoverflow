#include <RcppEigen.h>

// [[Rcpp::depends(RcppEigen)]]
//' Inverts matrices inside cpp
//' @param matrix Matrix to be inverted
//' @export
// [[Rcpp::export]]
Eigen::MatrixXd cpp_sparse_solver(Eigen::MatrixXd matrix){
    int n = matrix.rows();
    Eigen::MatrixXd I = Eigen::MatrixXd::Identity(n,n);
    Eigen::SparseMatrix<double> matrix_s = matrix.sparseView();
    Eigen::SimplicialLLT<Eigen::SparseMatrix<double>, Eigen::Lower, Eigen::NaturalOrdering<int>> solver;
    matrix_s.makeCompressed();
    solver.compute(matrix_s);
    Eigen::MatrixXd Ainv = solver.solve(I);
    return Ainv;
}
