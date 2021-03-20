
#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::NumericMatrix vec2mat(Rcpp::NumericVector vec, int n, int k) {
    Rcpp::NumericMatrix mat = Rcpp::no_init(n, k);
    for (auto i = 0; i < n * k; i++) mat[i] = vec[i];
    return mat;
}

// [[Rcpp::export]]
Rcpp::NumericMatrix vec2mat2(Rcpp::NumericVector s, int n, int k) {
    Rcpp::NumericMatrix mat(n, k, s.begin());
    return mat;
}

/*** R
v <- (1:9) * 1.0  # numeric
vec2mat(v, 3, 3)
vec2mat2(v, 3, 3)
*/
