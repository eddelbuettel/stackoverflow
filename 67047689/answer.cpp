#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector foo(int time_length, double BXadd,
                  NumericVector vn_complete, NumericVector vn1_complete) {

    // Empty vectors
    NumericVector BX (time_length);
    vn_complete = na_omit(vn_complete);
    vn1_complete = na_omit(vn1_complete);
    for(int t = 0; t < time_length; t++) {
        double a = vn_complete[t];
        double b = vn1_complete[t];
        BX[t] = BXadd * std::sqrt(std::min(a,b));
    }
    return BX;
}

// [[Rcpp::export]]
NumericVector foo2(double BXadd, NumericVector vn_complete, NumericVector vn1_complete) {
    return BXadd * sqrt(pmin(vn_complete, vn1_complete));
}

/*** R
foo(5, 2, 5:9, 1:5)
foo2(2, 5:9, 1:5)
*/
