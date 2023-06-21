
// we only include RcppArmadillo.h which pulls Rcpp.h in for us
#include "RcppArmadillo.h"

// [[Rcpp::export(rng=false)]]
arma::mat Xt(arma::mat x) {
    return x.t();
}
