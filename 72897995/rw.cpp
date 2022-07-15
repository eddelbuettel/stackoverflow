
#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::IntegerVector rwCpp(int n = 10000) {
    Rcpp::IntegerMatrix steps(n, 2); // zero filled

    Rcpp::IntegerVector s = Rcpp::sample(4, n, true);

    for (int i=0; i<n; i++) {
        if (s[i] == 1) {
            steps(i, 0) = 1;
        } else if (s[i] == 2) {
            steps(i, 0) = -1;
        } else if (s[i] == 3) {
            steps(i, 1) = 1;
        } else {
            steps(i, 1) = -1;
        }
    }

    return(Rcpp::colSums(steps));
}
