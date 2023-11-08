#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
List test_bug(int N) {

    Rcpp::IntegerVector inds(N);
    Rcpp::NumericVector vals(N);

    return List::create(inds, vals);
}

/*** R
for (k in 1:100) {
    if (k %% 10 == 0) print(k)
    test <- test_bug(1000000)
}
*/
