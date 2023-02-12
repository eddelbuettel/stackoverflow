#include <RcppArmadillo.h>
#include <RcppEigen.h>

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::depends(RcppEigen)]]

// [[Rcpp::export]]
void fooArma(const arma::mat& m) {
    m.print("arma: matrix m");
}

// [[Rcpp::export]]
void fooEigen(const Eigen::MatrixXd& m) {
    Rcpp::Rcout << "eigen\n" << m << std::endl;
}

/*** R
m <- matrix(1:9,3,3) * 1.0
fooArma(m)
fooEigen(m)
*/
