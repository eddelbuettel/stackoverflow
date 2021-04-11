#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]


// [[Rcpp::export]]
arma::mat Generate(int n=5, int k=6){
    arma::mat m = arma::ones<arma::mat>(n,k);
    return m;
}

/*** R
Generate()
*/
