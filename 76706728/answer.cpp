
#include <RcppEigen.h>

// [[Rcpp::depends(RcppEigen)]]

// [[Rcpp::export]]
bool conv1(Rcpp::NumericVector X) {
    Eigen::Map<Eigen::VectorXd> XS(Rcpp::as<Eigen::Map<Eigen::VectorXd>>(X));
    return true;
}

// [[Rcpp::export]]
bool conv2(Rcpp::NumericVector X) {
    const int n = 4;
    if (X.size() != n) Rcpp::stop("Wrong size");
    Eigen::Matrix<double,4,1> m;
    std::memcpy(&m[0,0], &X[0], n*sizeof(double));
    Rcpp::Rcout << m << std::endl;
    return true;
}

/*** R
x <- as.numeric(1:4)
conv1(x)
conv2(x)
*/
