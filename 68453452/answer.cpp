
#include <RcppEigen.h>
//[[Rcpp::depends(RcppEigen)]]

// [[Rcpp::export]]
void showVec(Eigen::VectorXd A) {
    Rcpp::Rcout << A << std::endl;
}

// [[Rcpp::export]]
Eigen::VectorXd createVec() {
    Eigen::VectorXd v = { 1.1, 2.2, 3.3 };
    return v;
}

/*** R
v <- c(1.1, 2.2, 3.3)
showVec(v)
showVec(createVec())
*/
