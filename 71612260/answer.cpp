// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>
using namespace Rcpp;

// [[Rcpp::export]]
arma::mat f(){
    arma::mat x = arma::randn(3, 4) ;
    List y = List::create( ::Named("a") = arma::randn(3, 4) ) ;

    return x - Rcpp::as<arma::mat>(y["a"]);
}

/*** R
set.seed(42) # reproducible RNG draws
f()
*/
