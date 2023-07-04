
#include <RcppEigen.h> // single header all you need

// need just for the Rcpp::sourceCpp() demo
// [[Rcpp::depends(RcppEigen)]]

// [[Rcpp::export]]
std::vector<double> pkgfun() {
    Eigen::ArrayXd r_beta = Eigen::ArrayXd::Random(4);
    auto r_beta_vec = std::vector<double>(r_beta.data(), r_beta.data()+4);
    return r_beta_vec;
}

// [[Rcpp::export]]
Eigen::ArrayXd pkgfun2() {
    return Eigen::ArrayXd::Random(4);
}

/*** R
pkgfun()
pkgfun2()
*/
