
#include <RcppEigen.h>

// [[Rcpp::depends(RcppEigen)]]

// [[Rcpp::export]]
Eigen::MatrixXd cpp_hom_crit(const Eigen::Map<Eigen::MatrixXd> Q,
                             const Eigen::Map<Eigen::VectorXd> d,
                             const Eigen::Map<Eigen::MatrixXd> Qinv) {

    auto res = Q * d.asDiagonal() * Qinv;
    return res;
}

/*** R
v <- as.numeric(1:3)
M <- v %*% t(v)
Mi <- chol2inv(M)
cpp_hom_crit(M, v, Mi)
*/
