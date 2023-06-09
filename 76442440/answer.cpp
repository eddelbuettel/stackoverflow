
// [[Rcpp::depends(BH)]]
#include <boost/math/special_functions/beta.hpp>

// this also ensure linking with the GSL
// [[Rcpp::depends(RcppGSL)]]
#include <gsl/gsl_sf_gamma.h>

#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
NumericVector bfR(NumericVector a, NumericVector b) {
    int n = a.size();
    NumericVector rst(n);
    for (int i = 0; i<n; i++) {
        rst[i] = R::beta(a[i], b[i]);
    }
    return rst;
}

// [[Rcpp::export]]
NumericVector bfB(NumericVector a, NumericVector b) {
    int n = a.size();
    NumericVector rst(n);
    for (int i = 0; i<n; i++) {
        rst[i] = boost::math::beta( a[i], b[i] );
    }
    return rst;
}

// [[Rcpp::export]]
NumericVector bfG(NumericVector a, NumericVector b) {
    int n = a.size();
    NumericVector rst(n);
    for (int i = 0; i<n; i++) {
        rst[i] = gsl_sf_beta( a[i], b[i] );
    }
    return rst;
}


/*** R

set.seed(123)
N <- 300000L
a <- runif(N, 0, 10) # Generate a in (0, 10)
b <- runif(N, 0, 10) # Generate b in (0, 10)
summary(bfR(a,b) - bfB(a,b))
summary(bfR(a,b) - bfG(a,b))
microbenchmark::microbenchmark(R = bfR(a, b), Boost = bfB(a, b), GSL = bfG(a, b), times=10)

*/

// no different

// [[Rcpp::export]]
NumericVector bfRcpp(NumericVector a, NumericVector b) {
    return Rcpp::beta(a, b);
}
