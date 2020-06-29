#include<Rcpp.h>

inline int randWrapper(const int n) { return floor(unif_rand()*n); }

// [[Rcpp::export]]
Rcpp::NumericVector randomShuffle(Rcpp::NumericVector a) {

    // clone a into b to leave a alone
    Rcpp::NumericVector b = Rcpp::clone(a);

    std::random_shuffle(b.begin(), b.end(), randWrapper);

    return b;
}

/*** R
a <- 1:8
set.seed(42)
randomShuffle(a)
*/
