
#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

// [[Rcpp::export]]
arma::colvec tailsum_arma(const arma::colvec &x){
    return arma::sum(x) + x - arma::cumsum(x);
}

Rcpp::NumericVector cumsum_self(const Rcpp::NumericVector &x){
    auto x_len = x.length();
    Rcpp::NumericVector y(x_len);
    y[0] = x[0];
    for (int i = 1;i < x_len; i++){
        y[i] = y[i - 1] + x[i];
    }
    return y;
}

// [[Rcpp::export]]
Rcpp::NumericVector tailsum_cpp(const Rcpp::NumericVector &x){
    //just to compare with tailsum_arma
    return sum(x) + x - cumsum_self(x);
}

// [[Rcpp::export]]
Rcpp::NumericVector tailsum_combo(const Rcpp::NumericVector &x){
    size_t x_len = x.length();
    double x_sum = Rcpp::sum(x);
    double csum = 0.0;
    Rcpp::NumericVector y(x_len);
    for (size_t i = 0; i < x_len; i++) {
        csum += x[i];
        y[i] = x_sum - csum + x[i];
    }
    return y;
}

/*** R

# But to my surprise, R code is more efficient than RcppArmadillo code:

tailsum_r <- function(x){
   sum(x) + x - cumsum(x)
}

x <- rnorm(1e6)
microbenchmark::microbenchmark(r = tailsum_r(x),
                               rcpp = tailsum_cpp(x),
                               arma = tailsum_arma(x),
                               combo = tailsum_combo(x),
                               times = 500)

*/
