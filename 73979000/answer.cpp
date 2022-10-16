// #define RCPP_ARMADILLO_RETURN_ANYVEC_AS_VECTOR
#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::vec quantile_f(arma::vec V, arma::vec P) {
    return arma::quantile(V, P);
}

// [[Rcpp::export]]
Rcpp::NumericVector quantile_f2(arma::vec V, arma::vec P) {
    arma::vec v = arma::quantile(V, P);
    Rcpp::NumericVector w = Rcpp::NumericVector(Rcpp::wrap(v));
    w.attr("dim") = static_cast<int>(v.n_elem);
    return w;
}

/*** R
set.seed(123)
quantile_f(rnorm(1000), c(0, 0.25, 0.5, 0.75, 1.0))
quantile_f2(rnorm(1000), c(0, 0.25, 0.5, 0.75, 1.0))
*/
