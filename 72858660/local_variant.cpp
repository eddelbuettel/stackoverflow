

#include <RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::uvec intersectVectors(const arma::vec& x, const arma::vec& y) {
    arma::vec a(x.size(), arma::fill::zeros);
    for (auto i:y) a = a + (x==i);
    return arma::find(a) + 1;
}

/*** R
x <- c(1,1,1,4,2,4,4)
vals <- c(1,4)
intersectVectors(x, vals)
*/
